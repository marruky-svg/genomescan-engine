#include "server/HttpServer.hpp"
#include "fasta/FastaParser.hpp"
int main(){
    FastaParser parser;
    auto sequences = parser.parse("../src/teste.fasta");
    for(auto& seq : sequences){
        std::cout << "ID: " << seq.id << std::endl;
        std::cout << "Bases: " << seq.bases << std::endl;
    }
    return 0;
}