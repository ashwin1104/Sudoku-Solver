#include <fstream>
#include "catch.hpp"
#include "FileStream.h"

// Valid .spf file tests
TEST_CASE("If the file does not have '#spf1.0' as the first line, it is invalid") {
    std::string user_file = "/Users/ashwinsaxena/CLionProjects/streamlined-sudoku-ashwin1104/src/ValidPuzzles.spf";
    std::string line;
    REQUIRE(FileStream::IsFileValid(user_file, line));
}