#include "serialportmanager.h"

//!
//! \brief SerialPortManager::SerialPortManager
//!
SerialPortManager::SerialPortManager(QObject *parent) : QObject(parent) {
  mSerialPort.setBaudRate(QSerialPort::Baud115200);
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
  if (mSerialPort.isOpen()) {
    mSerialPort.close();
  }

  mSerialPort.setPortName(mCurrentPort);

  if (!mSerialPort.open(QIODevice::ReadWrite)) {
    qDebug() << mSerialPort.errorString();
  }
}

//!
//! \brief SerialPortManager::write
//! \param message
//!
void SerialPortManager::write(QByteArray message) {
  // mSerialPort.write(message);
}

//!
//! \brief SerialPortManager::read
//!
void SerialPortManager::read() {
  if (mSerialPort.isOpen()) {
    mSerialPort.write("t");
    mSerialPort.waitForBytesWritten();
    mSerialPort.waitForReadyRead();
    QString data = mSerialPort.readLine();
    if (data.contains("\n")) {
      emit temp(data);
    } else {
      read();
    }
  } else {
    qDebug() << "port is not open.";
  }
}

void SerialPortManager::send(QByteArray message) {
  mSerialPort.write(message);
  mSerialPort.waitForBytesWritten();
  mSerialPort.waitForReadyRead();
  QByteArray data = mSerialPort.readLine();
  qDebug() << data;
}
