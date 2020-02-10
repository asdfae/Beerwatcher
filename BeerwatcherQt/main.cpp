#include "dbconnection.h"
#include "serialportmanager.h"
#include "systemactions.h"

#include <QApplication>
#include <QProcess>
#include <QQmlApplicationEngine>
#include <QScreen>
#include <QtGlobal>

//!
//! \brief main
//! \param argc
//! \param argv
//! \return
//!
int main(int argc, char *argv[]) {
  qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  // QApplication instead of QGuiAppliction due to charts.
  QApplication app(argc, argv);
  app.setOrganizationName("aEneroth");
  app.setOrganizationDomain("aeneroth.com");
  app.setApplicationName("Beerwatcher");

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/main.qml"));

  qmlRegisterType<SerialPortManager>("aEneroth.SerialPortManager", 1, 0,
                                     "SerialPortManager");

  qmlRegisterType<DBConnection>("aEneroth.DBConnection", 1, 0, "DBconnection");
  qmlRegisterType<SystemActions>("aEneroth.SystemActions", 1, 0,
                                 "SystemActions");

  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app,
                   [url](QObject *obj, const QUrl &objUrl) {
                     if (!obj && url == objUrl)
                       QCoreApplication::exit(-1);
                   },
                   Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
