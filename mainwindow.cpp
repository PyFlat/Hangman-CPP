#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    words = Words();
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->homepage_btn, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->start_custom_btn, &QPushButton::clicked, this, [this](){
        startGame(ui->custom_word_entry->text());
    });

    connect(ui->start_random_btn, &QPushButton::clicked, this, [this](){
        startGame("");
    });

    connect(ui->restart_btn, &QPushButton::clicked, this, [this](){
        startGame("");
    });

    connect(ui->custom_word_entry, &QLineEdit::textChanged, this, [this](){
        QString word = ui->custom_word_entry->text();
        int currentLength = word.length();
        int maxLength = ui->custom_word_entry->maxLength();
        QString labelText = QString("Wort eingeben (%1/%2)").arg(currentLength).arg(maxLength);
        ui->custom_word_label->setText(labelText);

    });
}

void MainWindow::endGame(bool win) {
    ui->stackedWidget->setCurrentIndex(2);

    QString message = win
                          ? QString("Du hast gewonnen! Das Wort war: %1").arg(currentWord)
                          : QString("Du hast verloren! Das Wort war: %1").arg(currentWord);

    ui->results_label->setText(message);
}


void MainWindow::startGame(QString word){
    disconnect(ui->keyboard_widget, &CustomKeyBoard::newKeyTyped, this, &MainWindow::handleNewKey);

    ui->stackedWidget->setCurrentIndex(1);
    ui->keyboard_widget->enableAll();
    ui->hangman_widget->resetHangman();
    if (word.isEmpty()){
        currentWord = QString::fromStdString(words.getRandomWord());
    }else{
        currentWord = word;
        ui->custom_word_entry->clear();
    }

    analyzeWord();
    hiddenWord = QString::fromStdString(std::string(currentWord.length(), '_'));
    ui->word_label->setText(hiddenWord);

    connect(ui->keyboard_widget, &CustomKeyBoard::newKeyTyped, this, &MainWindow::handleNewKey);
}

void MainWindow::handleNewKey(QChar key){
    ui->keyboard_widget->disableByKey(key);

    if (analyzedWords.find(key) != analyzedWords.end()) {
        for (int index : analyzedWords[key]) {
            hiddenWord[index] = key;
        }
        ui->word_label->setText(hiddenWord);

        if (currentWord == hiddenWord) {
            endGame(true);
        }
    } else {
        ui->hangman_widget->incrementHangman();
    }

    if (ui->hangman_widget->gameOver) endGame(false);
}

void MainWindow::analyzeWord(){
    analyzedWords.clear();

    for (size_t i = 0; i < currentWord.size(); ++i) {
        QChar ch = currentWord[i];
        analyzedWords[ch].push_back(i);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
