#ifndef SUDOKU_SUDOKUSOLVER_H
#define SUDOKU_SUDOKUSOLVER_H

#endif //SUDOKU_SUDOKUSOLVER_H
#include <string>

class SudokuSolver {
private:
    std::string initial_puzzle_;
    const std::string kLegalCharacters = "123456789_";
    const int kAcceptableSudokuSize = 81;
public:
    // required constructor
    bool IsValid(std::string &sudoku_problem);
    std::string Solve(std::string &sudoku_problem);
};