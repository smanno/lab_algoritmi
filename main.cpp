#ifndef  iostream
#include <iostream>
#endif
#ifndef fstream
#include <fstream>
#endif
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
#include "StimaTempiOld.h"

using namespace std;
using namespace std::chrono;

void calcoloRes();
double getDuration(steady_clock::time_point,steady_clock::time_point);

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
    stimaTempiOld();
    return 0;
}

double getDuration(steady_clock::time_point start, steady_clock::time_point end){
    typedef duration<double, nanoseconds::period> nanosecs;
    return duration_cast<nanosecs>(end-start).count();
}

void calcoloRes(){
    steady_clock::time_point start = steady_clock::now();
    steady_clock::time_point end;
    do{ end = steady_clock::now(); } while (start==end);
    cout<<getDuration(start,end);
}