import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls.Material 2.12
import QtCharts 2.3
import aEneroth.SerialPortManager 1.0

Page {
  topPadding: 15
  leftPadding: 15
  rightPadding: 15
  bottomPadding: 0

  ColumnLayout {
    anchors.fill: parent

    RowLayout {
      height: parent.height / 3
      width: parent.width
      ColumnLayout {
        Label {
          text: "BeerWatcher"
          color: "#F3CA3E"
          font.pixelSize: 36
        }

        Item {
          height: 20
        }

        Label {
          text: qsTr("Time")
        }
        Label {
          id: timeLabel

          Timer{
            interval: 1000
            running: true
            repeat: true
            triggeredOnStart: true
            onTriggered: {

              timeLabel.text = new Date().toLocaleTimeString(Qt.locale(), Locale.ShortFormat);
            }
          }

        }
      }
      Item {Layout.fillWidth: true}

      ColumnLayout {
        Button {
          text: qsTr("Go Back")
          highlighted: true
          font.pixelSize: 14
          Layout.alignment: Qt.AlignHCenter
          Layout.preferredHeight: 58
          Layout.preferredWidth: 190

          background: Rectangle {
            color: Material.accent
            radius: 15
          }
          onClicked: {
            console.log("Go back pushed")
            stackView.pop()
          }
        }

        Button {
          text: qsTr("☰ Saved data")
          highlighted: true
          background: Rectangle {
            color: "transparent"
            border.color: Material.accent
            border.width: 1
            radius: 15
          }

          font.pixelSize: 14
          Layout.alignment: Qt.AlignHCenter
          Layout.preferredHeight: 58
          Layout.preferredWidth: 190

          onClicked: {
            console.log("Go back pushed")
            stackView.pop()
          }
        }
      }
    }

    Label {
      text: qsTr("Temperature & vibrations over time")
    }

    BeerChart {
      Layout.fillHeight: true
    }
  }
}
