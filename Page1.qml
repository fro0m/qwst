import QtQuick 2.7

Page1Form {
    id: componentRoot
    signal clicked()
    button1.onClicked: {
        console.log("Button Pressed. Entered text: " + textField1.text);
        componentRoot.clicked()

    }
}
