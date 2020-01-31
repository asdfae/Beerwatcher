#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H

#include <QDebug>
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QVariant>

class SerialPortManager : public QObject {
  Q_OBJECT
public:
  explicit SerialPortManager(QObject *parent = nullptr);

  Q_INVOKABLE static QVariant availablePorts();
  Q_INVOKABLE static QString getVendor(QString tty);
  Q_INVOKABLE static QString getManufacturer(QString tty);
  Q_INVOKABLE static QString getProductIdentifier(QString tty);
  Q_INVOKABLE static QString getSerialNumber(QString tty);

  Q_INVOKABLE void setCurrentPort(QString tty);
  Q_INVOKABLE void write(QByteArray message);
  Q_INVOKABLE void read();
  Q_INVOKABLE void send(QByteArray message);

signals:
  void temp(QString data);

private:
  QString mCurrentPort;
  QSerialPort mSerialPort;
  QTextStream mStandardOutput;
  QTimer mTimer;
};

#endif // SERIALPORTMANAGER_H
