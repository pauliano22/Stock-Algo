// data_parser.cpp
#include "data_parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<PriceData> DataParser::load_csv(const std::string& filename) {
    std::vector<PriceData> data;
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return data;
    }

    // Skip the header line (assumes CSV has a header)
    std::getline(file, line);

    // Read each line of the CSV
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        PriceData entry;
        std::getline(ss, entry.date, ',');
        ss >> entry.open;
        ss.ignore(1, ','); // Ignore the comma
        ss >> entry.close;
        data.push_back(entry);
    }

    file.close();
    return data;
}
