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
    string toString();          // prints the heap arrayNodes
    int length();
    int getRoot();              // returns the root without deleting it
};

void Heap::build() { arrayNodes; }

void Heap::build(vector<int> arrayOfNumbers) {
    arrayNodes = arrayOfNumbers;
}
int Heap::length() { return arrayNodes.size(); }

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

    /**
     * CLASS MaxHeap
     * every node has a value lower than his parent
     * every node has a value greater than his children
     */
class MaxHeap: public Heap{
protected:
    void heapify(int);
public:
    void build(vector<int>);
    void insert(int);           // insert new number and heapify
    void extract();             // delete the root and heapify
    void change(int,int);       // replace replace arrayNodes[index] with the chosen number
};

void MaxHeap::build(vector<int> arrayOfNumbers) {
    arrayNodes = arrayOfNumbers;
    for(int i=(arrayNodes.size()/2) -1; i>=0; --i){
        heapify(i);
    }
}

void MaxHeap::heapify(int index) {
    int newIndex;
    int l = left(index);
    int r = right(index);
    if(l <= length()-1 && arrayNodes[l] > arrayNodes[index]){
        newIndex = l;
    } else {
        newIndex = index;
    }
    if(r <= length()-1 && arrayNodes[r] > arrayNodes[newIndex]){
        newIndex = r;
    }
    if(newIndex != index){
        swap(arrayNodes[index],arrayNodes[newIndex]);
        heapify(newIndex);
    }
}

void MaxHeap::extract() {
    int i = length()-1, j=0;
    swap( arrayNodes[0], arrayNodes[i]);
    arrayNodes.erase(arrayNodes.begin()+i);
    heapify(0);
}

void MaxHeap::change(int index, int newNumber) {
    arrayNodes[index] = newNumber;
    heapify(index);
    while (index>=0 && arrayNodes[index]>arrayNodes[parent(index)]){
        swap(arrayNodes[index],arrayNodes[parent(index)]);
        index = parent(index);
    }
}

void MaxHeap::insert(int number) {
    arrayNodes.push_back(number);
    int i = length()-1;
    while (i>0 && arrayNodes[i]>arrayNodes[parent(i)]){
        swap(arrayNodes[i],arrayNodes[parent(i)]);
        i = parent(i);
    }
}

    /**
     * CLASS MinHeap
     * every node has a value greater than his parent
     * every node has a value lower than his children
     */
class MinHeap: public Heap{
protected:
    void heapify(int);
public:
    void build(vector<int>);
    void insert(int);           // insert new number and heapify
    void extract();             // delete the root and heapify
    void change(int,int);       // replace replace arrayNodes[index] with the chosen number
};

void MinHeap::build(vector<int> arrayOfNumbers) {
    arrayNodes = arrayOfNumbers;
    for(int i=(arrayNodes.size()/2)-1; i>=0; --i){
        heapify(i);
    }
}

void MinHeap::heapify(int index) {
    int newIndex;
    int l = left(index);
    int r = right(index);
    if(l <= length()-1 && arrayNodes[l] < arrayNodes[index]){
        newIndex = l;
    } else {
        newIndex = index;
    }
    if(r <= length()-1 && arrayNodes[r] < arrayNodes[newIndex]){
        newIndex = r;
    }
    if(newIndex != index){
        swap(arrayNodes[index],arrayNodes[newIndex]);
        heapify(newIndex);
    }
}

void MinHeap::extract() {
    int i = length()-1, j=0;
    swap( arrayNodes[0], arrayNodes[i]);
    arrayNodes.erase(arrayNodes.begin()+i);
    heapify(0);
}

void MinHeap::change(int index, int newNumber) {
    arrayNodes[index] = newNumber;
    heapify(index);
    while (index>0 && arrayNodes[index]<arrayNodes[parent(index)]){
        swap(arrayNodes[index],arrayNodes[parent(index)]);
        index = parent(index);
    }
}

void MinHeap::insert(int number) {
    arrayNodes.push_back(number);
    int i = length()-1;
    while (i>0 && arrayNodes[i]<arrayNodes[parent(i)]){
        swap(arrayNodes[i],arrayNodes[parent(i)]);
        i = parent(i);
    }
}