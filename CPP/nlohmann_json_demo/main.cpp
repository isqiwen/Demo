#include <iostream>
#include <fstream>

#include <nlohmann/json.hpp>


int main(int argc, char** argv) {
    
    if (argc < 2) {
        std::cout << "Please specify  input json!" << std::endl;
    }

    std::fstream file(argv[1], std::ios::binary | std::ios::in);
    if (!file.is_open()) {
        std::cout << "Failed to open " << argv << "!" << std::endl;
    }

    nlohmann::json j;
    file >> j;

    if (j.contains("sys_channel_num")) {
        std::cout << j["sys_channel_num"] << std::endl;
    }
    else {
        std::cout << "there is no entry with key sys_channel_num" << std::endl;
    }

    return 0;
}
