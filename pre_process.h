//
// Created by 王青龙 on 04/11/2016.
//

#ifndef INCREALIGN_PREPRO_H
#define INCREALIGN_PREPRO_H

#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

class PrePro{
public:
    void readFile(std::string str);
    void corpus2Index(std::string inputFile, std::string outputFile);
private:
    std::unordered_map<std::string, int> word_index;
};

#endif //INCREALIGN_PREPRO_H
