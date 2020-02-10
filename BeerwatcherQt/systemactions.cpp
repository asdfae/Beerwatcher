#include "systemactions.h"

SystemActions::SystemActions(QObject *parent) : QObject(parent) {}

void SystemActions::setBrightness(int brightness) {
  qDebug() << "Trying to set screen brightness to: " << brightness;
  QFile file("/sys/class/backlight/rpi_backlight/brightness");
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    qDebug() << "unable to open file for write";
    return;
  }
  file.write(QByteArray::number(brightness));
}

void SystemActions::setScreenState(int state) {
  qDebug() << "Trying to set screen to: " << state;
  QFile file("/sys/class/backlight/rpi_backlight/bl_power");
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    qDebug() << "unable to open file for write";
    return;
  }
  file.write(QByteArray::number(state));
}
