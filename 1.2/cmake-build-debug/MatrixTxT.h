//
// Created by Dima on 04.05.2019.
//

#ifndef INC_1_2_MATRIXTXT_H
#define INC_1_2_MATRIXTXT_H


#include <utility>

using std::pair;

class MatrixTxT {
private:
    static const int size = 3;

    bool CheckLine (int x);
    bool CheckColumn (int y);
    bool CheckMainDiag ();
    bool CheckAddDiag ();

public:
    int M [size][size]{};

    int getElem (int x, int y);

    pair<int,int> Check ();

};


#endif //INC_1_2_MATRIXTXT_H
