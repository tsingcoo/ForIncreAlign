//
// Created by 王青龙 on 06/11/2016.
//

#ifndef INCREALIGN_INFERALIGN_H
#define INCREALIGN_INFERALIGN_H

#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <iostream>

class InferAlign{
public:
    void ReadTTable(std::string inputFile);
    void ReadCorpusIndexCh(std::string inputFile);
    void ReadCorpusIndexEn(std::string inputFile);
    virtual void OutputAlign(std::string outputFile);


    void ReadGizaVcbCh(std::string inputFile);
    void ReadGizaVcbEn(std::string inputFile);

public:
    std::unordered_map<int, std::unordered_map<int, double >> t_table_;
    std::vector<std::vector<int>> corpus_index_ch_;
    std::vector<std::vector<int>> corpus_index_en_;

    std::unordered_map<int, int> word_freq_ch_;
    std::unordered_map<int, int> word_freq_en_;
};

#endif //INCREALIGN_INFERALIGN_H
