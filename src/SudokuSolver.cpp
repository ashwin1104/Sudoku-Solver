#include "SudokuSolver.h"
#include <iostream>


std::string SudokuSolver::Solve(std::string &sudoku_problem) {
    std::string sudoku_solution = sudoku_problem;
    if (!IsValid(sudoku_solution) || !SolveSudoku(sudoku_solution)) {
        return sudoku_problem;
    }
    return sudoku_solution;
}

bool SudokuSolver::IsValid(std::string &sudoku_solution) {
    if (sudoku_solution.length() != kAcceptableSudokuSize) {
        return false;
    }
    for (char& temp_char : sudoku_solution) {
        if (kLegalNumbers.find(temp_char) == std::string::npos && temp_char != '_') {
            return false;
        }
    }
    return true;
}

bool SudokuSolver::SolveSudoku(std::string &sudoku_solution) {
    int board_index;
    char temp_num;

    int first_num = 1;
    int last_num = 9;

    if (!FindUnassignedLocation(sudoku_solution, board_index)) {
        final_solution_ = sudoku_solution;
        return true;
    }
    for (int num = first_num; num <= last_num; num++) {
        temp_num = '0' + num;
        if (IsSafe(sudoku_solution, board_index, num)) {
            sudoku_solution[board_index] = temp_num;
            if (SolveSudoku(sudoku_solution)) {
                return true;
            }
            sudoku_solution[board_index] = '_';
        }
    }
    return false;
}

bool SudokuSolver::FindUnassignedLocation(std::string &sudoku_solution, int &board_index)
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

bool SudokuSolver::IsSafe(std::string &sudoku_solution, int board_index, int num) {
    int col = board_index % kNumCharsInRow;
    int row = (board_index - col)/kNumCharsInRow;
    return !UsedInRow(sudoku_solution, row, num) && !UsedInCol(sudoku_solution, col, num) &&
           !UsedInBox(sudoku_solution, row - row % 3 , col - col % 3, num);
}

bool SudokuSolver::UsedInRow(std::string &sudoku_solution, int row, int num) {
    int temp_num_at_index;
    int temp_char_index = 0;
    for (int col = 0; col < kNumCharsInRow; col++) {
        temp_char_index = (kNumCharsInRow * row) + col;
        temp_num_at_index = sudoku_solution[temp_char_index] - '0';

        if (temp_num_at_index == num) {
            return true;
        }

    }
    return false;
}

bool SudokuSolver::UsedInCol(std::string &sudoku_solution, int col, int num)
{
    int temp_num_at_index;
    int temp_char_index;
    for (int row = 0; row < kNumCharsInRow; row++) {
        temp_char_index = (kNumCharsInRow * row) + col;
        temp_num_at_index = sudoku_solution[temp_char_index] - '0';

        if (temp_num_at_index == num) {
            return true;
        }

    }
    return false;
}

bool SudokuSolver::UsedInBox(std::string &sudoku_solution, int box_start_row, int box_start_col, int num)
{
    int temp_num_at_index;
    int temp_char_index = 0;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            temp_char_index = (kNumCharsInRow * (row + box_start_row)) + col + box_start_col;
            temp_num_at_index = sudoku_solution[temp_char_index] - '0';

            if (temp_num_at_index == num) {
                return true;
            }

        }
    }
    return false;
}

void SudokuSolver::OutputSolution() {
    std::cout << *this << std::endl;
}
