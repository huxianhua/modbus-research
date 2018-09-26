/*
import QtQuick 2.0

//Rectangle

Rectangle{
    width: 640; height: 480;

    color: Qt.rgba(0.8,0.6,0.4,1.0);

    Column {
        anchors.fill: parent; spacing: 20

        Text {
            text: "If a translation is available for the system language (eg. French) then the "+
            "string below will translated (eg. 'Bonjour'). Otherwise it will show 'Hello'."
            width: parent.width; wrapMode: Text.WordWrap
        }

        Text {
            text: qsTr("Hello")
            font.pointSize: 25; anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
*/


import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Extras 1.4

import QtQuick 2.6
import QtQuick.Controls 1.4
import QtQuick.Window 2.0


Rectangle{
    //visible: true;
    id: root;
    objectName: "nb";
    width: 200;
    height: 200;

    color: Qt.rgba(1,1,1,0.1);

    //color: "#161616";


    signal signal_init(string str);

    signal sig_test();

    signal sig_clicked(string str);



    function setTextName(str)
    {
        name.text = str;
    }



    Component.onCompleted:
    {
        signal_init.connect(setTextName);
    }

    Component.onDestruction:{

        signal_init.disconnect(setTextName)
    }

    MouseArea{
        anchors.fill: parent;

        acceptedButtons: Qt.LeftButton | Qt.RightButton



        onClicked: {

            sig_clicked("onClicked");
            console.log("mouse click-- x: " + mouseX + "y:" + mouseY);
/*
            if (mouse.button == Qt.RightButton)
                parent.color = 'blue';
            else
                parent.color = 'red';
*/

        }
    }

    Column{
        anchors.top: parent.top;
        anchors.left: parent.left;
        anchors.leftMargin: 10;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 10;



       spacing: 20;
       padding: 50;



        Text{
            id: name;
            text: qsTr("welcom to my house!");
            //anchors.centerIn: parent;
        }

/*
        CircularGauge {
            id: speedometer
            value: 66
            //anchors.verticalCenter: parent.verticalCenter
            maximumValue: 280
            // We set the width to the height, because the height will always be
            // the more limited factor. Also, all circular controls letterbox
            // their contents to ensure that they remain circular. However, we
            // don't want to extra space on the left and right of our gauges,
            // because they're laid out horizontally, and that would create
            // large horizontal gaps between gauges on wide screens.
            width: height
            height: container.height * 0.5

             style: DashboardGaugeStyle {}
        }*/


        Row{
            spacing: 20;
            CircularGauge {
                value: 15;
                minimumValue: 0;
                maximumValue: 100;
                style: CircularGaugeStyle {
                    needle: Rectangle {
                        y: outerRadius * 0.15
                        implicitWidth: outerRadius * 0.03
                        implicitHeight: outerRadius * 0.9
                        antialiasing: true
                        color: Qt.rgba(0.66, 0.3, 0, 1)
                    }
                }
            }
            CircularGauge {
                value: 25;
                minimumValue: 0;
                maximumValue: 100;

                style: CircularGaugeStyle {
                    needle: Rectangle {
                        y: outerRadius * 0.15
                        implicitWidth: outerRadius * 0.03
                        implicitHeight: outerRadius * 0.9
                        antialiasing: true
                        color: Qt.rgba(0.66, 0.3, 0, 1)
                    }
                }
            }
            CircularGauge {
                value: 5;
                minimumValue: 0
                maximumValue: 8

                anchors.verticalCenter: parent.verticalCenter

                style: CircularGaugeStyle {

                    needle: Rectangle {
                        y: outerRadius * 0.15
                        implicitWidth: outerRadius * 0.03
                        implicitHeight: outerRadius * 0.9
                        antialiasing: true
                        color: Qt.rgba(0.66, 0.3, 0, 1)

                    }
                }
            }

        }

        CircularGauge {
            id: gauge
            //anchors.fill: parent
            style: CircularGaugeStyle {
                labelInset: outerRadius * 0.2

                tickmarkLabel: null

                tickmark: Text {
                    text: styleData.value

                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.top: parent.bottom
                        text: styleData.index
                        color: "blue"
                    }
                }

                minorTickmark: Text {
                    text: styleData.value
                    font.pixelSize: 8

                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.top: parent.bottom
                        text: styleData.index
                        font.pixelSize: 8
                        color: "blue"
                    }
                }
            }

            Text {
                id: indexText
                text: "Major and minor indices"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: valueText.top
                color: "blue"
            }
            Text {
                id: valueText
                text: "Major and minor values"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
            }
        }




        Button{
            id: btn;
            text: "button -- hello";
            onClicked: {
                sig_test();
            }
        }


    }

}
