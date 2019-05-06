#include "Tree.h"

int Tree::AddString(const string & s) {
    Vertex * RecentVertex = Root;
    for (auto i = 0; i < s.length(); ++i) {
        char c = s[i];
        if (RecentVertex->Next == nullptr ||
            RecentVertex->Next->find(c) == RecentVertex->Next->end()){
            Vertex * NewV = new Vertex(RecentVertex, c);
            RecentVertex->Next->insert({c,NewV});
        }
        RecentVertex = RecentVertex->Next->find(c)->second;
    }
    RecentVertex->Leaf = true;
    RecentVertex->SetLeaf = true;
    return 0;
}

Vertex *Tree::Go(Vertex *_V, char c) {
    if (_V->Next->find(c) == _V->Next->end()) {
        if (_V == Root) { return Root; }
        _V->Next->insert({c,(Root==_V)? Root : Go(Get_link(_V),c)});
    }
    return _V->Next->find(c)->second;
}

Vertex *Tree::Get_link(Vertex * _V) {
    if (_V->Link == nullptr) {
        if (_V == Root || _V->Parent == Root) {
            _V->Link = Root;
        } else{
            _V->Link = Go(Get_link(_V->Parent), _V->Pch);
        }
    }
    return _V->Link;
}

Tree::~Tree() { Root->~Vertex(); }

void Tree::Print() { Root->Print(0); }

bool Tree::SetLeaf(Vertex *V) {
    if (V->Leaf) { return true; }
    else if (V != Root && !V->SetLeaf) {
        V->Leaf = SetLeaf(Get_link(V));
        V->SetLeaf = true;
        return V->Leaf;
    }
    return false;
}
