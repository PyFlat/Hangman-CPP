#include "hangmanwidget.h"
#include <qpen.h>
#include <qpainter.h>

HangmanWidget::HangmanWidget(QWidget *parent):QWidget(parent), hangmanParts(0), gameOver(false) {}

void HangmanWidget::resetHangman(){
    hangmanParts = 0;
    gameOver = false;
}

void HangmanWidget::incrementHangman(){
    hangmanParts++;
    if (hangmanParts >= maxParts) gameOver = true;
    update();
}

void HangmanWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(Qt::white, 2);
    painter.setPen(pen);

    if (hangmanParts >= 1)
        painter.drawArc(100, 150, 100, 100, 0, 180 * 16);

    if (hangmanParts >= 2)
        painter.drawLine(150, 150, 150, 50);

    if (hangmanParts >= 3)
        painter.drawLine(150, 50, 225, 50);

    if (hangmanParts >= 4)
        painter.drawLine(150, 75, 175, 50);

    if (hangmanParts >= 5)
        painter.drawLine(225, 50, 225, 75);

    if (hangmanParts >= 6)
        painter.drawEllipse(212, 75, 25, 25);

    if (hangmanParts >= 7)
        painter.drawLine(225, 100, 225, 150);

    if (hangmanParts >= 8) {
        painter.drawLine(225, 100, 212, 125);
        painter.drawLine(225, 100, 237, 125);
    }

    if (hangmanParts >= 9) {
        painter.drawLine(225, 150, 210, 175);
        painter.drawLine(225, 150, 240, 175);
    }
}
