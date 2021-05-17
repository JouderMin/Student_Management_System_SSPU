//
// Created by JouderMin on 2021/5/9.
//

#ifndef STUDENT_MANAGEMENT_SYSTEM_SSPU_FILEOPERATION_H
#define STUDENT_MANAGEMENT_SYSTEM_SSPU_FILEOPERATION_H

#include "StudentData.h"
#include <fstream>
#include <vector>

class FileOperation {
  public:
    // 构造函数与构析函数
    FileOperation();
    ~FileOperation();

    // 文件操作接口
    void addLog(const StudentData & data);
    bool deleteLog(int number);
    bool modifyLog(int number, const StudentData & data);
    bool allLog(std::vector<StudentData> & get);
    bool getLog(int number, StudentData & data);

  private:
    std::fstream dataFile;
};

#endif // STUDENT_MANAGEMENT_SYSTEM_SSPU_FILEOPERATION_H
