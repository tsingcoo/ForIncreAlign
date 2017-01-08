#include "pre_process.h"
#include "distance.h"
#include "infer_align.h"
#include "infer_align2.h"
#include "infer_alignh.h"
#include "vocab.h"
#include "two_vocab_infer_align.h"
#include "two_vocab_infer_align.h"
#include "two_index_infer_align.h"

#include <iostream>

int main() {

//    Distance d;
//    d.readFile("/Users/wangql/windows/119/glove.100.txt");

//    InferAlign ia;
//    ia.ReadTTable("/Users/wangql/windows/119/s2t64.t1.5");
//    ia.ReadCorpusIndexCh("/Users/wangql/windows/119/corpus.ch.index");
//    ia.ReadCorpusIndexEn("/Users/wangql/windows/119/corpus.en.index");
//    ia.OutputAlign("/Users/wangql/windows/119/infer.align");

//    Vocab v;
//    v.readFile("/Users/wangql/windows/119/ch_30w.vcb");
//    v.CorpusFindOOV("/Users/wangql/windows/119/corpus.ch", "/Users/wangql/windows/119/corpus.ch.OOV");
//    v.readFile("/Users/wangql/windows/119/en_30w.vcb");
//    v.CorpusFindOOV("/Users/wangql/windows/119/corpus.en", "/Users/wangql/windows/119/corpus.en.OOV");





//    要非常注意，这类程序不能偷懒之定义一个对象，这会使得内部的私有成员变量存储的数据一直往上加
//    PrePro p_ch;
//    p_ch.readFile("/Users/wangql/Desktop/corpus.ch.vcb");
//    p_ch.corpus2Index("/Users/wangql/windows/119/26/corpus.ch", "/Users/wangql/windows/119/26/corpus.ch.index");
//
//    PrePro p_en;
//    p_en.readFile("/Users/wangql/Desktop/corpus.en.vcb");
//    p_en.corpus2Index("/Users/wangql/windows/119/26/corpus.en", "/Users/wangql/windows/119/26/corpus.en.index");


//    利用概率进行去推理491句
//    InferAlign ia;//model1推理
//    ia.ReadTTable("/Users/wangql/windows/119/16/s2t64.incre.t1.5");
//    ia.ReadCorpusIndexCh("/Users/wangql/windows/119/16/corpus.ch.index");
//    ia.ReadCorpusIndexEn("/Users/wangql/windows/119/16/corpus.en.index");
//    ia.OutputAlign("/Users/wangql/windows/119/16/infer.align");

//    InferAlign2 ia2;//model2推理
//    ia2.ReadTTable("/Users/wangql/Desktop/model2_5_em4.t");
////    ia2.ReadGizaATable("/Users/wangql/windows/119/16/s2t64.a2.5");
//    ia2.ReadMyATable("/Users/wangql/Desktop/model2_5_em4.a");
//    ia2.ReadCorpusIndexCh("/Users/wangql/windows/119/26/corpus.ch.index");
//    ia2.ReadCorpusIndexEn("/Users/wangql/windows/119/26/corpus.en.index");
//    ia2.OutputAlign("/Users/wangql/windows/119/26/infer.1610.align");

    InferAlignh iah;
    iah.ReadTTable("/Users/wangql/Desktop/hmm_26_5.t");
    iah.ReadCorpusIndexCh("/Users/wangql/windows/119/26/corpus.ch.index");
    iah.ReadCorpusIndexEn("/Users/wangql/windows/119/26/corpus.en.index");
    iah.ConstructAlCount_();
    iah.ReadBackgroundAlCount_("/Users/wangql/Desktop/hmm_26_5.AlCount");
    iah.ReadBackgroundai_("/Users/wangql/Desktop/hmm_26_5.ai");
    iah.ReadBackgroundbi_("/Users/wangql/Desktop/hmm_26_5.bi");
    iah.ConstructNetN();
    iah.ConstructNetE();
    iah.EMLoop();




    //利用大词表和小词表同时生成语料的index
//    TwoVocab tv_ch, tv_en;
//    tv_ch.ReadVocabs("/Users/wangql/windows/119/800w/LDC.ch.vcb", "/Users/wangql/windows/119/800w/corpus.ch.vcb");
//    tv_ch.Corpus2Index("/Users/wangql/windows/119/800w/corpus.ch", "/Users/wangql/windows/119/800w/corpus.ch.two.index");
//
//    tv_en.ReadVocabs("/Users/wangql/windows/119/800w/LDC.en.vcb", "/Users/wangql/windows/119/800w/corpus.en.vcb");
//    tv_en.Corpus2Index("/Users/wangql/windows/119/800w/corpus.en", "/Users/wangql/windows/119/800w/corpus.en.two.index");




    //得到corpus在test vocab上的index表示
//    PrePro p_test_ch, p_test_en;
//    p_test_ch.readFile("/Users/wangql/windows/119/800w/corpus.ch.vcb");
//    p_test_ch.corpus2Index("/Users/wangql/windows/119/800w/corpus.ch","/Users/wangql/windows/119/800w/corpus.ch.test.index");
//    p_test_en.readFile("/Users/wangql/windows/119/800w/corpus.en.vcb");
//    p_test_en.corpus2Index("/Users/wangql/windows/119/800w/corpus.en","/Users/wangql/windows/119/800w/corpus.en.test.index");
//
//
//    //得到corpus在train vocab上的index表示
//    PrePro p_train_ch, p_train_en;
//    p_train_ch.readFile("/Users/wangql/windows/119/800w/LDC.ch.vcb");
//    p_train_ch.corpus2Index("/Users/wangql/windows/119/800w/corpus.ch","/Users/wangql/windows/119/800w/corpus.ch.train.index");
//    p_train_en.readFile("/Users/wangql/windows/119/800w/LDC.en.vcb");
//    p_train_en.corpus2Index("/Users/wangql/windows/119/800w/corpus.en","/Users/wangql/windows/119/800w/corpus.en.train.index");


//    TwoIndexInferAlign tiia;
//    tiia.ReadIndexChTest("/Users/wangql/windows/119/800w/corpus.ch.test.index");
//    tiia.ReadIndexChTrain("/Users/wangql/windows/119/800w/corpus.ch.train.index");
//    tiia.ReadIndexEnTest("/Users/wangql/windows/119/800w/corpus.en.test.index");
//    tiia.ReadIndexEnTrain("/Users/wangql/windows/119/800w/corpus.en.train.index");
//    tiia.ReadTTableTest("/Users/wangql/windows/119/800w/s2t64.t1.491.5");
//    tiia.ReadTTableTrain("/Users/wangql/windows/119/800w/s2t64.t1.5");
//    tiia.OutputAlign("/Users/wangql/windows/119/800w/infer.two.index.align");
//    tiia.OutputAlignCombin("/Users/wangql/windows/119/infer.two.index.combin.align");



    return 0;
}