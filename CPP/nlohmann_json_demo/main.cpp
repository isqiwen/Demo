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

    nlohmann::ordered_json j;
    file >> j;

    std::cout << j.dump() << std::endl;

    nlohmann::ordered_json jj = nlohmann::ordered_json::parse(j.dump());
    std::cout << jj.dump() << std::endl;
    std::cout << jj["ReconCommands"] << std::endl;

    return 0;
}
