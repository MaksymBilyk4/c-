cmake_minimum_required(VERSION 3.27)
project(C__)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)


add_executable(Main lecture2/iterators/fast.cpp)
add_executable(WordReverse core/reversing_words.cpp)
add_executable(FmtPrinting core/fmt_printing.cpp)
add_executable(Cw2 lecture2/tasks_cw_v2/task.cpp)
add_executable(Lec3 lecture3/lecture3.cpp)
add_executable(Comp lecture3/comparators.cpp)
add_executable(Pred lecture3/lambdas_predicators.cpp)

target_link_libraries(Main fmt)
target_link_libraries(WordReverse fmt)
target_link_libraries(FmtPrinting fmt)
target_link_libraries(Cw2 fmt)
target_link_libraries(Lec3 fmt)
target_link_libraries(Comp fmt)
target_link_libraries(Pred fmt)