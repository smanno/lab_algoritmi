/*
Scrivere un programma che riceva in input un array V di interi e restituisca una coppia ordinata (i,j) di posizioni
nell'array V tale che i <= j e la differenza V[j] - V[i] sia massima
 */

int es7pairOfPositionsWithMaxDifference(){
    vector<int> arrayDaStudiare;
    cin >> arrayDaStudiare;
    int len = arrayDaStudiare.size();
    int bestI=len-1, bestJ=len-1, bestDiff=0, diff=0;

    for(int i=len-1, j=len-1; i>=0; i--){
        diff = arrayDaStudiare[j]-arrayDaStudiare[i];
        if(diff>bestDiff){
            bestDiff = diff;
            bestI = i;
            bestJ = j;
        }
        if(diff<0)
            j = i;
    }

    cout << bestI << " " << bestJ << endl;

    return 0;
}