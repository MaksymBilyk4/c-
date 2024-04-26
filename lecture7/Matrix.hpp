#pragma once

#include <vector>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <type_traits>
#include <utility>


template<typename T>
struct Matrix {

    Matrix(std::vector<std::vector<T>> const &matrix) : matrix(matrix) {}

    Matrix(int rows, int columns, T initValue) :
            matrix(std::vector<std::vector<T>>(rows, std::vector<T>(columns, initValue))) {}

    Matrix(Matrix<T> const &mat) : matrix(mat) {}

    auto getColumnsCount() const -> int {
        return matrix.empty() ? 0 : matrix[0].size();
    }

    auto getRowsCount() const -> int {
        return matrix.size();
    }

    auto getMatrix() const -> std::vector<std::vector<T>> {
        return matrix;
    }

    auto getDimension() const -> std::pair<T, T> {
        return {this->getRowsCount(), this->getColumnsCount()};
    }

    auto printFormattedMatrix() -> void {
        fmt::println("");
        for (auto &row: matrix)
            fmt::println("|  {}  |", fmt::join(row, "  "));
    }

    auto transpose() -> void {
        auto transposedMatrix = std::vector<std::vector<T>>(getColumnsCount(), std::vector<T>(getRowsCount(), 0));

        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                transposedMatrix[j][i] = matrix[i][j];


        matrix = transposedMatrix;
    }

    auto operator=(Matrix<T> const &another) -> void {
        matrix = another.getMatrix();
    }

    template<typename U>
    auto operator+(Matrix<U> &another) -> Matrix<typename std::common_type<T, U>::type> {
        auto resultMatrix = std::vector<std::vector<typename std::common_type<T, U>::type>>(another.getRowsCount(), std::vector<typename std::common_type<T, U>::type>(another.getColumnsCount(), 0));

        if (another.getRowsCount() != this->getRowsCount() || another.getColumnsCount() != this->getColumnsCount()) {
            throw std::runtime_error("Matrix dimensions must match");
        }

        for (int i = 0; i < another.getRowsCount(); i++)
            for (int j = 0; j < another.getColumnsCount(); j++)
                resultMatrix[i][j] = matrix[i][j] + another.getMatrix()[i][j];

        return {resultMatrix};
    }

    template<typename U>
    auto operator-(Matrix<U> const &another) -> Matrix<typename std::common_type<T, U>::type> {
        if (another.getRowsCount() != this->getRowsCount() || another.getColumnsCount() != this->getColumnsCount()) {
            throw std::runtime_error("Matrix dimensions must match");
        }

        auto resultMatrix = std::vector<std::vector<typename std::common_type<T, U>::type>>(another.getRowsCount(), std::vector<typename std::common_type<T, U>::type>(another.getColumnsCount(), 0));

        for (int i = 0; i < another.getRowsCount(); i++)
            for (int j = 0; j < another.getColumnsCount(); j++)
                resultMatrix[i][j] = matrix[i][j] - another.getMatrix()[i][j];

        return {resultMatrix};
    }

    template<typename U>
    auto operator*(Matrix<U> const &another) -> Matrix<typename std::common_type<T, U>::type> {
        if (this->getColumnsCount() != another.getRowsCount())
            throw std::runtime_error("Columns of first matrix should be equals to rows of second matrix");

        auto resultMatrix = std::vector<std::vector<typename std::common_type<T, U>::type>>(this->getRowsCount(), std::vector<typename std::common_type<T, U>::type>(another.getColumnsCount(), 0));

        for (int i = 0; i < this->getRowsCount(); i++)
            for (int j = 0; j < this->getColumnsCount(); j++)
                for (int k = 0; k < another.getColumnsCount(); k++)
                    resultMatrix[i][k] += matrix[i][j] * another.getMatrix()[j][k];


        return {resultMatrix};
    }


private:
    std::vector<std::vector<T>> matrix;
};
