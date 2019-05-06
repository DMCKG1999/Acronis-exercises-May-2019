#ifndef INC_1_2_DIRECT_SOLUTION_H
#define INC_1_2_DIRECT_SOLUTION_H

#include "cmake-build-debug/MatrixTxT.h"
#include <vector>

using std::vector;

/* Рекурсивная функция, которая по начальной
 * матрице (M), вектору пар координат незанятых
 * клеток (V) и номеру ходящего игрока (player)
 * выдает число возможных полей, достижимых из
 * этой позиции
 * */
int T(MatrixTxT M, vector <pair<int,int>> V, int player);

/* Оболочка для решения задачи, которая создает
 * и передает начальные параметры в функцию T
 * */
int dsol ();

#endif //INC_1_2_DIRECT_SOLUTION_H



