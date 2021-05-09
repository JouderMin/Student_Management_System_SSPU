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
    void addLog(const StudentData & data);
    bool deleteLog(int number);
    bool modifyLog(int number, const StudentData & data);
    std::vector<StudentData> allLog();
    StudentData getLog(int number);

  private:
    std::fstream File;
    bool rangeCheck();
};

#endif // STUDENT_MANAGEMENT_SYSTEM_SSPU_FILEOPERATION_H
