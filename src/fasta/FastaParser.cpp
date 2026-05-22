#include "FastaParser.hpp"
#include<fstream>

std::vector<Sequence> FastaParser::parse(std::string file) {
    std::vector<Sequence> sequences; 
    std::ifstream is;
    is.open(file, is.in);
    std::string line;
    Sequence sequence;
    while(std::getline(is, line))
    {   
        if(line[0] == '>') {
            if(!sequence.id.empty()){
                sequences.push_back(sequence);
            }
            sequence.id = line.substr(1);
            sequence.bases = "";
        }else {
            sequence.bases += line;
        }
    }
    if(!sequence.id.empty()){
        sequences.push_back(sequence);
    }
    is.close();
    return sequences;
}

    
    


