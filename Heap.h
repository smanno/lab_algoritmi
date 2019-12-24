//
// Created by stefano on 23/12/2019.
//
#ifndef vector
#include <vector>
#endif
#ifndef string
#include <string.h>
#endif
#ifndef sstream
#include <sstream>
#endif
#ifndef funzioni
#include "funzioni.h"
#endif

#ifndef LABORATORIO_HEAP_H
#define LABORATORIO_HEAP_H

using namespace std;

/**
 * For both single and double heaps to get parent/left/right
 */
class Heap{
protected:
    int parent(int);
    int left(int);
    int right(int);
};

/**
 * CLASS SingleHeap
 * has NO order
 */
class SingleHeap: virtual public Heap{
protected:
    vector<int> arrayNodes;
public:
    void build(vector<int>);
    vector<int> getVector();
    string toString();          // prints the heap structNodes
    int length();
    bool isEmpty();
    int getRoot();              // returns the root without deleting it
};

/**
 * CLASS MaxHeap
 * every node has a value lower than his parent
 * every node has a value greater than his children
 */
class MaxHeap: public SingleHeap{
protected:
    void heapify();
    void heapifyDown(int);
    void heapifyUp(int);
public:
    void build(vector<int>);
    void insert(int);           // insert new number and heapifyUp
    void extract();             // delete the root and heapifyDown
    void change(int,int);       // replace replace structNodes[index] with the chosen number
};

/**
 * CLASS MinHeap
 * every node has a value greater than his parent
 * every node has a value lower than his children
 */
class MinHeap: public SingleHeap{
protected:
    void heapify();
    void heapifyDown(int);
    void heapifyUp(int);
public:
    void build(vector<int>);
    void insert(int);           // insert new number and heapifyUp
    void extract();             // delete the root and heapifyDown
    void change(int,int);       // replace replace structNodes[index] with the chosen number
};





struct valueIndex {
    int value;
    int index;
};

/**
 * CLASS DoubleHeap
 * has NO order
 */
class DoubleHeap: public Heap{
protected:
    vector<valueIndex> structNodes;
public:
    void build(vector<valueIndex>);
    vector<int> getVector();
    string toString();          // prints the heap structNodes
    int length();
    bool isEmpty();
    valueIndex getRoot();              // returns the root without deleting it
};

/**
 * CLASS DoubleMinHeap
 * every node has a value greater than his parent
 * every node has a value lower than his children
 */
class DoubleMinHeap: public DoubleHeap{
protected:
    void heapify();
    void heapifyDown(int);
    void heapifyUp(int);
public:
    void build(vector<valueIndex>);
    void extract();
    void insert(int,int);
};

#endif //LABORATORIO_HEAP_H