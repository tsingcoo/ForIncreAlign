//
// Created by 王青龙 on 18/12/2016.
//

#ifndef INCREALIGN_INFER_ALIGN2_H
#define INCREALIGN_INFER_ALIGN2_H

#include "infer_align.h"

#include <string>
#include <vector>
#include <unordered_map>

const int long_sentence = 101;

class InferAlign2 : public InferAlign{
public:
    InferAlign2(){
        ConstrucATable();
    }
    void ConstrucATable();
    void ReadGizaATable(std::string inputFile);
    void ReadMyATable(std::string inputFile);
    void OutputAlign(std::string outputFile);

public:
    std::unordered_map<int, std::unordered_map<int, std::unordered_map<int, double >>> a_table_;


};

#endif //INCREALIGN_INFER_ALIGN2_H
