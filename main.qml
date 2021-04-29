import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    color: "#191928"
    title: qsTr("Monster slayer")

    ColumnLayout {
        anchors {
            fill: parent
            leftMargin: 10
            rightMargin: 10
            topMargin: 10
            bottomMargin: 10
        }

        Text{
            text: qsTr("Player")
            font.pixelSize: 25
            color: "white"
        }

        ProgressBar{
            id: playerProgressBar
            from: 0
            to: 100 // max value
            Layout.fillWidth: true
            value: backend.playerBar
        }

        Text{
            text: qsTr("Monster")
            font.pixelSize: 25
            color: "white"
        }

        ProgressBar{
            id: monsterProgressBar
            from: 0
            to: 100 // max value
            Layout.fillWidth: true
            value: backend.monsterBar;
        }

        Button{
            visible: !backend.gameOver
            text: qsTr("Attack")
            Layout.alignment: horizontalCenter
            font.pixelSize: 20
            Layout.fillWidth: true
            onClicked: {
                backend.attack()
            }
        }

        Button{
            visible: !backend.gameOver
            text: qsTr("Heal")
            Layout.alignment: horizontalCenter
            font.pixelSize: 20
            Layout.fillWidth: true
            enabled: backend.healEnabled
            onClicked: {
                backend.heal()
            }
        }

        Button{
            visible: backend.gameOver
            text: qsTr("Play again")
            Layout.alignment: horizontalCenter
            font.pixelSize: 20
            Layout.fillWidth: true
            onClicked: {
                backend.playAgain()
            }
        }

        Text{
            visible: backend.gameOver
            text: backend.winner == "player" ? "YOU WIN" : "GAME OVER"
            font.pixelSize: 25
            horizontalAlignment: Text.AlignHCenter
            Layout.alignment: horizontalCenter
            Layout.fillWidth: true
            color: backend.winner == "player" ? "green": "red"
        }
    }
}
