#ifndef WORDS_H
#define WORDS_H

#include <string>
#include <vector>

class Words
{
public:
    Words(const std::string &wordListPath = "wortliste.txt");

    std::string getRandomWord();

private:
    std::vector<std::string> wordlist;
};

#endif // WORDS_H
