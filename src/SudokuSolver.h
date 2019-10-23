#ifndef SUDOKU_SUDOKUSOLVER_H
#define SUDOKU_SUDOKUSOLVER_H

#endif //SUDOKU_SUDOKUSOLVER_H
#include <iostream>
#include <string>

//https://stackoverflow.com/questions/19022739/sudoku-solver-in-c
class SudokuSolver {
    private:
        std::string final_solution_;
        const std::string kLegalNumbers = "123456789";
        const int kAcceptableSudokuSize = 81;
        const int kNumCharsInRow = 9;
    public:
        // Returns the solution string, which will be the initial sudoku board if it is unsolvable
        std::string Solve(std::string &sudoku_problem);

        // Returns whether or not the sudoku board is of legal length and has legal characters
        bool IsValid(std::string &sudoku_problem);

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
        bool UsedInBox(std::string &sudoku_solution, int box_start_row, int box_start_col, int num);

        // std::cout solution in pretty format
        void OutputSolution();

        // ostream override to output the solved or unsolved sudoku puzzle
        friend std::ostream &operator<<(std::ostream &out, SudokuSolver &sudoku) {
            std::string temp_line;
            out << "+-----------------------+" << std::endl;
            for (int i = 0; i < sudoku.final_solution_.length(); i++) {
                if (i % 3 == 0) {
                    temp_line += "| ";
                }
                if (i != 0 && i % 9 == 0) {
                    out << temp_line << std::endl;
                    temp_line = "| ";
                }
                if (i != 0 && i % 27 == 0) {
                    out << "+-----------------------+" << std::endl;
                }
                temp_line += sudoku.final_solution_[i];
                temp_line += " ";
            }
            temp_line += "|";
            out << temp_line << std::endl;
            out << "+-----------------------+" << std::endl;
            return out;
        }
};