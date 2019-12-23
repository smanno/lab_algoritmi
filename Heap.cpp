//
// Created by stefano on 23/12/2019.
//

#include "Heap.h"

//
// Created by stefano on 23/12/2019.
//

#ifndef LABORATORIO_HEAP_H
#define LABORATORIO_HEAP_H

#endif //LABORATORIO_HEAP_H

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

using namespace std;

/**
 * For both single and double heaps to get parent/left/right
 *//*
class Heap{
protected:
    int parent(int);
    int left(int);
    int right(int);
};

// return parent of vector[index]
int Heap::parent(int index)  { return (index - 1) / 2; }

// return left child of vector[index]
int Heap::left(int index) { return (2 * index) + 1; }

// return right child of vector[index]
int Heap::right(int index) { return (2 * index) + 2; }*/

/**
 * CLASS SingleHeap
 * has NO order
 */
class SingleHeap/*: virtual public Heap*/{
protected:
    vector<int> arrayNodes;
    int parent(int);
    int left(int);
    int right(int);
public:
    void build(vector<int>);
    vector<int> getVector();
    string toString();          // prints the heap structNodes
    int length();
    bool isEmpty();
    int getRoot();              // returns the root without deleting it
};

// return parent of vector[index]
int SingleHeap::parent(int index)  { return (index - 1) / 2; }

// return left child of vector[index]
int SingleHeap::left(int index) { return (2 * index) + 1; }

// return right child of vector[index]
int SingleHeap::right(int index) { return (2 * index) + 2; }

// modify a SingleHeap with a new vector
void SingleHeap::build(vector<int> input) {
    arrayNodes = input;
}

// returns number of elements in SingleHeap
int SingleHeap::length() { return arrayNodes.size(); }

// true is no elements
bool SingleHeap::isEmpty() { return arrayNodes.size() == 0; }

// return root of SingleHeap
int SingleHeap::getRoot() {
    try {
        if(length()==0){
            throw out_of_range("Vector<X>::at : "
                               "index is out of range(Heap underflow) for SingleHeap::getRoot");
        }
        return arrayNodes[0];
    }
    catch (const out_of_range oor){
        cout<<"\n"<<oor.what();
        return -1;
    }
}

// return string with the vector
string SingleHeap::toString(){
    vector<int> arrayToPrint = getVector();
    string result;
    while(!arrayToPrint.empty()){
        int numberToAdd = arrayToPrint.back();
        stringstream ss;
        ss<<numberToAdd;
        string s;
        ss>>s;
        result = s + " " + result;
        arrayToPrint.pop_back();
    }
    return result;
}

// return node vector
vector<int> SingleHeap::getVector() {
    vector<int> newVector(arrayNodes);
    return newVector;
}

/**
 * CLASS MaxHeap
 * every node has a value lower than his parent
 * every node has a value greater than his children
 */
