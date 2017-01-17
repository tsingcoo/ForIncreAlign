//
// Created by 王青龙 on 18/12/2016.
//

#include "infer_align2.h"

void InferAlign2::ReadGizaATable(std::string inputFile) {
    std::ifstream fin(inputFile);
    std::string line;
    int position_ch;
    int position_en;
    int length_ch;
    int max_length_en;//用不到
    double prop_a;

    while (std::getline(fin, line)) {
        std::istringstream iss(line);
        iss >> position_ch;
        iss >> position_en;
        iss >> length_ch;
        iss >> max_length_en;
        iss >> prop_a;

        a_table_[length_ch][position_en][position_ch] = prop_a;
    }
    fin.close();

}

void InferAlign2::ReadMyATable(std::string inputFile) {
    std::ifstream fin(inputFile);
    std::string line;
    int length_ch;
    int position_en;
    int position_ch;
    double prop_a;

    while (std::getline(fin, line)){
        std::istringstream iss(line);
        iss>>length_ch;
        iss>>position_en;
        iss>>position_ch;
        iss>>prop_a;
        a_table_[length_ch][position_en][position_ch] = prop_a;
    }
    fin.close();
}

void InferAlign2::ConstrucATable() {
    for (int l = 1; l != long_sentence; ++l) {
        a_table_.insert({l, std::unordered_map<int, std::unordered_map<int, double>>()});
        for (int j = 1; j != long_sentence; ++j) {
            a_table_[l].insert({j, std::unordered_map<int, double>()});
            for (int i = 0; i != long_sentence; ++i) {
                a_table_[l][j].insert({i, 1.0 / (l + 1)});
            }
        }
    }
}

void InferAlign2::OutputAlign(std::string outputFile) {
    std::ofstream fout(outputFile);
    bool firstword = true;
    double tmp_max = 0.0;
    int tmp_i = 0;

    for(auto line = 0; line < corpus_index_ch_.size(); ++line){
        firstword = true;
        int l = (int)corpus_index_ch_[line].size() -1;
        std::vector<int> viterbi_alignment(corpus_index_en_[line].size());
        for(auto j = 0; j < corpus_index_en_[line].size(); ++j){
            tmp_max = 0.0;
            tmp_i = 0;
            for(auto i = 0; i < corpus_index_ch_[line].size(); ++i){
                double v = t_table_[corpus_index_ch_[line][i]][corpus_index_en_[line][j]]*a_table_[l][j][i];//难道这里我没有考虑能不能找到这个词对的概率？
                if(tmp_max < v){
                    tmp_max = v;
                    tmp_i = i;
                }
            }
            viterbi_alignment[j] = tmp_i;
        }
        for(auto j = 0; j < corpus_index_en_[line].size(); ++j){
            if(viterbi_alignment[j]){
                if(firstword){
                    firstword = false;
                } else{
                    fout<<" ";
                }
                fout<<viterbi_alignment[j]-1<<"-"<<j;
            }
        }
        fout<<std::endl;
    }
    fout.close();
}


