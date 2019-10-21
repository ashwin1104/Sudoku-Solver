#include "catch.hpp"
#include "SudokuSolver.h"

SudokuSolver sudoku = SudokuSolver();

// SudokuSolver IsValid method tests
TEST_CASE("Problem statement strings that are empty are invalid") {
    std::string temp_problem;
    REQUIRE(!sudoku.IsValid(temp_problem));
}
TEST_CASE("Problem statement strings with length less than the correct amount of characters are invalid") {
    std::string temp_problem = "_";
    REQUIRE(!sudoku.IsValid(temp_problem));
}
TEST_CASE("Problem statement strings with length greater than the correct amount of characters are invalid") {
    std::string temp_problem = "85___24__72______9__4_________1_7__23_5___9___4___________8__7__17__________36_4______";
    REQUIRE(!sudoku.IsValid(temp_problem));
}
TEST_CASE("Problem statement strings with illegal characters are invalid") {
    std::string temp_problem = "85___24__72__.___9__4_________1_7__23_5___9___4___________8__7__17__________36_4_";
    REQUIRE(!sudoku.IsValid(temp_problem));
}
TEST_CASE("Problem statement strings with the correct amount of characters are valid") {
    std::string temp_problem = "85___24__72______9__4_________1_7__23_5___9___4___________8__7__17__________36_4_";
    REQUIRE(sudoku.IsValid(temp_problem));
}

// SudokuSolver FindUnassignedLocation method tests
TEST_CASE("FindUnassignedLocation should update the current unassigned location") {
    std::string temp_problem = "85___24__72______9__4_________1_7__23_5___9___4___________8__7__17__________36_4_";
    int current_unassigned_location = -1;
    sudoku.FindUnassignedLocation(temp_problem, current_unassigned_location);
    REQUIRE(current_unassigned_location == 2);
}
TEST_CASE("Problem statement strings with at least one underscore will have unassigned location(s)") {
    std::string temp_problem = "85___24__72______9__4_________1_7__23_5___9___4___________8__7__17__________36_4_";
    int current_unassigned_location = -1;
    REQUIRE(sudoku.FindUnassignedLocation(temp_problem, current_unassigned_location));
}
TEST_CASE("Problem statement strings with no underscores will not have an unassigned location") {
    std::string temp_problem = "851112411721111119114111111111117112315111911141111111111181171117111111111136141";
    int current_unassigned_location = -1;
    REQUIRE(!sudoku.FindUnassignedLocation(temp_problem, current_unassigned_location));
}

// SudokuSolver UsedInRow method tests
TEST_CASE("If a given number exists in a given row, UsedInRow returns true") {
    std::string temp_problem = "851112411721111119114111111111117112315111911141111111111181171117111111111136141";
    REQUIRE(sudoku.UsedInRow(temp_problem, 0, 1));
}
TEST_CASE("If a given number does not exist in a given row, UsedInRow returns false") {
    std::string temp_problem = "851142411721111119114111111111117112315111911141111111111181171117111111111136141";
    REQUIRE(!sudoku.UsedInRow(temp_problem, 0, 3));
}

// SudokuSolver UsedInCol method tests
TEST_CASE("If a given number exists in a given col, UsedInCol returns true") {
    std::string temp_problem = "851132411711111119114111111111117112311111911141111111111181171117111111111136141";
    REQUIRE(sudoku.UsedInCol(temp_problem, 1, 5));
}
TEST_CASE("If a given number does not exist in a given col, UsedInCol returns false") {
    std::string temp_problem = "851132411721111119114111111111117112315111911141111111111181171117111111111136141";
    REQUIRE(!sudoku.UsedInCol(temp_problem, 0, 5));
}

// SudokuSolver UsedInBox method tests
TEST_CASE("If a given number exists in a given box, UsedInBox returns true") {
    std::string temp_problem = "851235411711111119114111111111117112311111911141111111111181171117111111111136141";
    REQUIRE(sudoku.UsedInBox(temp_problem, 0, 0, 5));
}
TEST_CASE("If a given number does not exist in a given box, UsedInBox returns false") {
    std::string temp_problem = "851132411721111119114111111111117112315111911141111111111181171117111111111136141";
    REQUIRE(!sudoku.UsedInBox(temp_problem, 6, 6, 5));
}

// SudokuSolver Solve method tests
TEST_CASE("Returns the correct solution of a valid problem") {
    std::string temp_problem = "85___24__72______9__4_________1_7__23_5___9___4___________8__7__17__________36_4_";
    std::string temp_solution = sudoku.Solve(temp_problem);
    REQUIRE("859612437723854169164379528986147352375268914241593786432981675617425893598736241" == temp_solution);
}
TEST_CASE("An unsolvable problem statement is returned") {
    std::string temp_problem = "5168497323_76_5___8_97___65135_6_9_7472591__696837__5_253186_746842_75__791_5_6_8";
    std::string temp_solution = sudoku.Solve(temp_problem);
    REQUIRE(temp_problem == temp_solution);
}