class MaxHeap: virtual public SingleHeap{
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

// modify and re-heapify a MaxHeap with a new vector
void MaxHeap::build(vector<int> arrayOfNumbers) {
    arrayNodes = arrayOfNumbers;
    heapify();
}

// heapify all non-leaf nodes
void MaxHeap::heapify() {
    for(int i=(arrayNodes.size()/2) -1; i>=0; --i){
        heapifyDown(i);
    }
}

// recursive heapify node[index] and its children
void MaxHeap::heapifyDown(int index) {
    int largest = index;
    int lef = left(index);
    int rig = right(index);
    if(lef < length() && arrayNodes[lef] > arrayNodes[index]){
        largest = lef;
    }
    if(rig < length() && arrayNodes[rig] > arrayNodes[largest]){
        largest = rig;
    }
    if(largest != index){
        swap(arrayNodes[index],arrayNodes[largest]);
        heapifyDown(largest);
    }
}

// recursive heapify node[index] and parent
void MaxHeap::heapifyUp(int index){
    if(index==0) return;
    if(index && arrayNodes[parent(index)]<arrayNodes[index]){
        swap(arrayNodes[index],arrayNodes[parent(index)]);
        heapifyUp(parent(index));
    }
}

// remove root element
void MaxHeap::extract() {
    try {
        if(length()==0){
            throw out_of_range("Vector<X>::at() : "
                               "index is out of range(Heap underflow) for MaxHeap::extract");
        }
        arrayNodes[0] = arrayNodes.back();
        arrayNodes.pop_back();
        heapifyDown(0);
    }
    catch (const out_of_range& oor){
        cout<<"\n"<<oor.what();
    }
}

// switch heap[index] with number, then heapify
void MaxHeap::change(int index, int newNumber) {
    int oldNumber = arrayNodes[index];
    arrayNodes[index] = newNumber;
    if(newNumber>oldNumber){
        heapifyUp(index);
    } else {
        heapifyDown(index);
    }
}

// insert number into the SingleHeap
void MaxHeap::insert(int number) {
    arrayNodes.push_back(number);
    int i = length()-1;
    heapifyUp(i);
}

/**
 * CLASS MinHeap
 * every node has a value greater than his parent
 * every node has a value lower than his children
 */
class MinHeap: virtual public SingleHeap{
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

// modify and re-heapify a SingleHeap with a new vector
void MinHeap::build(vector<int> arrayOfNumbers) {
    arrayNodes = arrayOfNumbers;
    heapify();
}

// heapify all non-leaf nodes
void MinHeap::heapify() {
    for(int i=(arrayNodes.size()/2) -1; i>=0; --i){
        heapifyDown(i);
    }
}

// recursive heapify node[index] and its children
void MinHeap::heapifyDown(int index) {
    int smallest = index;
    int lef = left(index);
    int rig = right(index);
    if(lef < length() && arrayNodes[lef] < arrayNodes[smallest]){
        smallest = lef;
    }
    if(rig < length() && arrayNodes[rig] < arrayNodes[smallest]){
        smallest = rig;
    }
    if(smallest != index){
        swap(arrayNodes[index],arrayNodes[smallest]);
        heapifyDown(smallest);
    }
}

// recursive heapify node[index] and parent
void MinHeap::heapifyUp(int index) {
    if(index && arrayNodes[parent(index)]>arrayNodes[index]){
        swap(arrayNodes[index],arrayNodes[parent(index)]);
        heapifyUp(parent(index));
    }
}

// remove root element
void MinHeap::extract() {
    try {
        if(arrayNodes.size()==0){
            throw out_of_range("Vector<X>::at() : "
                               "index is out of range(Heap underflow) for MinHeap::extract");
        }
        arrayNodes[0] = arrayNodes.back();
        arrayNodes.pop_back();
        heapifyDown(0);
    }
    catch (const out_of_range& oor){
        cout<<"\n"<<oor.what();
    }
}

// switch heap[index] with number, then heapify
void MinHeap::change(int index, int newNumber) {
    int oldNumber = arrayNodes[index];
    arrayNodes[index] = newNumber;
    if(newNumber<oldNumber){
        heapifyUp(index);
    } else {
        heapifyDown(index);
    }
}

// insert number into the SingleHeap
void MinHeap::insert(int number) {
    arrayNodes.push_back(number);
    int i = length()-1;
    heapifyUp(i);
}

























struct valueIndex {
    int value;
    int index;
};

/**
 * CLASS DoubleHeap
 * has NO order
 */
class DoubleHeap/*: virtual public Heap*/{
protected:
    vector<valueIndex> structNodes;
    int parent(int);
    int left(int);
    int right(int);
public:
    void build(vector<valueIndex>);
    vector<int> getVector();
    string toString();          // prints the heap structNodes
    int length();
    bool isEmpty();
    valueIndex getRoot();              // returns the root without deleting it
};

// return parent of vector[index]
int DoubleHeap::parent(int index)  { return (index - 1) / 2; }

// return left child of vector[index]
int DoubleHeap::left(int index) { return (2 * index) + 1; }

// return right child of vector[index]
int DoubleHeap::right(int index) { return (2 * index) + 2; }

// modify a SingleHeap with a new vector
void DoubleHeap::build(vector<valueIndex> input) {
    structNodes = input;
}

// returns number of elements in SingleHeap
int DoubleHeap::length() { return structNodes.size(); }

// true is no elements
bool DoubleHeap::isEmpty() { return structNodes.size() == 0; }

// return root
valueIndex DoubleHeap::getRoot() {
    try {
        if(length()==0){
            throw out_of_range("Vector<X>::at : "
                               "index is out of range(Heap underflow) for DoubleMinHeap::getRoot");
        }
        return structNodes[0];
    }
    catch (const out_of_range oor){
        cout<<"\n"<<oor.what();
        return {-1,-1};
    }
}

// return string with the vector
string DoubleHeap::toString(){
    vector<int> arrayToPrint = getVector();
    string result;
    while(!arrayToPrint.empty()){
        int numberToAdd = arrayToPrint.back();
        stringstream ss;
        ss<<numberToAdd;
        string s;
        ss>>s;
        result = s + " " + result;
        arrayToPrint.pop_back();
    }
    return result;
}

// return node vector
vector<int> DoubleHeap::getVector(){
    vector<int> newVector;
    for(int i=0; i<length(); i++){
        newVector.push_back(structNodes[i].value);
    }
    return newVector;
}

/**
 * CLASS DoubleMinHeap
 * every node has a value greater than his parent
 * every node has a value lower than his children
 */


class DoubleMinHeap: virtual public DoubleHeap{
protected:
    void heapify();
    void heapifyDown(int);
    void heapifyUp(int);
public:
    void build(vector<valueIndex>);
    void extract();
    void insert(int,int);
};

// modify and re-heapify a MaxHeap with a new vector
void DoubleMinHeap::build(vector<valueIndex> input) {
    structNodes = input;
    heapify();
}

// heapify all non-leaf nodes
void DoubleMinHeap::heapify() {
    for(int i=(length()/2) -1; i>=0; --i){
        heapifyDown(i);
    }
}

// recursive heapify node[index] and its children
void DoubleMinHeap::heapifyDown(int index) {
    int newIndex;
    int lef = left(index);
    int rig = right(index);
    if(lef < length() && structNodes[lef].value < structNodes[index].value){
        newIndex = lef;
    } else {
        newIndex = index;
    }
    if(rig < length() && structNodes[rig].value < structNodes[newIndex].value){
        newIndex = rig;
    }
    if(newIndex != index){
        swap(structNodes[index], structNodes[newIndex]);
        heapifyDown(newIndex);
    }
}

// recursive heapify node[index] and parent
void DoubleMinHeap::heapifyUp(int index) {
    if(index && structNodes[parent(index)].value > structNodes[index].value){
        swap(structNodes[index], structNodes[parent(index)]);
        heapifyUp(parent(index));
    }
}

// insert number/index as a valueIndex into the SingleHeap
void DoubleMinHeap::insert(int number, int pos) {
    valueIndex input;
    input.value = number;
    input.index = pos;
    structNodes.push_back(input);
    int i = length()-1;
    heapifyUp(i);
}

// remove root element
void DoubleMinHeap::extract() {
    try {
        if(length()==0){
            throw out_of_range("Vector<X>::at() : "
                               "index is out of range(Heap underflow) for MinHeap::extract");
        }
        structNodes[0] = structNodes.back();
        structNodes.pop_back();
        heapifyDown(0);
    }
    catch (const out_of_range& oor){
        cout<<"\n"<<oor.what();
    }
}