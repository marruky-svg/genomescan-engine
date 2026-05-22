#include "server/HttpServer.hpp"
#include "fasta/FastaParser.hpp"
#include "analysis/AnalysisEngine.hpp"
int main(){
    FastaParser parser;
    AnalysisEngine engine;
    auto sequences = parser.parse("../src/teste.fasta");
    for(auto& seq : sequences){
        std::cout << "ID: " << seq.id << std::endl;
        std::cout << "Bases: " << seq.bases << std::endl;
        AnalysisResult result = engine.analyse(seq);
         std::cout << "ID: " << result.id << std::endl;
        std::cout << "A: " << result.countA << std::endl;
        std::cout << "C: " << result.countC << std::endl;
        std::cout << "T: " << result.countT << std::endl;
        std::cout << "G: " << result.countG << std::endl;
        std::cout << "Proporção: " << result.gcContent<< std::endl;
    }
      
    return 0;
}