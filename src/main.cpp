#include <string>
#include <fstream>
#include "SudokuSolver.h"
#include "FileStream.h"

int main() {
    std::ifstream infile(FileStream::GetUserFile());
    std::string line;
    if (infile.is_open()) {
       FileStream::SolveAllProblems(infile, line);
    }
}