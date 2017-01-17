//
// Created by 王青龙 on 06/11/2016.
//

#include "infer_align.h"

void InferAlign::ReadTTable(std::string inputFile) {
    std::ifstream fin(inputFile);
    std::string line;
    int index_ch;
    int index_en;
    double prop_t;
    while(std::getline(fin, line)){
        std::istringstream ss(line);
        ss>>index_ch;
        if(t_table_.find(index_ch) == t_table_.end()){
            t_table_[index_ch] = std::unordered_map<int, double>();
        }
        ss>>index_en;
        ss>>prop_t;
        t_table_[index_ch].insert({index_en, prop_t});
    }
    fin.close();
}

void InferAlign::ReadCorpusIndexCh(std::string inputFile) {
    std::ifstream fin(inputFile);
    std::string line;
    std::string index;
    int line_num = 0;
    while (std::getline(fin, line)){
        std::istringstream ss(line);
        corpus_index_ch_.push_back(std::vector<int>());
        corpus_index_ch_[line_num].push_back(0);//在源语言开头加入空字符
        while (ss >> index){
            corpus_index_ch_[line_num].push_back(std::stoi(index));
        }
        ++line_num;
    }
    fin.close();
}

void InferAlign::ReadCorpusIndexEn(std::string inputFile) {
    std::ifstream fin(inputFile);
    std::string line;
    std::string index;
    int line_num = 0;
    while (std::getline(fin, line)){
        std::istringstream ss(line);
        corpus_index_en_.push_back(std::vector<int>());
        while (ss >> index){
            corpus_index_en_[line_num].push_back(std::stoi(index));
        }
        ++line_num;
    }
    fin.close();
}



void InferAlign::OutputAlign(std::string outputFile) {
    std::ofstream fout(outputFile);
    double tmp_max = 0.0;
    int tmp_index = 0;
    bool first_word = true;

    for(auto i = 0; i < corpus_index_ch_.size(); ++i){
        first_word = true;
        std::vector<int> viterbi_alignment(corpus_index_en_[i].size(), 0);
        for(auto j = 0; j < corpus_index_en_[i].size(); ++j){
            tmp_max = 0.0;
            tmp_index = 0;
            for (auto k = 0; k < corpus_index_ch_[i].size(); ++k){
                if(t_table_.find(corpus_index_ch_[i][k]) != t_table_.end()&&t_table_[corpus_index_ch_[i][k]].find(corpus_index_en_[i][j]) != t_table_[corpus_index_ch_[i][k]].end()){
                    double tmp_t = t_table_[corpus_index_ch_[i][k]][corpus_index_en_[i][j]];
                    if(tmp_max < tmp_t){
                        tmp_max = tmp_t;
                        tmp_index = k;
                    }
                }
            }
            viterbi_alignment[j] = tmp_index;
        }

        for(auto j = 0; j != corpus_index_en_[i].size(); ++j){
            if(viterbi_alignment[j] != -1 && viterbi_alignment[j] != 0){
                if(first_word){
                    first_word = false;
                } else{
                    fout<<" ";
                }
                fout << viterbi_alignment[j] - 1 << "-" << j;
            }
        }
        fout<<std::endl;
    }
    fout.close();
}

void InferAlign::ReadGizaVcbCh(std::string inputFile) {
    std::ifstream fin(inputFile);
    std::string line;
    int index;
    std::string word;
    int freq;
    while (std::getline(fin, line)) {
        std::istringstream iss(line);
        iss>>index;
        iss>>word;
        iss>>freq;
        word_freq_ch_.insert({index, freq});
    }
    fin.close();
}

void InferAlign::ReadGizaVcbEn(std::string inputFile) {
    std::ifstream fin(inputFile);
    std::string line;
    int index;
    std::string word;
    int freq;
    while (std::getline(fin, line)) {
        std::istringstream iss(line);
        iss>>index;
        iss>>word;
        iss>>freq;
        word_freq_en_.insert({index, freq});
    }
    fin.close();
}



