#pragma once
#include "fasta/FastaParser.hpp"
#include <string>

struct AnalysisResult{
    std::string id;
    int length;
    int countA = 0;
    int countC = 0;
    int countT = 0;
    int countG = 0;
    double gcContent;
};

class AnalysisEngine{
    
    public:
    AnalysisResult analyse(Sequence seq);

};