#ifndef  iostream
#include <iostream>
#endif
#ifndef string
#include <string.h>
#endif
#ifndef funzioni
#include "funzioni.h"
#endif
/*
#ifndef time
#include <time.h>
#endif*/
#ifndef algorithm
#include <algorithm>
#endif
#ifndef chrono
#include <chrono>
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
//#include "es12.h"

using namespace std;
using namespace std::chrono;

void calcoloRes();

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
    calcoloRes();
    return 0;
}

void calcoloRes(){
    vector<int> values(10000);
    auto f = []() -> int { return rand()%10000; };
    generate(values.begin(), values.end(), f);

    //auto start = high_resolution_clock::now;
    auto start = chrono::steady_clock::now();

    //sort(values.begin(), values.end());

    //auto stop = high_resolution_clock::now;
    auto stop = chrono::steady_clock::now();

    auto durationSec = duration_cast<seconds>(stop - start);
    auto durationMilli = duration_cast<milliseconds>(stop - start);
    auto durationMicro = duration_cast<microseconds>(stop - start);
    auto durationNano = duration_cast<nanoseconds>(stop - start);

    cout<<durationSec.count()<<" seconds"<<endl;
    cout<<durationMilli.count()<<" milliseconds"<<endl;
    cout<<durationMicro.count()<<" microseconds"<<endl;
    cout<<durationNano.count()<<" nanoseconds"<<endl;
}

/**
void calcoloRes(){
    for(int i=0; i<100; i++) {
        clock_t tStart = clock();
        clock_t tEnd;
        do{
            tEnd = clock();
        } while (tStart==tEnd);

        double elapsed = ((double)(tEnd-tStart))/CLOCKS_PER_SEC;
        cout<<elapsed<<" ";
    }
    cout<<endl<<CLOCKS_PER_SEC;
}*/