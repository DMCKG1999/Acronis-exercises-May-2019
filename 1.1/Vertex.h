#ifndef INC_1_1_VERTEX_H
#define INC_1_1_VERTEX_H

#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::pair;

class Vertex {
public:
    map<char, Vertex*> * Next = new map<char, Vertex*>;
    bool Leaf = false;
    bool SetLeaf = false;

    Vertex * Parent;
    char Pch;

    Vertex * Link = nullptr;

    void Print(int depth){
        for(int i = 0; i < depth; i++) {
            cout << "-";
        }
        cout << Pch << " = " << Leaf << endl;
        for(auto it = Next->begin(); it != Next->end(); it++) {
            it->second->Print(depth+1);
        }
    }

    Vertex(): Leaf (false), Parent(nullptr), Pch(), Link(nullptr) {}
    Vertex(Vertex*_Parent, char _Pch) : Leaf (false),
        Parent(_Parent), Pch(_Pch) {}

    ~Vertex(){
        delete(Next);
        delete(Parent);
        delete(Link);

        for (auto it = Next->begin(); it != Next->end(); it++) {
            it->second->~Vertex();
        }
    }
};

#endif //INC_1_1_VERTEX_H
