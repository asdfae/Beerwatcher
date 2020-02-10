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

signals:
  void temp(float data);
  void vibrations(int data);

private slots:
  void handleReadyRead();
  void handleTimeout();
  void handleError(QSerialPort::SerialPortError error);

private:
  void read();
  void handleMessage(QString message);

  QString mCurrentPort;
  QSerialPort *mSerialPort = nullptr;
  QByteArray mReadData;
  // QTextStream mStandardOutput();
  QTimer mTimer;
};

#endif // SERIALPORTMANAGER_H
