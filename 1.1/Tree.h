#ifndef INC_1_1_TREE_H
#define INC_1_1_TREE_H

#include "Vertex.h"
#include <string>

using std::string;

class Tree{
public:
    Vertex * Root = new Vertex;

    int AddString (const string & s);

    Vertex * Go (Vertex * _V, char c);
    Vertex * Get_link (Vertex * _V);

    bool SetLeaf(Vertex * V);

    void Print ();

    Tree() {
        Root->SetLeaf = true;
    }

    ~Tree();
};


#endif //INC_1_1_TREE_H
