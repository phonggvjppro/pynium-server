#include <iostream>
#include <fstream>

const std::string DIGIT = "0123456789";
const std::string LOWER = "abcdefghijklmnopqrstuvxyzw";

bool check_file_exist(std::string file_path) {
    FILE *file = fopen(file_path, "r");
    if(file) {
        fclose(file);
        return true;   
    } else return false;
}

std::string random_string(const std::string CHARSET, const int length) {
    std::string tmp_s;
    tmp_s.reserve(length);

    for (int i = 0; i < length; ++i) {
        tmp_s += CHARSET[rand() % (sizeof(CHARSET) - 1)];
    }
    
    return tmp_s;
}