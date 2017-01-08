cmake_minimum_required(VERSION 3.6)
project(IncreAlign)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp incre_align.cpp incre_align.h pre_process.cpp pre_process.h distance.cpp distance.h infer_align.cpp infer_align.h vocab.cpp vocab.h two_vocab_infer_align.cpp two_vocab_infer_align.h two_vocab_infer_align.cpp two_vocab_infer_align.h two_index_infer_align.cpp two_index_infer_align.h two_index_infer_align.cpp two_index_infer_align.h infer_align2.cpp infer_align2.h infer_alignh.cpp infer_alignh.h)
add_executable(IncreAlign ${SOURCE_FILES})