#ifndef SKIPLIST_H
#define SKIPLIST_H

template <typename E>
class Node
{
private:
    E *element;
    Node *nextList;
    int height;

    Node();
    ~Node();

    friend class Skiplist;

};

template <typename E>
class Skiplist
{
private:
    int size;
    std::vector<*Node<E>> negativeInf;
    Node positiveInf;

    std::vector<**Node<E>> search(E*);

public:
    void add(E*);
    E* remove(E*);
};

#endif // SKIPLIST_H