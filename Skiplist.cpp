#include <vector>
#include <random>
#include <iostream> // for test_print, delete later
#include <ctime>
#include "Skiplist.h"

///////////////////////////////// Node
template <typename E>
Node<E>::Node(E newElem, int newHeight)
{
    height = newHeight;
    element = newElem;
    nextList = new Node<E>*[height];
}

template <typename E>
Node<E>::~Node()
{
    delete[] nextList;
}

template <typename E>
bool operator< (const Node<E> &lhs, const E &rhs)
{
    return lhs.element < rhs;
}

/////////////////////////////// Skiplist
// Constructor/destructor
template <typename E>
Skiplist<E>::Skiplist()
{
    size = 0;
    negativeInf.push_back(NULL);
    distribution = std::geometric_distribution<int> (0.5);
    generator.seed(time(NULL));
}

template <typename E>
Skiplist<E>::~Skiplist()
{
    Node<E> *current = negativeInf[0];
    Node<E> *next;
    while (current)
    {
        next = current->nextList[0];
        delete current;
        current = next;
    }
}

// Private functions
template <typename E>
std::vector<Node<E>**> Skiplist<E>::search(const E &target)
{
    int level = negativeInf.size() - 1;
    std::vector<Node<E>**> links;
    Node<E> **ppCurrent = &negativeInf[level];

    while (level >= 0)
    {   
        if (*ppCurrent && (*ppCurrent)->element < target)
        {
            // Move rightward
            ppCurrent = &(*ppCurrent)->nextList[level];
        }
        else
        {
            // Move downward
            links.push_back(ppCurrent);
            --level;
            --ppCurrent;
        }
    }

    return links;
}

// Public functions
template <typename E>
void Skiplist<E>::add(const E &newElement)
{
    std::vector<Node<E>**> links = search(newElement);
    int height = distribution(generator) + 1;
    int index = 0;
    Node<E> *pNewNode = new Node<E>(newElement, height);

    while (links.size() > 0 && index < height)
    {
        Node<E> **ppPrevNode = links.back();
        links.pop_back();
        Node<E> *pNextNode = *ppPrevNode;
        *ppPrevNode = pNewNode;
        pNewNode->nextList[index] = pNextNode;
        ++index;
    }

    while (index < height) // We need to raise total height of list
    {
        negativeInf.push_back(pNewNode);
        pNewNode->nextList[index] = NULL;
        ++index;
    }

    ++size;
}

template <typename E>
void Skiplist<E>::remove(const E &target)
{
    std::vector<Node<E>**> links = search(target);
    Node<E> **ppPrevNode = links.back();
    Node<E> *toDelete = *ppPrevNode;

    if (toDelete == NULL || toDelete->element != target)
    {
        // TODO: raise exception; target not found
        return;
    }
    
    for (int i = 0; i < toDelete->height; ++i)
    {
        ppPrevNode = links.back();
        links.pop_back();
        *ppPrevNode = toDelete->nextList[i];
    }

    delete toDelete;

    while (negativeInf.back() == NULL)
    {
        negativeInf.pop_back();
    }

    --size;
}

template <typename E>
void Skiplist<E>::test_print()
{
    using namespace std;

    cout << "-infinity\t";
    for (unsigned int i = 0; i < negativeInf.size(); ++i)
        cout << "- ";
    cout << endl;

    Node<E> *current = negativeInf[0];
    while (current)
    {
        int i = 0;
        cout << current->element << "\t\t";
        for (; i < current->height; ++i)
            cout << "- ";
        for (; i < signed(negativeInf.size()); ++i)
            cout << "| ";
        cout << endl;
        current = current->nextList[0];
    }

    cout << "infinity\t";
    for (unsigned int i = 0; i < negativeInf.size(); ++i)
        cout << "- ";
    cout << endl;
}

template <typename E>
bool Skiplist<E>::contains(const E &target)
{
    int level = negativeInf.size() - 1;
    Node<E> **ppCurrent = &negativeInf[level];

    while (level >= 0)
    {
        if (*ppCurrent && (*ppCurrent)->element < target)
        {
            ppCurrent = &(*ppCurrent)->nextList[level];
        }
        else if (*ppCurrent && (*ppCurrent)->element == target)
        {
            return true;
        }
        else
        {
            --level;
            --ppCurrent;
        }
    }

    return false;
}

template class Skiplist<int>;