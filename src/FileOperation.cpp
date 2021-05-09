//
// Created by JouderMin on 2021/5/9.
//

#include "FileOperation.h"

using std::ios;

FileOperation::FileOperation() {
    dataFile.open("./StudentData.dat", ios::in | ios::out | ios::binary);
    while (!dataFile) {
        std::system("type nul>cashdata.dat");
        dataFile.open("./StudentData.dat", ios::in | ios::out | ios::binary);
    }
}

FileOperation::~FileOperation() {
    dataFile.close();
}
