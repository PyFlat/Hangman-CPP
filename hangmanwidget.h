#ifndef HANGMANWIDGET_H
#define HANGMANWIDGET_H

#include <qwidget.h>
class HangmanWidget: public QWidget
{
public:
    explicit HangmanWidget(QWidget *parent = nullptr);

    void resetHangman();

    void incrementHangman();

    bool gameOver;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int hangmanParts;
    static constexpr int maxParts = 9;
};

#endif // HANGMANWIDGET_H
