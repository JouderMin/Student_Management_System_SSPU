cmake_minimum_required(VERSION 3.0.0)
project(Exp4 VERSION 0.1.0)

include(CTest)
enable_testing()
set(CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED True)
aux_source_directory(src/ sourceList)
add_executable(Student_Management_System_SSPU ${sourceList})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
