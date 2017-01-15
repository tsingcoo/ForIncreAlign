//
// Created by 王青龙 on 07/01/2017.
//

#ifndef INCREALIGN_INFER_ALIGNH_H
#define INCREALIGN_INFER_ALIGNH_H

#include "infer_align.h"
#include <algorithm>

const int kLongSentence = 101;
const double kProbSmooth = 1e-4;
const double kHMMAlignmentModelSmoothFactor = 0.2;
const double kGLOBALProbabilityForEmpty = 0.4;

class InferAlignh : public InferAlign {
public:
    void ConstructAlCount_();

    void ReadBackgroundAlCount_(std::string filename);

    void ReadBackgroundai_(std::string filename);

    void ReadBackgroundbi_(std::string filename);

    void ConstructNetN();

    void InitNetN(std::vector<int> &v_ch, std::vector<int> &v_en, const int &cnt_line_ch, const int &cnt_line_en);

    void ConstructNetE();

    void InitNetE(bool doInit, const int &cnt_line_ch);

    void EMLoop();

    void MakeHMMNetwork(std::vector<int> &v_ch, std::vector<int> &v_en, bool doInit);

    void ForwardBackwardTraining(std::vector<int> &v_ch, std::vector<int> &v_en, std::vector<double> &betainit_global,
                                 bool doInit);

    void
    HMMRealViterbi(std::string output_file, std::vector<int> &v_ch, std::vector<int> &v_en,
                   std::vector<double> &betainit_global, bool doInit);

public:
    std::vector<std::vector<double >> net_n_;
    std::vector<std::vector<double >> net_e_;

    std::vector<double> gamma_;
    std::vector<double> E_;
    std::vector<int> vit_;
    std::vector<int> viterbi_alignment_;

    std::unordered_map<int, double> AlCount_;

    std::unordered_map<int, std::vector<double >> ai_;
    std::unordered_map<int, std::vector<double >> bi_;
};

#endif //INCREALIGN_INFER_ALIGNH_H
