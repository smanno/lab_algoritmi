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

int Heap::getRoot() {
    try {
        if(length()==0){
            throw out_of_range("Vector<X>::at : ""index is out of range(Heap underflow)");
        }
        return arrayNodes.at(0);
    }
    catch (const out_of_range oor){
        cout<<"\n"<<oor.what();
    }
}

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

vector<int> Heap::getVector() {
    vector<int> newVector(arrayNodes);
    return newVector;
}

    /**
     * CLASS MaxHeap
     * every node has a value lower than his parent
     * every node has a value greater than his children
     */
class MaxHeap: public Heap{
protected:
    void heapify();
    void BubbleDown(int);
    void BubbleUp(int);
public:
    void build(vector<int>);
    void insert(int);           // insert new number and BubbleDown
    void extract();             // delete the root and BubbleDown
    void change(int,int);       // replace replace arrayNodes[index] with the chosen number
};

void MaxHeap::build(vector<int> arrayOfNumbers) {
    arrayNodes = arrayOfNumbers;
    heapify();
}

void MaxHeap::heapify() {
    for(int i=(arrayNodes.size()/2) -1; i>=0; --i){
        BubbleDown(i);
    }
}

void MaxHeap::BubbleDown(int index) {
    int largest = index;
    int l = left(index);
    int r = right(index);
    if(l < length() && arrayNodes[l] > arrayNodes[largest]){
        largest = l;
    }
    if(r < length() && arrayNodes[r] > arrayNodes[largest]){
        largest = r;
    }
    if(largest != index){
        swap(arrayNodes[index],arrayNodes[largest]);
        BubbleDown(largest);
    }
}

void MaxHeap::BubbleUp(int index){
    if(index==0) return;
    if(index && arrayNodes[parent(index)]<arrayNodes[index]){
        swap(arrayNodes[index],arrayNodes[parent(index)]);
        BubbleUp(parent(index));
    }
}

void MaxHeap::extract() {
    try {
        if(length()==0){
            throw out_of_range("Vector<X>::at() : ""index is out of range(Heap underflow)");
        }
        arrayNodes[0] = arrayNodes.back();
        arrayNodes.pop_back();
        BubbleDown(0);
    }
    catch (const out_of_range& oor){
        cout<<"\n"<<oor.what();
    }
    /*
    int i = length()-1;
    swap( arrayNodes[0], arrayNodes[i]);
    arrayNodes.erase(arrayNodes.begin()+i);
    BubbleDown(0);
     */
}

void MaxHeap::change(int index, int newNumber) {
    arrayNodes[index] = newNumber;
    BubbleDown(0);
    /*
    BubbleDown(index);
    BubbleUp(index);
     */
}

void MaxHeap::insert(int number) {
    arrayNodes.push_back(number);
    int i = length()-1;
    BubbleUp(i);
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
    void insert(int);           // insert new number and BubbleDown
    void extract();             // delete the root and BubbleDown
    void change(int,int);       // replace replace arrayNodes[index] with the chosen number
};

void MinHeap::build(vector<int> arrayOfNumbers) {
    arrayNodes = arrayOfNumbers;
    for(int i=(arrayNodes.size()/2)-1; i>=0; --i){
        heapifyDown(i);
    }
}

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

void MinHeap::heapifyUp(int index) {
    if(index==0) return;
    if(index && arrayNodes[parent(index)]>arrayNodes[index]){
        swap(arrayNodes[index],arrayNodes[parent(index)]);
        heapifyUp(parent(index));
    }
}

void MinHeap::extract() {
    if(length()==0) return;
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
    BubbleDown(index);
    BubbleUp(index);
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
    //vector<int> getVector();
    void insert(int,int);           // insert new number and BubbleDown
    void extract();                 // delete the root and BubbleDown
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
    if(l < length() && arrayNodes[l].value < arrayNodes[index].value){
        newIndex = l;
    } else {
        newIndex = index;
    }
    if(r < length() && arrayNodes[r].value < arrayNodes[newIndex].value){
        newIndex = r;
    }
    if(newIndex != index){
        swap(arrayNodes[index],arrayNodes[newIndex]);
        heapifyDown(newIndex);
    }
}

void DoubleMinHeap::heapifyUp(int index) {
    if(index==0) return;
    if(index>0 && arrayNodes[parent(index)].value>arrayNodes[index].value){
        swap(arrayNodes[index],arrayNodes[parent(index)]);
        heapifyUp(parent(index));
    }
}
/*
vector<int> DoubleMinHeap::getVector(){
    vector<int> newVector;
    for(int i=0; i<length(); i++){
        newVector.push_back(arrayNodes[i-1].value);
    }
    return newVector;
}
*/
void DoubleMinHeap::insert(int number, int index) {
    valueIndex input;
    input.value = number;
    input.index = index;
    arrayNodes.push_back(input);
    int i = arrayNodes.size()-1;
    heapifyUp(i);
}

void DoubleMinHeap::extract() {
    if(length()==0) return;
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