import QtQuick 2.9
import "../Forms"

LanguagePanelForm {
    colRef.width: Math.max(implicitWidth, rectRef.availableWidth) - 20
    languageDropDown: "Language"
}
