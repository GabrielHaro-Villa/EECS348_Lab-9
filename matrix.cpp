#include "matrix.hpp"
#include <fstream>
#include <iomanip>

// class member function definitions go here.
// you are allowed to reuse your definitions from lab 8 and modify them to take a template argument


template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs) const {
    if (rhs.get_size() != this->get_size()) {
        throw std::invalid_argument("Matrix sizes must be the same for addition.");
    }
    Matrix<T> result(this->get_size());
    for (std::size_t i = 0; i < size; ++i)
        for (std::size_t j = 0; j < size; ++j)
            result.set_value(i, j, this->get_value(i, j) + rhs.get_value(i, j));
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &rhs) const {
    if (rhs.get_size() != this->get_size()) {
        throw std::invalid_argument("Matrix sizes must be the same for multiplication.");
    }
    Matrix<T> result(this->get_size());
    for (std::size_t i = 0; i < size; ++i)
        for (std::size_t j = 0; j < size; ++j)
            for (std::size_t k = 0; k < size; ++k)
                result.set_value(i, j, result.get_value(i, j) + this->get_value(i, k) * rhs.get_value(k, j));
    return result;
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
void Matrix<T>::set_value(std::size_t i, std::size_t j, T n) {
    data[i][j] = n;
}

// Get a value from row i, column j
template <typename T>
T Matrix<T>::get_value(std::size_t i, std::size_t j) const {
    return data[i][j];
}

// Get the size of the matrix
template <typename T>
int Matrix<T>::get_size() const {
    return size;
}

// Sum of the major diagonal
template <typename T>
int Matrix<T>::sum_diagonal_major() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i)
        sum += get_value(i, i);
    return sum;
}

// Sum of the minor diagonal
template <typename T>
int Matrix<T>::sum_diagonal_minor() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i)
        sum += get_value(i, size - 1 - i);
    return sum;
}

// Swap two rows in the matrix
template <typename T>
void Matrix<T>::swap_rows(std::size_t r1, std::size_t r2) {
    if (r1 >= size || r2 >= size)
        throw std::out_of_range("Row indices out of bounds.");
    std::swap(data[r1], data[r2]);
}

// Swap two columns in the matrix
template <typename T>
void Matrix<T>::swap_cols(std::size_t c1, std::size_t c2) {
    if (c1 >= size || c2 >= size)
        throw std::out_of_range("Column indices out of bounds.");
    for (std::size_t i = 0; i < size; ++i)
        std::swap(data[i][c1], data[i][c2]);
}

// Print the matrix to the console
template <typename T>
void Matrix<T>::print_matrix() const {
    for (const auto& row : data) {
        for (T val : row)
            std::cout << std::setw(5) << val << " ";  // Fixed setw issue
        std::cout << std::endl;
    }
}