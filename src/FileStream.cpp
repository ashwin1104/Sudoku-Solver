#include <string>
#include <iostream>
#include <fstream>
#include "FileStream.h"
#include "SudokuSolver.h"

FileStream::FileStream() = default;

FileStream::FileStream(std::string &sudoku_board) {
    game_board_ = sudoku_board;
}

std::string FileStream::GetUserFile() {
    FileStream stream = FileStream();
    std::cin >> stream;
    std::string line;
    if (IsFileValid(stream.user_file_, line)) {
        std::cout << "Using requested file path..." << std::endl;
        return stream.user_file_;
    }
    std::cout << "The file requested is not a valid .spf file. Using default file path..." << std::endl;
    return "/Users/ashwinsaxena/CLionProjects/streamlined-sudoku-ashwin1104/src/ValidPuzzles.spf";
}

bool FileStream::IsFileValid(const std::string &file_name, std::string line) {
    std::ifstream infile(file_name);
    std::getline(infile, line);
    if (line != "#spf1.0") {
        std::cout << "This file is of type " + line + ", not #spf1.0" << std::endl;
        return false;
    }
    return true;
}

std::string FileStream::SolveAllProblems(std::ifstream &infile, std::string line) {
    std::getline(infile, line);
    SudokuSolver sudoku = SudokuSolver();
    std::string raw_output;
    while (std::getline(infile, line)) {
        if (line.empty()) {
            break;
        }
        std::string temp_solution = sudoku.Solve(line);
        sudoku.OutputSolution();
        raw_output += temp_solution;
    }
    infile.close();
    return raw_output;
}

std::string FileStream::GetCurrentFile(){
    return user_file_;
}






