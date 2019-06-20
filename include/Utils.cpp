#include "Utils.h"

std::vector<long double> GetRow(std::ifstream &inputFile) {
    std::vector<long double> buffer;

    std::string line;
    std::getline(inputFile, line);
    std::istringstream inputStream(line);

    std::string numString;
    while (std::getline(inputStream, numString, ',')) {
        buffer.push_back(1.0 * atoi(numString.c_str()));
    }

    return buffer;
}

std::vector<std::pair<int, std::vector<long double>>> GetDataset(std::string inputFilename) {
    std::vector<std::pair<int, std::vector<long double>>> trainDataset;
    std::ifstream trainingFile(inputFilename);

    while (true) {
        auto row = GetRow(trainingFile);
        if (row.empty()) {
            break;
        }
        int correctValue = row[0];
        trainDataset.push_back({correctValue, std::vector<long double>(row.begin() + 1, row.end())});
    }
    return trainDataset;
}
