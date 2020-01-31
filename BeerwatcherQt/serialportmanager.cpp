#include "serialportmanager.h"

//!
//! \brief SerialPortManager::SerialPortManager
//!
SerialPortManager::SerialPortManager(QObject *parent) : QObject(parent) {

  mSerialPort = new QSerialPort();
  mSerialPort->setBaudRate(QSerialPort::Baud115200);

  connect(mSerialPort, &QSerialPort::readyRead, this,
          &SerialPortManager::handleReadyRead);
  connect(mSerialPort, &QSerialPort::errorOccurred, this,
          &SerialPortManager::handleError);
  connect(&mTimer, &QTimer::timeout, this, &SerialPortManager::handleTimeout);
  mTimer.start();
}

//!
//! \brief SerialPortManager::availablePorts
//! \return
//!
QVariant SerialPortManager::availablePorts() {
  QList<QSerialPortInfo> portsAvailable = QSerialPortInfo::availablePorts();
  QStringList portsAvailableNames;
  for (const QSerialPortInfo &portInfo : portsAvailable) {
    portsAvailableNames << portInfo.portName();
  }
  return QVariant::fromValue(portsAvailableNames);
};

//!
//! \brief SerialPortManager::getVendor
//! \param tty
//! \return
//!
QString SerialPortManager::getVendor(QString tty) {
  return QString::number(QSerialPortInfo(tty).vendorIdentifier());
};

//!
//! \brief SerialPortManager::getManufacturer
//! \param tty
//! \return
//!
QString SerialPortManager::getManufacturer(QString tty) {
  return QSerialPortInfo(tty).manufacturer();
};

//!
//! \brief SerialPortManager::getSerialNumber
//! \param tty
//! \return
//!
QString SerialPortManager::getSerialNumber(QString tty) {
  return QSerialPortInfo(tty).serialNumber();
};

//!
//! \brief SerialPortManager::getProductIdentifier
//! \param tty
//! \return
//!
QString SerialPortManager::getProductIdentifier(QString tty) {
  return QString::number(QSerialPortInfo(tty).productIdentifier(), 16);
};

//!
//! \brief SerialPortManager::setCurrentPort
//! \param tty
//!
void SerialPortManager::setCurrentPort(QString tty) {
  mCurrentPort = tty;

  // Close if open, needed?
  if (mSerialPort->isOpen()) {
    mSerialPort->close();
  }

  mSerialPort->setPortName(mCurrentPort);

  if (mSerialPort->open(QIODevice::ReadWrite)) {
    qDebug() << mSerialPort->isOpen();
  } else {
    qDebug() << mSerialPort->errorString();
  }
}

//!
//! \brief SerialPortManager::write
//! \param message
//!
void SerialPortManager::write(QByteArray message) {
  mSerialPort->write(message);
  mSerialPort->waitForBytesWritten();
  qDebug() << "Sent: " << message << " to arduino";
}

//!
//! \brief SerialPortManager::read
//!
void SerialPortManager::read() {
  while (mSerialPort->canReadLine() > 0) {
    mReadData.append(mSerialPort->readLine());
    qDebug() << "data: " << mReadData;

    // check if data contains \r\n
    if (mReadData.contains("\r\n")) {
      int bytes = mReadData.indexOf("\r\n") + 2;
      QString message = mReadData.left(bytes);
      // qDebug() << "message: " << message;
      // should not be data left? can not be data left?
      mReadData = mReadData.mid(bytes);
      handleMessage(message);
    }
  }
}

void SerialPortManager::handleMessage(QString message) {
  QList<QString> msg = message.split(':');
  if (msg[0] == "temp") {
    qDebug() << "temp: " << msg[1].simplified();
    emit temp(msg[1].simplified().toFloat());
  } else if (msg[0] == "vibrations") {
    qDebug() << "vibrations: " << msg[1].simplified();
    emit vibrations(msg[1].simplified().toInt());
  } else {
    // unknown message;
  }
}

void SerialPortManager::handleReadyRead() {
  if (mSerialPort->canReadLine()) {
    read();
    if (!mTimer.isActive()) {
      mTimer.start(5000);
    }
  }
}

//!
//! \brief SerialPortManager::handleTimeout
//! Why here? does it always timeout when complete?
void SerialPortManager::handleTimeout() {
  if (!mReadData.isEmpty()) {
    mReadData.clear();
  }
}

void SerialPortManager::handleError(QSerialPort::SerialPortError error) {
  if (error == QSerialPort::ReadError) {
    qDebug() << QObject::tr("An I/O error occurred while reading "
                            "the data from port %1, error: %2")
                    .arg(mSerialPort->portName())
                    .arg(mSerialPort->errorString())
             << endl;
  }
}
