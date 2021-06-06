//
// Created by JouderMin on 2021/5/9.
//

#include "FileOperation.h"

using std::ios;
using std::vector;

FileOperation::FileOperation() {
    dataFile.open("./StudentData.dat", ios::in | ios::out | ios::binary);
    while (!dataFile) {
        std::system("type nul>StudentData.dat");
        dataFile.open("./StudentData.dat", ios::in | ios::out | ios::binary);
    }
}

FileOperation::~FileOperation() {
    dataFile.close();
}

void FileOperation::addLog(const StudentData & data) {
    dataFile.seekp(0, ios::end);
    dataFile.write((char *)&data, sizeof(StudentData));
}

bool FileOperation::allLog(vector<StudentData> & get) {
    vector<StudentData>().swap(get);
    auto * input = new StudentData();
    dataFile.seekg(0, ios::end);
    if (dataFile.tellg() == 0) {
        delete input;
        return false;
    }
    dataFile.clear();
    dataFile.seekg(0, ios::beg);
    while (dataFile.read((char *)input, sizeof(StudentData))) {
        get.push_back(*input);
    }
    delete input;
    return true;
}

bool FileOperation::getLog(int number, StudentData & data) {
    dataFile.seekg(number * (signed)sizeof(StudentData), ios::beg);
    dataFile.read((char *)&data, sizeof(StudentData));
    if (dataFile.eof()) {
        return false;
    }
    return true;
}

bool FileOperation::modifyLog(int number, const StudentData & data) {
    dataFile.seekg((number + 1) * (signed)sizeof(StudentData), ios::beg);
    if (dataFile.eof()) {
        return false;
    }
    dataFile.seekg(number * (signed)sizeof(StudentData), ios::beg);
    dataFile.write((char *)&data, sizeof(StudentData));

    return true;
}

bool FileOperation::deleteLog(int number) {
    vector<StudentData> temp;
    allLog(temp);
    if (number > temp.size() || number <= 0) {
        return false;
    }
    temp.erase(temp.begin() + number - 1);
    dataFile.close();
    dataFile.open("./StudentData.dat", ios::out | ios::binary | ios::trunc);
    dataFile.seekp(0, ios::beg);
    for (auto i : temp) {
        dataFile.write((char *)&i, sizeof(StudentData));
    }
    dataFile.close();
    dataFile.open("./StudentData.dat", ios::in | ios::out | ios::binary);
    return true;
}
