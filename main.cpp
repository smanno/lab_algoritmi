#ifndef  iostream
#include <iostream>
#endif
#ifndef string
#include <string.h>
#endif
#ifndef funzioni
#include "funzioni.h"
#endif
//#include "es1.h"
//#include "es2.h"
//#include "es3.h"
//#include "es4.h"
//#include "es5.h"
//#include "es6.h"
//#include "es7.h"
//#include "es8.h"
//#include "es9.h"
//#include "es10.h"
//#include "es11.h"
#include "es12.h"

using namespace std;

int provaDoubleMinHeap();

int main() {
    //es1helloWorld();
    //es2sumOfTwoIntegers();
    //es3stringSuffixes();
    //es4stringPrefixes();
    //es5binarySearch();
    //es6pairOfPositionsWithGivenSum();
    //es7pairOfPositionsWithMaxDifference();
    //es8arrayIntervalWithGivenSum();
    //es9majority();
    //es10sort();
    //es11minHeap();
    //es12selection();
    provaDoubleMinHeap();
    return 0;
}

int provaDoubleMinHeap() {
    vector<int> arrayOfNumbers;
    int number;
    cin>>arrayOfNumbers;
    cin>>number;

    MinHeap heapA;
    heapA.build(arrayOfNumbers);
    arrayOfNumbers = heapA.getVector();
    cout<<"heapA: "<<arrayOfNumbers;
    heapA.insert(0);

    valueIndex val;
    vector<valueIndex> arrayDouble;
    for(int i=0; i<arrayOfNumbers.size(); i++){
        val.value = arrayOfNumbers[i];
        val.index = i;
        arrayDouble.push_back(val);
    }

    DoubleMinHeap heapB;
    heapB.build(arrayDouble);
    vector<int> heapBprint = heapB.getVector();
    cout<<"heapB: "<<heapBprint;

    DoubleMinHeap heapC;
    heapC.insert(arrayOfNumbers[0],0);
    vector<int> heapCprint = heapC.getVector();
    cout<<"heapC[-1]: "<<heapCprint;

    valueIndex root;
    for(int i=1; i<number; i++){
        root = heapC.getRoot();
        int left = (root.index*2)+1;
        int right = (root.index*2)+2;
        heapC.extract();
        if(left<arrayOfNumbers.size()) {
            heapC.insert(arrayOfNumbers[left], left);
        }
        if(right<arrayOfNumbers.size()) {
            heapC.insert(arrayOfNumbers[right], right);
        }
        heapCprint = heapC.getVector();
        cout<<"heapC["<<i<<"]: "<<heapCprint;
    }

    root = heapC.getRoot();
    cout<<root.value<<endl;

    cout<<"heapCprint: "<<heapCprint;
    swap(heapCprint[0], heapCprint[heapCprint.size()-1]);
    cout<<"heapCprint: "<<heapCprint;

    return 0;
}