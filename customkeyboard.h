#ifndef CUSTOMKEYBOARD_H
#define CUSTOMKEYBOARD_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSignalMapper>
#include <QMap>

class CustomKeyBoard : public QWidget {
    Q_OBJECT

public:
    explicit CustomKeyBoard(QWidget *parent = nullptr);

    void enableAll();
    void disableByKey(const QChar &key);

signals:
    void newKeyTyped(const QChar &key);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void onButtonClick(const QChar &key);

private:
    QMap<QString, QPushButton *> buttons;
};

#endif // CUSTOMKEYBOARD_H
