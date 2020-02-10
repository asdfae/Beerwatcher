#include "dbconnection.h"

//!
//! \brief DBConnection::DBConnection
//! \param parent
//!
DBConnection::DBConnection(QObject *parent) : QObject(parent) {
  QString databaseName = "beerwatch";
  QString databaseUsername = "beerwatch";
  QString databasePassword = "'beerwatch'";

  mDb = QSqlDatabase::addDatabase("QPSQL");
  mDb.setHostName("localhost");
  mDb.setDatabaseName("beerwatch");
  mDb.setUserName("beerwatch");
  mDb.setPassword("beerwatch");

  // Check if ok, else assume dabase is not create, so we create it and add our
  // beerwatch user.
  if (!mDb.open()) {
    qDebug() << "Unable to connect to database, checking if we can create it";
    mDb.setUserName("postgres");
    mDb.setPassword("");
    mDb.setDatabaseName("");
    if (!mDb.open()) {
      qDebug() << "Unable to connect to postgres. is server running?";
    } else {

      // Create database
      qDebug() << "Connected as postgres, creating database.";
      QSqlQuery query(mDb);
      if (query.exec("CREATE DATABASE " + databaseName)) {
        qDebug() << "Successfully created database: " << databaseName;
      } else {
        qDebug() << "unable to create database with name: " + databaseName
                 << " - " << query.lastError().text();
      }

      // Create user
      query.clear();
      if (query.exec("CREATE USER " + databaseUsername +
                     " WITH ENCRYPTED PASSWORD " + databasePassword)) {
        qDebug() << "Successfully added user: " << databaseUsername;

      } else {
        qDebug() << "Unable to create user: " << databaseUsername << " - "
                 << query.lastError().text();
      }

      // Grant privileges
      query.clear();
      if (query.exec("GRANT ALL PRIVILEGES ON DATABASE " + databaseName +
                     " to " + databaseUsername)) {
        qDebug() << "Successfully granted privileges to user "
                 << databaseUsername << " on database " << databaseName;
      } else {
        qDebug() << "Unable to grant privileges to: " << databaseUsername
                 << " on database " << databaseName << " - "
                 << query.lastError().text();
      }

      // Change database to the one we created.
      mDb.close();
      mDb.setUserName(databaseUsername);
      mDb.setPassword(databasePassword);
      mDb.setDatabaseName(databaseName);

      if (mDb.open()) {
        qDebug() << "Successfully connected to new database";
      }
    }
  } else {
    qDebug() << "Successfully connected to database";
  }

  // Check if tables exists
  if (mDb.tables() == QStringList()) {
    qDebug() << "Could not find any tables, creating.";
    QSqlQuery query(mDb);
    bool ok = query.exec("CREATE TABLE sessions(id smallserial PRIMARY KEY, "
                         "name VARCHAR (50) UNIQUE NOT NULL, "
                         "created_at TIMESTAMP NOT NULL)");

    if (ok) {
      qDebug() << "Successfully created sessions";
    } else {
      qDebug() << "Unable to create table sessions - "
               << query.lastError().text();
    }

    // Create datapoints
    query.clear();
    ok = query.exec(
        "CREATE TABLE data_points(session_id INTEGER REFERENCES sessions(id),"
        "type INTEGER NOT NULL,"
        "value NUMERIC (6, 2) NOT NULL,"
        "created_at TIMESTAMP NOT NULL)");
    if (ok) {
      qDebug() << "Successfully created data points table";
    } else {
      qDebug() << "Unable to create data points table - " << query.lastError();
    }
  }
}

void DBConnection::addDataPoint(QVariant value, int type) {
  // qDebug() << "Adding datapoint: " << value;
  QSqlQuery query(mDb);
  // Get last session

  query.prepare("INSERT INTO data_points (session_id, type, value, created_at) "
                "VALUES(:session_id, :type, :value, :created_at)");
  query.bindValue(":session_id", mActiveSession);
  query.bindValue(":type", type);
  query.bindValue(":value", value);
  query.bindValue(":created_at", QDateTime::currentDateTime());

  if (!query.exec()) {
    qDebug() << query.lastError().text();
    qDebug() << "Value: " << value;
  }
}

void DBConnection::createNewSession() {
  QSqlQuery query(mDb);
  query.prepare(
      "INSERT INTO sessions (name, created_at) VALUES(:name, :created_at)");
  query.bindValue(":name", QDateTime::currentDateTime());
  query.bindValue(":created_at", QDateTime::currentDateTime());

  if (!query.exec()) {
    qDebug() << query.lastError().text();
  }

  mActiveSession = query.lastInsertId().toInt();
};

void DBConnection::resumeSession() {
  QSqlQuery query(mDb);
  // Get last session
  if (!query.exec("SELECT * FROM sessions ORDER BY created_at DESC")) {
    qDebug() << query.lastError().text();
  }

  qDebug() << query.first();
  mActiveSession = query.value(0).toInt();
  qDebug() << "Last session id is: " << mActiveSession;
}
