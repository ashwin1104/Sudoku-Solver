#ifndef SUDOKU_FILESTREAM_H
#define SUDOKU_FILESTREAM_H

#endif //SUDOKU_FILESTREAM_H

#include <iostream>

class FileStream {
    private:
        // Stores the file that the user initially inputs
        std::string user_file_;

        // Stores the initial sudoku problem
        std::string game_board_;

    public:
        // Default constructor
        FileStream();

        // Constructor used to initialize game_board_ with a sudoku problem
        explicit FileStream(std::string &sudoku_board);

        // Accepts the user's input file
        static std::string GetUserFile();

        // Checks if the input file is valid
        static bool IsFileValid(const std::string &file_name, std::string line);

        // Outputs solution for each problem statement in the given file
        //https://cpppatterns.com/patterns/read-line-by-line.html
        static std::string SolveAllProblems(std::ifstream &infile, std::string line);

        // istream override to read in user's file path
        //https://medium.com/@nonuruzun/overloading-input-output-operators-in-c-a2a74c5dda8a
        friend std::istream &operator>>(std::istream &in, FileStream &stream) {
            std::cout << "Input file path:" << std::endl;
            in >> stream.user_file_;
            return in;
        }
        std::string GetCurrentFile();
};