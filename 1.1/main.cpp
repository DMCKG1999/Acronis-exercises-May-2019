#include "Tree.h"
#include <queue>
#include <iomanip>

using std::cin;
using std::endl;
using std::queue;
using std::setw;

int main(int argc, char* argv[]) {
    // Объявляем Бор
    Tree T  = Tree();

    // Инициализируем его
    for (int i = 1; i < argc; i++) {
        T.AddString(argv[i]);
    }

    string str;
    Vertex * V = T.Root;

    while(cin >> str) {
        bool exit = false;
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];

            // Если дошли до конца файла, то выходим
            if (c == EOF) {
                exit = true;
                break;
            }

            // Выводим элемент
            cout << c;

            // Делаем переход по нему
            V = T.Go(V,c);

            /* Если до этого не проверили вершину,
             * то проверяем на наличие... (см.
             * подробности в Vertex.h)
             * */
            if (!V->SetLeaf) { T.SetLeaf(V); }

            /* Если у нас есть шаблонная строка,
             * совпадающая с суффиксом, то
             * тогда V->Leaf = true и мы
             * выведем * после символа
             * */
            if (V->Leaf) {
                cout << "*";
            }
        }

        // Выходим из программы
        if (exit) { break; }
    }

    return 0;
}