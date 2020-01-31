import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtCharts 2.3
import aEneroth.SerialPortManager 1.0

Page {
  Timer {
    interval: 2000
    repeat: true
    running: true
    triggeredOnStart: true
    onTriggered: {
      //Get temp and log.
      console.log("Getting temp:")
      serialPortManager.read()
    }
  }

  Connections {
    target: serialPortManager
    onTemp: {
      console.log(data)
      //check tthat data is either blurps or temp
      mySeries.add(data)
    }
  }

  ColumnLayout {
    anchors.fill: parent

    ChartView {
      id: chartView
      width: 400
      height: 300
      theme: ChartView.ChartThemeBrownSand
      antialiasing: true

      ValueAxis {
        id: valueAxis
        min: 0
        max: mySeries.currentCount + 2
        tickCount: 12
        labelFormat: "%.0f"
      }

      ValueAxis {
        id: valueAxisY
        min: 0
        max: 40
        tickCount: 12
        labelFormat: "%.0f"
      }

      SplineSeries {
        id: mySeries
        axisX: valueAxis
        axisY: valueAxisY
        property int currentCount: 0
        function add(temp) {
          append(currentCount, temp)
          currentCount++
        }
      }
    }
  }
}
