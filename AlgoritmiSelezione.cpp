//
// Created by stefano on 23/12/2019.
//
#ifndef vector
#include <vector>
#endif
#ifndef funzioni
#include "funzioni.h"
#endif
#ifndef minMAXheap
#include "minMAXheap.h"
#endif

using namespace std;

    /** QUICK SELECT */
int partition(vector<int> &arrayOfNumbers, int start, int end){
    int key = arrayOfNumbers[end];
    int i = start-1;
    for(int j=start; j<=end; j++){                  // con j<end non fa l'ultima iterazione e continua all'infinito
        if(arrayOfNumbers[j]<=key){
            i++;
            swap(arrayOfNumbers[i],arrayOfNumbers[j]);
        }
    }
    return i;
}

void quickSelect(vector<int> &arrayOfNumbers, int start, int end, int index){
    if(start>=end) return;
    if(index<start || index>end) return;
    int partitionIndex = partition(arrayOfNumbers,start,end);
    quickSelect(arrayOfNumbers,start,partitionIndex-1,index);
    quickSelect(arrayOfNumbers,partitionIndex+1,end,index);
}

    /** HEAP SELECT */
int heapSelect(vector<int> arrayOfNumbers, int number){
    MinHeap heapA;
    heapA.build(arrayOfNumbers);
    arrayOfNumbers = heapA.getVector();
    DoubleMinHeap heapB;
    heapB.insert(arrayOfNumbers[0],0);
    valueIndex root;

    for(int i=1; i<number; i++){
        root = heapB.getRoot();
        int left = (root.index*2)+1;
        int right = (root.index*2)+2;
        heapB.extract();
        if(left<arrayOfNumbers.size()) {
            heapB.insert(arrayOfNumbers[left], left);
        }
        if(right<arrayOfNumbers.size()) {
            heapB.insert(arrayOfNumbers[right], right);
        }
    }

    root = heapB.getRoot();
    cout<<root.value<<endl;

    return 0;
}