#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <vector>
#include <random>

template<typename E> class Node;
template<typename E> bool operator< (const Node<E>&, const E&);
template<typename E> class Skiplist;

template <typename E>
class Node
{
private:
    E element;
    Node<E> **nextList;
    int height;

    Node(E, int);
    ~Node();

    friend class Skiplist<E>;
    friend bool operator< <>(const Node<E>&, const E&);
};

template <typename E>
class Skiplist
{
private:
    int size;
    std::vector<Node<E>*> negativeInf;
    // Positive infinity = NULL

    std::default_random_engine generator;
    std::geometric_distribution<int> distribution;

    std::vector<Node<E>**> search(const E&);

public:
    Skiplist();
    ~Skiplist();
    void add(const E&);
    //void remove(const E&);
    //bool is_in(const E&);
    void test_print();
};

#endif // SKIPLIST_H