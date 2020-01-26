#include "serialportmanager.h"
#include "serialportreader.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);
  app.setOrganizationName("aEneroth");
  app.setOrganizationDomain("aeneroth.com");
  app.setApplicationName("Beerwatcher");

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/main.qml"));

  qmlRegisterType<SerialPortManager>("aEneroth.SerialPortManager", 1, 0,
                                     "SerialPortManager");

  //  qmlRegisterType<SerialPortReader>("aEneroth.SerialPortReader", 1, 0,
  //                                    "SerialPortReader");

  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
