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
  qDebug() << "using: " << tty;
  mCurrentPort = tty;
  mSerialPort.setPortName(mCurrentPort);
}

//!
//! \brief SerialPortManager::write
//! \param message
//!
void SerialPortManager::write(QByteArray message) {
  qDebug() << "Writing: " << message;
  if (mSerialPort.open(QIODevice::ReadWrite))
    mSerialPort.write(message);
  else {
    // error
    qDebug() << mSerialPort.errorString();
  }
}

void SerialPortManager::readData() {
  QByteArray data = mSerialPort.readAll();

  qDebug() << data;
}
