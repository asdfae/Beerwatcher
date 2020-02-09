#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QDebug>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class DBConnection : public QObject {
  Q_OBJECT
public:
  explicit DBConnection(QObject *parent = nullptr);

public slots:
  void connect();
};

#endif // DBCONNECTION_H
