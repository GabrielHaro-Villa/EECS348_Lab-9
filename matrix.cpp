#include "matrix.hpp"
#include <fstream>
#include <iomanip>

// class member function definitions go here.
// you are allowed to reuse your definitions from lab 8 and modify them to take a template argument


template <typename T> // Constructor that initializes an NxN matrix with zeros
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs) const { // overload + operator for matrix addition
    if (rhs.get_size() != this->get_size()) { // checks if sizes are the same
        throw std::invalid_argument("Matrix sizes must be the same for addition."); // throws exception
    }
    Matrix<T> result(this->get_size()); // creates a new matrix
    for (std::size_t i = 0; i < size; ++i) // iterates through rows
        for (std::size_t j = 0; j < size; ++j) // iterates through columns
            result.set_value(i, j, this->get_value(i, j) + rhs.get_value(i, j)); // adds values
    return result; // returns the result
}

template <typename T> 
Matrix<T> Matrix<T>::operator*(const Matrix<T> &rhs) const { // overload * operator for matrix multiplication
    if (rhs.get_size() != this->get_size()) { // checks if sizes are the same
        throw std::invalid_argument("Matrix sizes must be the same for multiplication."); // throws exception
    }
    Matrix<T> result(this->get_size()); // creates a new matrix
    for (std::size_t i = 0; i < size; ++i) // iterates through rows
        for (std::size_t j = 0; j < size; ++j) // iterates through columns
            for (std::size_t k = 0; k < size; ++k) // iterates through inner
                result.set_value(i, j, result.get_value(i, j) + this->get_value(i, k) * rhs.get_value(k, j)); // multiplies values
    return result; // returns the result
}

// Explicit template instantiation for int and double
template class Matrix<int>;
template class Matrix<double>;

// Constructor that initializes an NxN matrix with zeros
template <typename T>
Matrix<T>::Matrix(std::size_t N) : data(N, std::vector<T>(N, 0)), size(N) {}

// Constructor that initializes the matrix with the provided 2D vector
template <typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> nums) : data(nums), size(nums.size()) {}

// Set a value at row i, column j
template <typename T>
void Matrix<T>::set_value(std::size_t i, std::size_t j, T n) { // set a value at row i, column j
    if (i >= size || j >= size) { // checks if indices are out of bounds
        throw std::out_of_range("Row or column index out of bounds."); // throws exception
    }
    data[i][j] = n; // sets the value
}

// Get a value from row i, column j
template <typename T>
T Matrix<T>::get_value(std::size_t i, std::size_t j) const { // get a value from row i, column j
    return data[i][j]; // returns the value
}


template <typename T>
int Matrix<T>::get_size() const { // get the size of the matrix
    return size; // returns the size
}

// Sum of the major diagonal
template <typename T>
int Matrix<T>::sum_diagonal_major() const {
    int sum = 0; // initialize sum to 0
    for (std::size_t i = 0; i < size; ++i) // iterate through rows
        sum += get_value(i, i); // add the diagonal value
    return sum; // return the sum
}

// Sum of the minor diagonal
template <typename T>
int Matrix<T>::sum_diagonal_minor() const {
    int sum = 0; // initialize sum to 0
    for (std::size_t i = 0; i < size; ++i) // iterate through rows
        sum += get_value(i, size - 1 - i); // add the diagonal value
    return sum; // return the sum
}

// Swap two rows in the matrix
template <typename T>
void Matrix<T>::swap_rows(std::size_t r1, std::size_t r2) {
    if (r1 >= size || r2 >= size) { // checks if indices are out of bounds
        throw std::out_of_range("Row indices out of bounds."); // throws exception
    }
    std::swap(data[r1], data[r2]); // swap the rows
}

// Swap two columns in the matrix
template <typename T>
void Matrix<T>::swap_cols(std::size_t c1, std::size_t c2) {
    if (c1 >= size || c2 >= size) { // checks if indices are out of bounds
        throw std::out_of_range("Column indices out of bounds."); // throws exception
    }
    for (std::size_t i = 0; i < size; ++i) // iterate through rows
        std::swap(data[i][c1], data[i][c2]); // swap the columns
}

// Print the matrix to the console
template <typename T>
void Matrix<T>::print_matrix() const {
    for (const auto& row : data) { // iterate through rows
        for (T val : row) // iterate through columns
            std::cout << std::setw(5) << val << " ";  // Fixed setw issue
        std::cout << std::endl; // print the row
    }
}