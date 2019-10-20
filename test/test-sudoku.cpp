#include "catch.hpp"
#include "main.cpp"

SudokuSolver sudoku;

TEST_CASE("Problem statement strings with less than the correct amount of characters will return the same string") {
    std::string temp_problem = "_";
    REQUIRE(temp_problem == sudoku.Solve(temp_problem));
}
TEST_CASE("Problem statement strings with an illegal character will return the same string") {
    std::string temp_problem = "85___24__72__.___9__4_________1_7__23_5___9___4___________8__7__17__________36_4_";
    REQUIRE(temp_problem == sudoku.Solve(temp_problem));
}
TEST_CASE("Problem statement strings with greater than the correct amount of characters will return the same string") {
    std::string temp_problem = "85___24__72______9__4_________1_7__23_5___9___4___________8__7__17__________36_4______";
    REQUIRE(temp_problem == sudoku.Solve(temp_problem));
}
TEST_CASE("Valid problem statement strings without the correct amount of characters will return the correct solution") {
    std::string temp_problem = "85___24__72______9__4_________1_7__23_5___9___4___________8__7__17__________36_4_";
    REQUIRE(temp_problem != sudoku.Solve(temp_problem));
}