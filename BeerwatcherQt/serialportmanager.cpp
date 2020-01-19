#include "serialportmanager.h"

//!
//! \brief SerialPortManager::SerialPortManager
//!
SerialPortManager::SerialPortManager() {}

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
  mSerialPort.write(message);
}

void SerialPortManager::read() {
  QByteArray data = mSerialPort.readAll();
  qDebug() << data;
}
