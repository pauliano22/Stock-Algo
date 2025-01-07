// data_parser.h
#ifndef DATA_PARSER_H
#define DATA_PARSER_H

#include <vector>
#include <string>

// Define the structure to hold price data
struct PriceData {
    std::string date;
    double open, close;
};

class DataParser {
public:
    // Function to load CSV data (just a basic mock-up)
    std::vector<PriceData> load_csv(const std::string& filename);
};

#endif // DATA_PARSER_H
