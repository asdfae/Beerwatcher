#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QDateTime>
#include <QDebug>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class DBConnection : public QObject {
  Q_OBJECT
public:
  explicit DBConnection(QObject *parent = nullptr);
  enum DataPointTypes { TEMPERATURE, VIBRATIONS };

public slots:
  void connect();

private:
  QSqlDatabase mDb;
};

#endif // DBCONNECTION_H
