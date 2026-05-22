#include "analysis/AnalysisEngine.hpp"

AnalysisResult AnalysisEngine::analyse(Sequence sequence) {
    
    AnalysisResult result;
    result.length = sequence.bases.size();
    result.id = sequence.id;
    for(char c : sequence.bases){
     switch (c)
     {
        case 'A': result.countA += 1;break;
        case 'T': result.countT += 1;break;
        case 'C': result.countC += 1;break;
        case 'G': result.countG += 1;break;
     }
    }
    result.gcContent = (result.countC + result.countG)/(double)result.length*100;
    return result;
}