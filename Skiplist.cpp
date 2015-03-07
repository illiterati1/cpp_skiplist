#include 'Skiplist.h'

// Node
Node::Node(E *newElem, int newHeight)
{
    height = newHeight;
    element = newElem;
    nextList = new *Node[height];
}

Node::~Node()
{
    delete[] nextList;
}

// Skiplist