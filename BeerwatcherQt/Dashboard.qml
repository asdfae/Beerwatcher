import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtCharts 2.3
import aEneroth.SerialPortManager 1.0

Page {
  Timer {
    interval: 1000
    repeat: true
    running: true
    onTriggered: {
      //Get temp and log.
      console.log("Getting temp:")
      serialPortManager.read()
    }
  }

  ColumnLayout {
    anchors.fill: parent

    ChartView {
        width: 400
        height: 300
        theme: ChartView.ChartThemeBrownSand
        antialiasing: false

        BarSeries {
            id: mySeries
            axisX: BarCategoryAxis { categories: ["2007", "2008", "2009", "2010", "2011", "2012" ] }
            BarSet { label: "Bob"; values: [2, 2, 3, 4, 5, 6] }
            BarSet { label: "Susan"; values: [5, 1, 2, 4, 1, 7] }
            BarSet { label: "James"; values: [3, 5, 8, 13, 5, 8] }
        }
    }
  }
}
