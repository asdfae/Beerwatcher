#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H

#include <QDebug>
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QVariant>

class SerialPortManager : public QObject {
  Q_OBJECT
public:
  SerialPortManager();
  Q_INVOKABLE static QVariant availablePorts();
  Q_INVOKABLE static QString getVendor(QString tty);
  Q_INVOKABLE static QString getManufacturer(QString tty);
  Q_INVOKABLE static QString getProductIdentifier(QString tty);
  Q_INVOKABLE static QString getSerialNumber(QString tty);

  Q_INVOKABLE void setCurrentPort(QString tty);
  Q_INVOKABLE void write(QByteArray message);

public slots:
  void readData();

private:
  QString mCurrentPort;
  QSerialPort mSerialPort;
};

#endif // SERIALPORTMANAGER_H
