#pragma once
#include <string>
#include <vector>
struct Sequence{
    std::string id;
    std::string bases;

};

class FastaParser{
    public: 
    std::vector<Sequence> parse(std::string filePath);
};
