#ifndef SUDOKU_SUDOKUSOLVER_H
#define SUDOKU_SUDOKUSOLVER_H

#endif //SUDOKU_SUDOKUSOLVER_H
#include <string>

//https://stackoverflow.com/questions/19022739/sudoku-solver-in-c
class SudokuSolver {
    private:
        const std::string kLegalCharacters = "123456789_";
        const int kAcceptableSudokuSize = 81;
        const int kNumCharsInRow = 9;
    public:
        // Returns whether or not the sudoku board is of legal length and has legal characters
        bool IsValid(std::string &sudoku_problem);
        // Returns the solution string, which will be the initial sudoku board if it is unsolvable
        std::string Solve(std::string &sudoku_problem);
        // Assigns values to all unassigned locations for Sudoku solution
        bool SolveSudoku(std::string &sudoku_solution);
        // Searches the grid to find an entry that is still unassigned.
        bool FindUnassignedLocation(std::string &sudoku_solution, int &board_index);
        // Returns whether it will be legal to assign num to the given row,col location.
        bool IsSafe(std::string &sudoku_solution, int board_index, int num);
        // Returns whether any assigned entry n the specified row matches the given number.
        bool UsedInRow(std::string &sudoku_solution, int row, int num);
        // Returns whether any assigned entry in the specified column matches the given number.
        bool UsedInCol(std::string &sudoku_solution, int col, int num);
        // Returns whether any assigned entry within the specified 3x3 box matches the given number
        bool UsedInBox(std::string &sudoku_solution, int boxStartRow, int boxStartCol, int num);
};