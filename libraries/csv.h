#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class CSVOperations { 
        vector<string> split(const string& line, char delimiter);
    public:
        vector<vector<string>> readFile(string file_name);
        void writeData(vector<string> header, string file_name, vector<vector<string>> data);
};

vector<string> CSVOperations:: split(const string& line, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(line);

    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<vector<string>> CSVOperations:: readFile(string file_name) {
    fstream reader;
    reader.open(file_name, ios::in); 
    string line, word;
    vector<vector<string>> csv_data;

    getline(reader, line);

    while(!reader.eof()) {
        getline(reader, line);
        stringstream ss(line);

        while(getline(ss, word)) {
            csv_data.push_back(split(word, ','));
        }
    }
    reader.close();
    return csv_data;
}

void CSVOperations:: writeData(vector<string> header, string file_name, vector<vector<string>> data) {
    fstream writer;
    writer.open(file_name, ios::out | ios::app);
    
    if(writer.is_open()) {

        writer.seekp(0, ios::end);

        if(writer.tellg() == 0) {
            for(int col = 0; col < header.size(); col++) {
                if(col == header.size()-1) {
                    writer << header.at(col);
                    break;
                }
                writer << header.at(col) << ", ";
            }
            writer << endl;
        }

        int row = 0;
        writer.seekp(0, ios::beg);

        while(row < data.size()) {
            for(int col = 0; col < data.at(row).size(); col++) {
                if(col == header.size()-1) {
                    writer << data.at(row).at(col);
                    break;
                }
                writer << data.at(row).at(col) << ", ";
            }
            writer << endl;
            row++;
        }
        writer.close();
    }
}