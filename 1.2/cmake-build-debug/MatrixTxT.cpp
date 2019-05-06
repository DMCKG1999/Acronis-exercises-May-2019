#include "CMakeFiles/enum.h"
#include "MatrixTxT.h"

/* Если закоментировать строку ниже, то появятся распечатки,
 * которые использовались при отладке работы кода
 * */
#define PRINT

int MatrixTxT::setElem(int x, int y, int num) {
    /* Если x и y выходят за допустимый интервал,
     * то возвращаем WRONG_PARAMETER
     * */

    if (x < 0 || x >= MSIZE || y < 0 || y >= MSIZE) {
        return RET_ERROR::WRONG_PARAMETER;
    }

    // Иначе устанавливаем значение и возвращаем -1
    M[x][y] = num;
    return -1;
}

pair<int,int> MatrixTxT::Check() {
    // Чекаем все строки
    for (int i = 0; i < MSIZE; i++) {
        if (CheckLine(i)) {
#ifndef PRINT
            cout << "LINE" << endl;
            print();
#endif //PRINT
            return {CHECKED::LINE, i};
        }
    }

    // Чекаем все столбцы
    for (int i = 0; i < MSIZE; i++) {
        if (CheckColumn(i)) {
#ifndef PRINT
            cout << "COLUMN" << endl;
            print();
#endif //PRINT
            return {CHECKED::COLUMN, i};
        }
    }
    // Чекаем главную диагональ, а потом побочную
    if (CheckMainDiag()) {
#ifndef PRINT
        cout << "MDIAG" << endl;
        print();
#endif //PRINT
        return {CHECKED::MDIAG, 0};
    } else if (CheckAddDiag()) {
#ifndef PRINT
        cout << "ADIAG" << endl;
        print();
#endif //PRINT
        return {CHECKED::ADIAG, 0};
    } else return {-1, -1};
}

int MatrixTxT::CheckLine(int x) {
    /* Если x выходит за допустимый интервал,
     * то возвращаем WRONG_PARAMETER
     * */
    if (x < 0 || x >= MSIZE) {
        return RET_ERROR::WRONG_PARAMETER;
    }
    int elem = M[x][0];

    /* Если первый элемент равен нулю, то
     * проверка окончена и возвращаем false
     * */
    if (elem == 0) {
        return false;
    }

    /* Cравниваем первый элемент с остальными:
     * в случае победы должны все совпадать
     * */
    for (int i = 1; i < MSIZE; i++) {
        if (elem != M[x][i]) {
            return false;
        }
    }
    return true;
}

int MatrixTxT::CheckColumn(int y) {
    /* Если y выходит за допустимый интервал,
     * то возвращаем WRONG_PARAMETER
     * */
    if (y < 0 || y >= MSIZE) {
        return RET_ERROR::WRONG_PARAMETER;
    }

    int elem = M[0][y];

    /* Если первый элемент равен нулю, то
     * проверка окончена и возвращаем false
     * */
    if (elem == 0) {
        return false;
    }

    /* Cравниваем первый элемент с остальными:
     * в случае победы должны все совпадать
     * */
    for (int i = 1; i < MSIZE; i++) {
        if (elem != M[i][y]) {
            return false;
        }
    }
    return true;
}

bool MatrixTxT::CheckMainDiag() {
    int elem = M[0][0];

    /* Если первый элемент равен нулю, то
     * проверка окончена и возвращаем false
     * */
    if (elem == 0) {
        return false;
    }

    /* Cравниваем первый элемент с остальными:
     * в случае победы должны все совпадать
     * */
    for (int i = 1; i < MSIZE; i++) {
        if (elem != M[i][i]) {
            return false;
        }
    }
    return true;
}

bool MatrixTxT::CheckAddDiag() {
    int elem = M[0][MSIZE-1];

    /* Если первый элемент равен нулю, то
     * проверка окончена и возвращаем false
     * */
    if (elem == 0) {
        return false;
    }

    /* Cравниваем первый элемент с остальными:
     * в случае победы должны все совпадать
     * */
    for (int i = 1; i < MSIZE; i++) {
        if (elem != M[i][MSIZE-i-1]) {
            return false;
        }
    }
    return true;
}

void MatrixTxT::print() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
