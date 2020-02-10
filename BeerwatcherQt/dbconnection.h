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
  Q_ENUMS(DataPointTypes);

public:
  explicit DBConnection(QObject *parent = nullptr);
  enum DataPointTypes { TEMPERATURE, VIBRATIONS };

  Q_INVOKABLE void addDataPoint(QVariant value, int type);
  Q_INVOKABLE void createNewSession();
  Q_INVOKABLE void resumeSession();

private:
  QSqlDatabase mDb;
  int mActiveSession = -1;
};

#endif // DBCONNECTION_H
