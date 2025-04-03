#include <iostream>
#include <fstream>
#include "matrix.hpp"

int main(int argc, char *argv[]) {
    std::string filename; // string for the filename
    
    std::cout << "Enter the filename: "; // prompt user for filename
    std::cin >> filename; // read filename from user
    
    std::ifstream file(filename); // open the file
    if (!file) { // check if file opened successfully
        std::cerr << "Error opening file." << std::endl; // print error message
        return 1; // exit with error
    }
    
    int N, type; // read the size of the matrix and type from the file
    file >> N >> type; // read the size and type from the file

    // Declare the matrices here
    Matrix<int>* A_int = nullptr;
    Matrix<int>* B_int = nullptr;
    Matrix<double>* A_double = nullptr;
    Matrix<double>* B_double = nullptr;

    if (type == 0) {
        // Integer matrix
        A_int = new Matrix<int>(N);
        B_int = new Matrix<int>(N);

        // Read matrices from file
        for (int i = 0; i < N; ++i) { // sets first lines of N values to matrix A
            for (int j = 0; j < N; ++j) {
                int value;
                file >> value;
                A_int->set_value(i, j, value);
            }
        }
        for (int i = 0; i < N; ++i) { // sets rest of values to matrix B
            for (int j = 0; j < N; ++j) {
                int value;
                file >> value;
                B_int->set_value(i, j, value);
            }
        }

        std::cout << "Matrix A:" << std::endl; // prints matrix A
        A_int->print_matrix();

        std::cout << "Matrix B:" << std::endl; // prints matrix B
        B_int->print_matrix();

        // Perform matrix operations using the overloaded + and * operators
        Matrix<int> C = *A_int + *B_int;  // Using the overloaded + operator
        std::cout << "Sum of A and B:" << std::endl;
        C.print_matrix();

        Matrix<int> D = *A_int * *B_int;  // Using the overloaded * operator
        std::cout << "Product of A and B:" << std::endl;
        D.print_matrix();

        std::cout << "Sum of major diagonal: " << A_int->sum_diagonal_major() << std::endl;
        std::cout << "Sum of minor diagonal: " << A_int->sum_diagonal_minor() << std::endl;

    } else if (type == 1) {
        // Double matrix
        A_double = new Matrix<double>(N);
        B_double = new Matrix<double>(N);

        // Read matrices from file
        for (int i = 0; i < N; ++i) { // sets first N lines of values to matrix A
            for (int j = 0; j < N; ++j) {
                double value;
                file >> value;
                A_double->set_value(i, j, value);
            }
        }
        for (int i = 0; i < N; ++i) { // sets rest of values to matrix B
            for (int j = 0; j < N; ++j) {
                double value;
                file >> value;
                B_double->set_value(i, j, value);
            }
        }

        std::cout << "Matrix A:" << std::endl;
        A_double->print_matrix(); // prints matrix A

        std::cout << "Matrix B:" << std::endl;
        B_double->print_matrix(); // prints matrix B

        // Perform matrix operations using the overloaded + and * operators
        Matrix<double> C = *A_double + *B_double;  // Using the overloaded + operator
        std::cout << "Sum of A and B:" << std::endl;
        C.print_matrix(); // prints sum of A and B

        Matrix<double> D = *A_double * *B_double;  // Using the overloaded * operator
        std::cout << "Product of A and B:" << std::endl;
        D.print_matrix(); // prints product of A and B

        std::cout << "Sum of major diagonal: " << A_double->sum_diagonal_major() << std::endl;
        std::cout << "Sum of minor diagonal: " << A_double->sum_diagonal_minor() << std::endl;
    } else {
        std::cerr << "Invalid type flag in file. Must be 0 (int) or 1 (double)." << std::endl;
        return 1;
    }

    // Now we ask the user for swaps, which are independent of matrix type
    if (type == 0) {
        std::cout << "Enter two row indices to swap (0-indexed): ";
        int r1, r2;
        std::cin >> r1 >> r2;
        A_int->swap_rows(r1, r2); // swap rows
        // prints matrix A after swapping rows
        std::cout << "Matrix A after swapping rows " << r1 << " and " << r2 << ":" << std::endl;
        A_int->print_matrix();

        std::cout << "Enter two column indices to swap (0-indexed): ";
        int c1, c2;
        std::cin >> c1 >> c2;
        A_int->swap_cols(c1, c2); // swap columns
        // prints matrix A after swapping columns
        std::cout << "Matrix A after swapping columns " << c1 << " and " << c2 << ":" << std::endl;
        A_int->print_matrix();

    } else if (type == 1) { // double matrix
        std::cout << "Enter two row indices to swap (0-indexed): ";
        int r1, r2;
        std::cin >> r1 >> r2;
        A_double->swap_rows(r1, r2); // swap rows
        // prints matrix A after swapping rows
        std::cout << "Matrix A after swapping rows " << r1 << " and " << r2 << ":" << std::endl;
        A_double->print_matrix();

        std::cout << "Enter two column indices to swap (0-indexed): ";
        int c1, c2;
        std::cin >> c1 >> c2;
        A_double->swap_cols(c1, c2); // swap columns
        // prints matrix A after swapping columns
        std::cout << "Matrix A after swapping columns " << c1 << " and " << c2 << ":" << std::endl;
        A_double->print_matrix();
    }

    std::cout << "Enter a row index, column index, and value to set (0-indexed): ";
    int row, col, value;
    std::cin >> row >> col >> value;
    if (type == 0) {
        A_int->set_value(row, col, value); // set value in matrix A if matrix is int
        std::cout << "Matrix A after setting value at (" << row << ", " << col << ") to " << value << ":" << std::endl;
        A_int->print_matrix();
    } else if (type == 1) {
        A_double->set_value(row, col, value); // set value in matrix A if matrix is double
        std::cout << "Matrix A after setting value at (" << row << ", " << col << ") to " << value << ":" << std::endl;
        A_double->print_matrix();
    }

    return 0;
}
