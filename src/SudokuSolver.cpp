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
    if (!IsValid(sudoku_problem)) {
        return sudoku_problem;
    }
    std::string sudoku_solution = sudoku_problem;
    int board_index = 0;
    if (!SolveSudoku(sudoku_solution)) {
        return sudoku_problem;
    }
    return sudoku_solution;
}

bool SudokuSolver::SolveSudoku(std::string sudoku_solution) {
    int board_index;
    if (!FindUnassignedLocation(sudoku_solution, board_index)) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (IsSafe(sudoku_solution, board_index, num)) {
            sudoku_solution[board_index] = num;
            if (SolveSudoku(sudoku_solution)) {
                return true;
            }
            sudoku_solution[board_index] = '_';
        }
    }
    return false;
}

bool SudokuSolver::FindUnassignedLocation(std::string sudoku_solution, int &board_index)
{
    int temp_char_index = 0;
    for (int row = 0; row < kNumCharsInRow; row++) {
        for (int col = 0; col < kNumCharsInRow; col++) {
            temp_char_index = (kNumCharsInRow * row) + col;
            if (sudoku_solution[temp_char_index] == '_') {
                board_index = (row * kNumCharsInRow) + col;
                return true;
            }
        }
    }
    return false;
}

bool SudokuSolver::UsedInRow(std::string sudoku_solution, int row, int num) {
    int temp_char_index = 0;
    for (int col = 0; col < ; col++) {
        temp_char_index = (kNumCharsInRow * row) + col;
        if (sudoku_solution[temp_char_index] == num) {
            return true;
        }
    }
    return false;
}

bool SudokuSolver::UsedInCol(std::string sudoku_solution, int col, int num)
{
    int temp_char_index = 0;
    for (int row = 0; row < kNumCharsInRow; row++) {
        temp_char_index = (kNumCharsInRow * row) + col;
        if (sudoku_solution[temp_char_index] == num) {
            return true;
        }
    }
    return false;
}

bool SudokuSolver::UsedInBox(std::string sudoku_solution, int boxStartRow, int boxStartCol, int num)
{
    int temp_char_index = 0;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            temp_char_index = (kNumCharsInRow * row) + col;
            if (sudoku_solution[temp_char_index] == num) {
                return true;
            }
        }
    }
    return false;
}

bool SudokuSolver::IsSafe(std::string sudoku_solution, int board_index, int num) {
    int col = board_index % kNumCharsInRow;
    int row = (board_index - col)/kNumCharsInRow;
    return !UsedInRow(sudoku_solution, row, num) && !UsedInCol(sudoku_solution, col, num) &&
           !UsedInBox(sudoku_solution, row - row % 3 , col - col % 3, num);
}