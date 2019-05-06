#include "Tree.h"
#include <queue>
#include <iomanip>

using std::cin;
using std::endl;
using std::queue;
using std::setw;

int main(int argc, char* argv[]) {
    Tree T  = Tree();

    for (int i = 1; i < argc; i++) {
        T.AddString(argv[i]);
    }
    T.AddString("12");

    string str;
    Vertex * V = T.Root;

    while(cin >> str) {
        bool exit = false;
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            if (c == EOF || c == '\n') {
                exit = true;
                break;
            }
            cout << c;
            V = T.Go(V,c);
            if (!V->SetLeaf) { T.SetLeaf(V); }

            if (V->Leaf) {
                cout << "*";
            } else {
                continue;
            }
        }
        if (exit) { break; }
    }

    T.Print();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}