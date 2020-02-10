#ifndef SYSTEMACTIONS_H
#define SYSTEMACTIONS_H

#include <QDebug>
#include <QFile>
#include <QObject>

class SystemActions : public QObject {
  Q_OBJECT
  Q_ENUMS(ScreenState);

public:
  explicit SystemActions(QObject *parent = nullptr);

  enum ScreenState { ON, OFF };

  Q_INVOKABLE void setBrightness(int brightness);
  Q_INVOKABLE void setScreenState(int state);
};

#endif // SYSTEMACTIONS_H
