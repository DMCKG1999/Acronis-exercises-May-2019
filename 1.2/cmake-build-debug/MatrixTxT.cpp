//
// Created by Dima on 04.05.2019.
//

#include "MatrixTxT.h"
#include "CMakeFiles/enum.h"

int MatrixTxT::getElem(int x, int y) {
    if (x > size || x < 0 || y > 3 || y < 0) {
        return RET_ERROR::WRONG_PARAMETER;
    } else {
        return M[x][y];
    }
}

pair<int,int> MatrixTxT::Check() {
    for (int i = 0; i < size; i++) {
        if (CheckLine(i)) {
            return {CHECKED::LINE, i};
        }
    }
    for (int i = 0; i < size; i++) {
        if (CheckColumn(i)) {
            return {CHECKED::COLUMN, i};
        }
    }
    if (CheckMainDiag()) {
        return {CHECKED::MDIAG, 0};
    } else if (CheckAddDiag()) {
        return {CHECKED::ADIAG, 0};
    } else return {-1, -1};
}

bool MatrixTxT::CheckLine(int x) {
    int elem = M[x][0];
    for (int i = 1; i < size; i++) {
        if (elem != M[x][i]) {
            return false;
        }
    }
    return true;
}

bool MatrixTxT::CheckColumn(int y) {
    int elem = M[0][y];
    for (int i = 1; i < size; i++) {
        if (elem != M[i][y]) {
            return false;
        }
    }
    return true;
}

bool MatrixTxT::CheckMainDiag() {
    int elem = M[0][0];
    for (int i = 1; i < size; i++) {
        if (elem != M[i][i]) {
            return false;
        }
    }
    return true;
}

bool MatrixTxT::CheckAddDiag() {
    int elem = M[0][size-1];
    for (int i = 1; i < size; i++) {
        if (elem != M[i][size-i-1]) {
            return false;
        }
    }
    return true;
}
