/**
 * Class Heap: build either a min-Heap or a MAX-Heap
 */

#ifndef vector
#include <vector>
#endif
#ifndef string
#include <string.h>
#endif
#ifndef sstream
#include <sstream>
#endif
/*
#ifndef funzioni.h
#include "funzioni.h"
#endif
*/

using namespace std;

    /**
     * CLASS Heap
     */
class Heap{
protected:
    vector<int> arrayNodes;
    int parent(int);
    int left(int);
    int right(int);
public:
    void build();
    void build(vector<int>);
    vector<int> getVector();
    string toString();          // prints the heap arrayNodes
    int length();
    bool isEmpty();
    int getRoot();              // returns the root without deleting it
};

void Heap::build() { arrayNodes; }

void Heap::build(vector<int> input) {
    arrayNodes = input;
}
int Heap::length() { return arrayNodes.size(); }

bool Heap::isEmpty() { return arrayNodes.size()==0; }

int Heap::parent(int index)  { return (index - 1) / 2; }

int Heap::left(int index) { return (2 * index) + 1; }

int Heap::right(int index) { return (2 * index) + 2; }

int Heap::getRoot() { return arrayNodes[0]; }

string Heap::toString(){
    vector<int> arrayToPrint = arrayNodes;
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

vector<int> Heap::getVector() { return arrayNodes; }

    /**
     * CLASS MaxHeap
     * every node has a value lower than his parent
     * every node has a value greater than his children
     */
class MaxHeap: public Heap{
protected:
    void heapifyDown(int);
    void heapifyUp(int);
public:
    void build(vector<int>);
    void insert(int);           // insert new number and heapifyDown
    void extract();             // delete the root and heapifyDown
    void change(int,int);       // replace replace arrayNodes[index] with the chosen number
};

void MaxHeap::build(vector<int> arrayOfNumbers) {
    arrayNodes = arrayOfNumbers;
    for(int i=(arrayNodes.size()/2) -1; i>=0; --i){
        heapifyDown(i);
    }
}

void MaxHeap::heapifyDown(int index) {
    int largest = index;
    int l = left(index);
    int r = right(index);
    if(l <= length()-1 && arrayNodes[l] > arrayNodes[largest]){
        largest = l;
    }
    if(r <= length()-1 && arrayNodes[r] > arrayNodes[largest]){
        largest = r;
    }
    if(largest != index){
        swap(arrayNodes[index],arrayNodes[largest]);
        heapifyDown(largest);
    }
}

void MaxHeap::heapifyUp(int index){
    if(index && arrayNodes[index]>arrayNodes[parent(index)]){
        swap(arrayNodes[index],arrayNodes[parent(index)]);
        heapifyUp(parent(index));
    }
}

void MaxHeap::extract() {
    arrayNodes[0] = arrayNodes.back();
    arrayNodes.pop_back();
    /*
    int i = length()-1;
    swap( arrayNodes[0], arrayNodes[i]);
    arrayNodes.erase(arrayNodes.begin()+i);
     */
    heapifyDown(0);
}

void MaxHeap::change(int index, int newNumber) {
    arrayNodes[index] = newNumber;
    heapifyDown(0);
    /*
    heapifyDown(index);
    heapifyUp(index);
     */
}

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
class MinHeap: public Heap{
protected:
    void heapifyDown(int);
    void heapifyUp(int);
public:
    void build(vector<int>);
    void insert(int);           // insert new number and heapifyDown
    void extract();             // delete the root and heapifyDown
    void change(int,int);       // replace replace arrayNodes[index] with the chosen number
};

void MinHeap::build(vector<int> arrayOfNumbers) {
    arrayNodes = arrayOfNumbers;
    for(int i=(arrayNodes.size()/2)-1; i>=0; --i){
        heapifyDown(i);
    }
}

void MinHeap::heapifyDown(int index) {
    int newIndex;
    int l = left(index);
    int r = right(index);
    if(l <= length()-1 && arrayNodes[l] <= arrayNodes[index]){
        newIndex = l;
    } else {
        newIndex = index;
    }
    if(r <= length()-1 && arrayNodes[r] <= arrayNodes[newIndex]){
        newIndex = r;
    }
    if(newIndex != index){
        swap(arrayNodes[index],arrayNodes[newIndex]);
        heapifyDown(newIndex);
    }
}

void MinHeap::heapifyUp(int index) {
    if(index && arrayNodes[index]<arrayNodes[parent(index)]){
        swap(arrayNodes[index],arrayNodes[parent(index)]);
        heapifyUp(parent(index));
    }
}

void MinHeap::extract() {
    arrayNodes[0] = arrayNodes.back();
    arrayNodes.pop_back();
    /*
    int i = length()-1;
    swap( arrayNodes[0], arrayNodes[i]);
    arrayNodes.erase(arrayNodes.begin()+i);
     */
    heapifyDown(0);
}

void MinHeap::change(int index, int newNumber) {
    arrayNodes[index] = newNumber;
    heapifyDown(0);
    /*
    heapifyDown(index);
    heapifyUp(index);
     */
}

void MinHeap::insert(int number) {
    arrayNodes.push_back(number);
    int i = length()-1;
    heapifyUp(i);
}

        /**
         * CLASS DoubleMinHeap
         * every node has a value greater than his parent
         * every node has a value lower than his children
         */
struct valueIndex {
    int value;
    int index;
};

class DoubleMinHeap: public Heap{
protected:
    vector<valueIndex> arrayNodes;
    void heapifyDown(int);
    void heapifyUp(int);
public:
    void build(vector<valueIndex>);
    valueIndex getRoot();
    void insert(int,int);           // insert new number and heapifyDown
    void extract();                 // delete the root and heapifyDown
};

void DoubleMinHeap::build(vector<valueIndex> input) {
    arrayNodes = input;
    for(int i=(arrayNodes.size()/2)-1; i>=0; --i){
        heapifyDown(i);
    }
}

void DoubleMinHeap::heapifyDown(int index) {
    int newIndex;
    int l = left(index);
    int r = right(index);
    if(l <= length()-1 && arrayNodes[l].value <= arrayNodes[index].value){
        newIndex = l;
    } else {
        newIndex = index;
    }
    if(r <= length()-1 && arrayNodes[r].value <= arrayNodes[newIndex].value){
        newIndex = r;
    }
    if(newIndex != index){
        swap(arrayNodes[index],arrayNodes[newIndex]);
        heapifyDown(newIndex);
    }
}

void DoubleMinHeap::heapifyUp(int index) {
    if(index && arrayNodes[index].value<arrayNodes[parent(index)].value){
        swap(arrayNodes[index],arrayNodes[parent(index)]);
        heapifyUp(parent(index));
    }
}

void DoubleMinHeap::insert(int number, int index) {
    valueIndex input;
    input.value = number;
    input.index = index;
    arrayNodes.push_back(input);
    int i = length()-1;
    heapifyUp(i);
}

void DoubleMinHeap::extract() {
    arrayNodes[0] = arrayNodes.back();
    arrayNodes.pop_back();
    /*
    int i = length()-1, j=0;
    swap( arrayNodes[0], arrayNodes[i]);
    arrayNodes.erase(arrayNodes.begin()+i);
     */
    heapifyDown(0);
}

valueIndex DoubleMinHeap::getRoot() { return arrayNodes[0]; }