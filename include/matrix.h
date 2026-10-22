#include <cstddef>
#include <new>        // для std::bad_alloc
#include <stdexcept>  // для std::invalid_argument

/**
 * @file matrix.h
 * @brief Бибилиотека для работы с матрицами.
 * @author Студент
 * @version v0.0.1
 */

/**
 * @brief Структура матрицы.
 *
 * Хранит двумерный динамический массив и его размеры.
 * @warning Память освобождается через free_matrix().
 */

#ifndef MATRIX_H
#define MATRIX_H
typedef struct {
  double** data;  ///< Указатель на двумерный массив данных.
  int rows;       ///< Количество строк в матрице.
  int cols;       ///< Количество столбцов в матрице.
} Matrix;

/**
 * @brief Создание матрицы заданного размера.
 *
 * @param rows Количество строк (>0)
 * @param cols Количество столбцов (> 0).
 * @return Matrix Инициализированная нулями матрица.
 *
 * @exception std::invalid_argument Если rows <= 0 или cols <= 0.
 * @exception std::bad_alloc Если не удалось выделить память.
 *
 * @note Время выполнения: O(rows * cols).
 * @see free_matrix()
 *
 * @code
 * Matrix A = create_matrix(3, 3);
 * @endcode
 */
// Создание и освобождение
Matrix create_matrix(int rows, int cols);  // С выделением памяти
void free_matrix(Matrix m);                // Без утечек памяти
// Базовые операции
Matrix matrix_add(Matrix a, Matrix b);  // Сложение

/**
 * @brief Умножение двух матриц.
 *
 * @param a Матрица M×N.
 * @param b Матрица N×K.
 * @return Matrix Результат M×K.
 *
 * @exception std::invalid_argument Если cols(a) != rows(b).
 *
 * @note Время выполнения: O(M*N*K).
 * @warning Результат нужно освобождать через free_matrix()
 */
Matrix matrix_multiply(Matrix a, Matrix b);  // Умножение
// Вспомогательные
void print_matrix(Matrix m);                                 // Вывод
Matrix matrix_from_array(double* data, int rows, int cols);  // Инициализация из массив

double matrix_determinant_2x2(Matrix m);
#endif