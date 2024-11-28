#include "CustomKeyBoard.h"
#include <QKeyEvent>

CustomKeyBoard::CustomKeyBoard(QWidget *parent)
    : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    QStringList keyboardLayout = {"QWERTZUIOP", "ASDFGHJKL", "YXCVBNM"};
    for (const QString &row : keyboardLayout) {
        QHBoxLayout *rowLayout = new QHBoxLayout();
        for (QChar letter : row) {
            QChar key = letter.toUpper();
            QPushButton *button = new QPushButton(key, this);
            buttons[key] = button;
            connect(button, &QPushButton::clicked, [this, key]() { onButtonClick(key); });
            rowLayout->addWidget(button);
        }
        layout->addLayout(rowLayout);
    }
}

void CustomKeyBoard::onButtonClick(const QChar &key) {
    emit newKeyTyped(key.toLower());
}

void CustomKeyBoard::keyPressEvent(QKeyEvent *event) {
    QString text = event->text().toUpper();

    if (!text.isEmpty()) {
        QChar key = text[0];
        if (buttons.contains(key)) {
            buttons[key]->click();
        }
    }
}


void CustomKeyBoard::enableAll() {
    for (auto button : buttons) {
        button->setEnabled(true);
    }
}

void CustomKeyBoard::disableByKey(const QChar &key) {
    if (buttons.contains(key.toUpper())) {
        buttons[key.toUpper()]->setEnabled(false);
    }
}
