#include "SudokuSolver.h"


bool SudokuSolver::IsValid(std::string &sudoku_problem) {
    if (sudoku_problem.length() != kAcceptableSudokuSize) {
        return false;
    }
    for (char& temp_char : sudoku_problem) {
        if (kLegalCharacters.find(temp_char) == std::string::npos) {
            return false;
        }
    }
    return true;
}

std::string SudokuSolver::Solve(std::string &sudoku_problem) {
    std::string sudoku_solution = sudoku_problem;
    return sudoku_solution;
}