#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void processInput() {
    std::string input;
    std::cin >> input;

    // Example of extracting matrix dimensions and creating a matrix
    int rows = 0, cols = 0;

    // Parse the input string to find dimensions
    for (char c : input) {
        if (isdigit(c)) {
            if (rows == 0) {
                rows = c - '0'; // assuming first digit is rows
            } else {
                cols = c - '0'; // assuming second digit is cols
            }
        }
    }

    // Create a matrix with the specified dimensions
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));
    
    // Fill the matrix with example values for testing
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = i * cols + j + 1; // Fill with sequential numbers
        }
    }

    // Output the dimensions and the matrix
    std::cout << "Matrix dimensions: " << rows << " x " << cols << std::endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    processInput(); // Call the process function
    return 0; // Indicate successful program execution
}

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        
        TEST_METHOD(TestMethod1)
        {
            // Redirect output
            std::stringstream buffer;
            std::streambuf* oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());

            // Input for the test
            const char* testInput = "3abc5def";
            std::cin.rdbuf(std::istringstream(testInput).rdbuf()); // Redirect input

            // Call the main function to run the program logic
            main();

            // Restore standard output
            std::cout.rdbuf(oldCoutBuffer);

            // Check the output
            std::string output = buffer.str();

            Assert::IsTrue(output.find("Matrix dimensions: 3x5") != std::string::npos, L"Matrix dimensions are incorrect.");

            Assert::IsTrue(output.find(" 1 ") != std::string::npos, L"Matrix does not start with 1.");
            Assert::IsTrue(output.find(" 6 ") != std::string::npos, L"Matrix does not contain the number 6.");
            Assert::IsTrue(output.find(" 12 ") != std::string::npos, L"Matrix does not contain the number 12.");
        }
    };
}
