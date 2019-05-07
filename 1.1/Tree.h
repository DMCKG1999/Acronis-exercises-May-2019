#ifndef INC_1_1_TREE_H
#define INC_1_1_TREE_H

#include "Vertex.h"
#include <string>

using std::string;

/* Класс описывает структуру - Бор.
 * Эта модифицированная и, вероятно,
 * оптимизированная версия той структуры,
 * которая была в источнике:
 *
 * https://e-maxx.ru/algo/aho_corasick
 * */
class Tree{
public:

    // Корень Бора
    Vertex * Root = new Vertex;

    // Добавляет шаблоннуб строку в Бор
    int AddString (const string & s);

    /* Эти две функции взаимодействуют друг с другом.
     * Первая выдает вершину, в которую можно перейти
     * из _V по символу c, а вторая возвращает
     * суффиксную ссылку для вершины _V.
     * */
    Vertex * Go (Vertex * _V, char c);
    Vertex * Get_link (Vertex * _V);

    /* Функция, добавленная для того, чтобы
     * проверять есть ли шаблонные строки,
     * которые являются суффиксом строки,
     * соответствующей вершине V
     * (подробности в Vertex.h)
     * */
    bool SetLeaf(Vertex * V);

    // Вызывает Root->Print()
    void Print ();

    Tree() { Root->SetLeaf = true; }

    ~Tree();
};


#endif //INC_1_1_TREE_H
