/*
Copyright 2015 Brendan Wilson

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
    void remove(const E&);
    bool contains(const E&);
    void test_print();
};

#endif // SKIPLIST_H