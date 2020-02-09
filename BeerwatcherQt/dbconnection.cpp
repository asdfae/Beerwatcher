#include "dbconnection.h"

//!
//! \brief DBConnection::DBConnection
//! \param parent
//!
DBConnection::DBConnection(QObject *parent) : QObject(parent) {
  QString databaseName = "beerwatch";
  QString databaseUsername = "beerwatch";
  QString databasePassword = "'beerwatch'";

  QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
  db.setHostName("localhost");
  db.setDatabaseName("beerwatch");
  db.setUserName("beerwatch");
  db.setPassword("beerwatch");

  // Check if ok, else assume dabase is not create, so we create it and add our
  // beerwatch user.
  if (!db.open()) {
    qDebug() << "Unable to connect to database, checking if we can create it";
    db.setUserName("postgres");
    db.setPassword("");
    db.setDatabaseName("");
    if (!db.open()) {
      qDebug() << "Unable to connect to postgres. is server running?";
    } else {

      // Create database
      qDebug() << "Connected as postgres, creating database.";
      QSqlQuery query(db);
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
      db.close();
      db.setUserName(databaseUsername);
      db.setPassword(databasePassword);
      db.setDatabaseName(databaseName);

      if (db.open()) {
        qDebug() << "Successfully connected to new database";
      }
    }
  } else {
    qDebug() << "Successfully connected to database";
  }

  // Check if tables exists
  if (db.tables() == QStringList()) {
    qDebug() << "Could not find any tables, creating.";
    QSqlQuery query(db);
    bool ok = query.exec("CREATE TABLE sessions(id smallserial PRIMARY KEY, "
                         "name VARCHAR (50) UNIQUE NOT NULL, "
                         "created_at TIMESTAMP NOT NULL)");

    if (ok) {
      qDebug() << "Successfully created sessions";
    } else {
      qDebug() << "Unable to create table sessions - "
               << query.lastError().text();
    }
  }
}

void DBConnection::connect() { qDebug() << "Connnecting"; }
