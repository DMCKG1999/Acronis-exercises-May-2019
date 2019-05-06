#ifndef INC_1_2_MATRIXTXT_H
#define INC_1_2_MATRIXTXT_H

#include <iostream>

using std::pair;
using std::cout;
using std::endl;

// Размер матрицы
static const int MSIZE = 3;

class MatrixTxT {
private:

    // Матрица
    int M [MSIZE][MSIZE]{};

    /* Вспомогательные функции; каждая из них чекает
     * некоторое множество элементов матрицы на предмет
     * совпадения всех элементов (и проверяет, что они
     * не равны нулю)
     * */
    int CheckLine (int x);
    int CheckColumn (int y);
    bool CheckMainDiag ();
    bool CheckAddDiag ();

public:

    // Setter
    int setElem (int x, int y, int num);

    /* Функция проверяет наличие столбца, строки
     * или диагонали (главной, побочной) с
     * одинаковыми числами, не равными нулю.
     *
     * Вовращаемое значение: пара (-1, -1),
     * если не найдено, иначе: первый int
     * отвечает за сработавший чекер (см.
     * enum.h -> CHECKED), а второй равен
     * номеру строки или столбца в соответсвующих
     * случаях или нулю в остальных.
     * */
    pair<int,int> Check ();

    // Печатает матрицу
    void print();
};


#endif //INC_1_2_MATRIXTXT_H
