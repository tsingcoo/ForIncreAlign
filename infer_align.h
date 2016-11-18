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
    void OutputAlign(std::string outputFile);

private:
    std::unordered_map<int, std::unordered_map<int, double >> t_table_;
    std::vector<std::vector<int>> corpus_index_ch_;
    std::vector<std::vector<int>> corpus_index_en_;
};

#endif //INCREALIGN_INFERALIGN_H
