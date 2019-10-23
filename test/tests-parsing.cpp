#include <fstream>
#include "catch.hpp"
#include "FileStream.h"
#include "SudokuSolver.h"

// Valid .spf file tests
TEST_CASE("If the file does have '#spf1.0' as the first line, it is valid") {
    std::string user_file = "/Users/ashwinsaxena/CLionProjects/streamlined-sudoku-ashwin1104/src/ValidPuzzles.spf";
    std::string line;
    REQUIRE(FileStream::IsFileValid(user_file, line));
}
TEST_CASE("If the file does not have '#spf1.0' as the first line, it is invalid") {
    std::string user_file = "/Users/ashwinsaxena/CLionProjects/streamlined-sudoku-ashwin1104/src/NotSPF.spf";
    std::string line;
    REQUIRE(!FileStream::IsFileValid(user_file, line));
}
TEST_CASE("If the file path is an empty string, it is invalid") {
    std::string user_file = "";
    std::string line;
    REQUIRE(!FileStream::IsFileValid(user_file, line));
}

// SolveAllProblems tests
TEST_CASE("A valid file with multiple problems will output multiple solutions with SolveAllProblems") {
    std::ifstream infile("/Users/ashwinsaxena/CLionProjects/streamlined-sudoku-ashwin1104/src/ValidPuzzles.spf");
    std::string line;
    REQUIRE(FileStream::SolveAllProblems(infile, line)==
    "859612437723854169164379528986147352375268914241593786432981675617425893598736241"
    "714825936538469127692713845247958361853671294961234578176592483389147652425386719");
}
TEST_CASE("A valid file with no problems will output an empty string with SolveAllProblems") {
    std::ifstream infile("/Users/ashwinsaxena/CLionProjects/streamlined-sudoku-ashwin1104/src/EmptySPF.spf");
    std::string line;
    REQUIRE(FileStream::SolveAllProblems(infile, line).empty());
}

// Overloaded ifstream test
TEST_CASE("The overloaded ifstream will take in user input for a file path and "
          "instantiate a FileStream object's current file by doing so") {
    FileStream stream = FileStream();

    std::ofstream myfile;
    myfile.open("output.txt");
    myfile << "/Users/ashwinsaxena/CLionProjects/streamlined-sudoku-ashwin1104/src/EmptySPF.spf";
    myfile.close();

    std::ifstream infile("output.txt");
    infile >> stream;
    REQUIRE(stream.GetCurrentFile() ==
    "/Users/ashwinsaxena/CLionProjects/streamlined-sudoku-ashwin1104/src/EmptySPF.spf");
}

// Overloaded ofstream test
TEST_CASE("The overloaded ofstream will convert the raw solution to a pretty board design") {
    SudokuSolver sudoku = SudokuSolver();
    std::string board = "85___24__72______9__4_________1_7__23_5___9___4___________8__7__17__________36_4_";
    std::string temp_solution = sudoku.Solve(board);

    std::ofstream myfile;
    myfile.open("output.txt");
    myfile << sudoku;
    myfile.close();

    std::string line;
    std::string output;
    std::ifstream infile("output.txt");
    while (std::getline(infile, line)) {
        if (line.empty()) {
            break;
        }
        output += line;
    }
    REQUIRE(output == "+-----------------------+"
                      "| 8 5 9 | 6 1 2 | 4 3 7 |"
                      " | 7 2 3 | 8 5 4 | 1 6 9 |"
                      " | 1 6 4 | 3 7 9 | 5 2 8 |"
                      " +-----------------------+"
                      "| 9 8 6 | 1 4 7 | 3 5 2 |"
                      " | 3 7 5 | 2 6 8 | 9 1 4 |"
                      " | 2 4 1 | 5 9 3 | 7 8 6 |"
                      " +-----------------------+"
                      "| 4 3 2 | 9 8 1 | 6 7 5 |"
                      " | 6 1 7 | 4 2 5 | 8 9 3 | "
                      "| 5 9 8 | 7 3 6 | 2 4 1 |"
                      "+-----------------------+");
}