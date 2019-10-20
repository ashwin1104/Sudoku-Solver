#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class SudokuSolver {
private:
    std::string initial_puzzle;
public:
    // required constructor
    SudokuSolver() {

    }
    std::string Solve(std::string &sudoku_problem) {
        std::string sudoku_solution = sudoku_problem;
        return sudoku_solution;
    }
};
int main(int argc, char *argv[]) {
    SudokuSolver sudoku;
    std::ifstream infile("thefile.txt");
    std::string line;
    //https://cpppatterns.com/patterns/read-line-by-line.html
    while (std::getline(infile, line))
    {
        std::istringstream stream(line);
        std::string temp_sudoku_unsolved;
        if (!(stream >> temp_sudoku_unsolved)) {
            break;
        }
        std::string sudoku_solution = sudoku.Solve(temp_sudoku_unsolved);
        std::cout << sudoku_solution << std::endl;
    }
}