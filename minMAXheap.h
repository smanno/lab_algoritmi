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
    string toString();
    int length();
    int getRoot();
};

string Heap::toString(){
    vector<int> arrayToPrint = this->arrayNodes;
    string result = "";
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

void Heap::build(vector<int> arrayOfNumbers) {
    arrayNodes = arrayOfNumbers;
}
int Heap::length() { return arrayNodes.size(); }

int Heap::parent(int index)  { return index / 2; }

int Heap::left(int index) { return 2 * index; }

int Heap::right(int index) { return 2 * index; }

int Heap::getRoot() { return arrayNodes[0]; }

    /**
     * CLASS MaxHeap
     */
class MaxHeap: public Heap{
public:
    void build(vector<int>);
    void heapify(int);
    void insert(int);
    void extract();
    void change(int,int);
};

void MaxHeap::build(vector<int> arrayOfNumbers) {
    arrayNodes = arrayOfNumbers;
    for(int i=arrayNodes.size()/2; i>=0; --i){
        heapify(i);
    }
}

void MaxHeap::heapify(int index) {
    int newIndex;
    int left = this->left(index);
    int right = this->right(index);
    if(left<=this->length() && arrayNodes[left]>arrayNodes[index]){
        newIndex = left;
    } else {
        newIndex = index;
    }
    if(right<=this->length() && arrayNodes[right]>arrayNodes[index]){
        newIndex = right;
    }
    if(newIndex != index){
        swap(arrayNodes[index],arrayNodes[newIndex]);
        this->heapify(newIndex);
    }
}

void MaxHeap::extract() {
    arrayNodes.erase(arrayNodes.begin());
    for(int i=arrayNodes.size()/2; i>0; --i){
        heapify(i);
    }
}

void MaxHeap::change(int index, int newNumber) {
    arrayNodes[index] = newNumber;
    heapify(index);
}

void MaxHeap::insert(int number) {
    this->arrayNodes.push_back(number);
    int i = this->length();
    while (i>1 && arrayNodes[i]>arrayNodes[parent(i)]){
        swap(arrayNodes[i],arrayNodes[parent(i)]);
        i = parent(i);
    }
}

    /**
     * CLASS MinHeap
     */
/*
class MinHeap: public Heap{
public:
    void build(vector<int>);
    void heapify(int);
    void insert(int);
    void extract();
    void change(int,int);
};

void MinHeap::build(vector<int> arrayOfNumbers) {
    arrayNodes = arrayOfNumbers;
    for(int i=arrayNodes.size()/2; i>0; --i){
        heapify(i);
    }
}
*/