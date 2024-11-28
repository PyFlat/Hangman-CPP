#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "words.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleNewKey(QChar key);

private:
    Ui::MainWindow *ui;

    QString currentWord;

    QString hiddenWord;

    Words words;

    std::unordered_map<QChar, std::vector<int>> analyzedWords;

    void startGame(QString word);

    void analyzeWord();

    void endGame(bool);
};
#endif // MAINWINDOW_H
