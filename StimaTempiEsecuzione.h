//
// Created by stefano on 10/12/2019.
//
#ifndef  iostream
#include <iostream>
#endif
#ifndef vector
#include <vector>
#endif
#ifndef algorithm
#include <algorithm>
#endif
#ifndef chrono
#include <chrono>
#endif
#ifndef stdlib
#include <stdlib.h>
#endif
/*
#ifndef LABORATORIO_STIMATEMPIESECUZIONE_H
#define LABORATORIO_STIMATEMPIESECUZIONE_H

#endif //LABORATORIO_STIMATEMPIESECUZIONE_H
*/
using namespace std;
using namespace std::chrono;

vector<int> inizializzaVettore(int);
vector<microseconds> testaAlgoritmo(vector<int>,int);
microseconds calcolaTempoMedio(vector<microseconds>);
vector<microseconds> calcolaDeviazione(vector<microseconds>,microseconds);

void stimaTempi(){
    /**
     * ciclo(x->10-49)
     *      vettoreCasuale[10^(i/10)]
     *      parametro k casuale (k varia tra 0 e 10^(x/10)-1)
     *      vettoreTempi[10]
     *      vettoreDeviazione[10]
     *      ciclo(y->0-9)
     *          start
     *          algortimo(vettoreCasuale, k)
     *          stop
     *          durata in vettoreTempi[y]
     *      }
     *      calcolo tempo medio di esecuzione
     *      ciclo(z->0-9)
     *          calcolo deviazione standard vettoreTempi[z] e tempo medio
     *          deviazione in vettoreDevizione[z]
     *      }
     *      stampa  10^(i/10)
     *              k
     *              vettoreTempi[0]
     *              vettoreDeviaizone[0]
     *              vettoreTempi[1]
     *              vettoreDeviaizone[1]
     *              ...
     * }
     */
    for(int i=10; i < 50; i++){
        // inizializzazione
        int N = 10^(int)(i / 10);          // per i=10-19 vettore[10], per i=20-29 vettore[100]...
        vector<int> vettoreCasuale = inizializzaVettore(N);
        int K = rand()%N;
        vector<microseconds> vettoreTempi = testaAlgoritmo(vettoreCasuale,K);
        microseconds tempoMedio = calcolaTempoMedio(vettoreTempi);
        vector<microseconds> vettoreDeviazione = calcolaDeviazione(vettoreTempi, tempoMedio);
    }
}

vector<int> inizializzaVettore(int N){
    vector<int> vettoreCasuale;
    for(int i=0; i < N; i++){
        int temp = rand()%N;
        int temp2 = rand()%100;
        if(temp2<40){
            temp=-1*temp;
        }
        vettoreCasuale.push_back(temp);
    }
    return vettoreCasuale;
}

vector<microseconds> testaAlgoritmo(vector<int> vettoreCasuale, int K){
    vector<microseconds> vettoreTempi;
    for(int i=0;i<10;i++){
        auto start = chrono::steady_clock::now();
        sort(vettoreCasuale.begin(), vettoreCasuale.end()); // algoritmo(vettoreCasuale, K)
        auto stop = chrono::steady_clock::now();
        auto durationMicro = duration_cast<microseconds>(stop - start);
        vettoreTempi.push_back(durationMicro);
    }
    return vettoreTempi;
}

microseconds calcolaTempoMedio(vector<microseconds> vettoreTempi){
    int measures = vettoreTempi.size();
    microseconds total;
    while(!vettoreTempi.empty()){
        total = total + vettoreTempi.back();
        vettoreTempi.pop_back();
    }
    return total/measures;
}

vector<microseconds> calcolaDeviazione(vector<microseconds> vettoreTempi,microseconds tempoMedio){
    vector<microseconds> vettoreDeviazione;
    return vettoreDeviazione;
}