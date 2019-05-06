#ifndef INC_1_2_ERR_H
#define INC_1_2_ERR_H

// Константы, возвращаемые при ошибках
enum RET_ERROR {
    WRONG_PARAMETER
};

// Константы, возвращаемые при обнаружении победы последнего игрока
enum CHECKED {
    LINE, COLUMN, MDIAG, ADIAG
};

#endif //INC_1_2_ERR_H
