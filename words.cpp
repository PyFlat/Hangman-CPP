#include "words.h"
#include "fstream"
#include "string"
#include <random>
#include "QString"
#include "QDir"
#include "QCoreApplication"

Words::Words(const std::string &wordListPath) {
    std::fstream myfile;

    // open file
    //myfile.open("C:/Users/Johannes/Downloads/Hangman/wortliste.txt");

    QString appDir = QCoreApplication::applicationDirPath();

    // Build the full path to the wordlist file
    QString fullPath = QDir(appDir).filePath(QString::fromStdString(wordListPath));

    // Open the file using the constructed full path
    myfile.open(fullPath.toStdString());

    if (myfile.is_open()) {
        std::string str;

        while (getline(myfile, str)) {
            wordlist.push_back(str);
        }
        myfile.close();
    }
}

std::string Words::getRandomWord(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, wordlist.size() - 1);
    return wordlist[dist(gen)];
}
