#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>
#include <iostream>

// modify this class declaration to take a template for the type of the data it holds

template <typename T>
class Matrix {
    public:
    Matrix(std::size_t N);  // Constructor that initializes an NxN matrix
    Matrix(std::vector<std::vector<T>> nums);  // Constructor with a vector of vectors

    Matrix<T> operator+(const Matrix<T> &rhs) const; // overload + operator for matrix addition
    Matrix<T> operator*(const Matrix<T> &rhs) const; // overload * operator for matrix multiplication
    void set_value(std::size_t i, std::size_t j, T n);  // Set a value at row i, column j
    T get_value(std::size_t i, std::size_t j) const;    // Get a value from row i, column j
    int get_size() const;  // Get the size of the matrix (NxN)
    int sum_diagonal_major() const;  // Sum of the major diagonal
    int sum_diagonal_minor() const;  // Sum of the minor diagonal
    void swap_rows(std::size_t r1, std::size_t r2);  // Swap two rows
    void swap_cols(std::size_t c1, std::size_t c2);  // Swap two columns
    void print_matrix() const;  // Print the matrix to the console
private:
    std::vector<std::vector<T>> data; // 2D vector to hold the matrix data
    std::size_t size; // size of the matrix (N)
};

#endif // __MATRIX_HPP__
