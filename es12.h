//
// Created by stefano on 11/11/2019.
//
/**
Esercizio 12 - selection
        Numero massimo di file: 3
Tipo di lavoro: Lavoro individuale

Implementare un algoritmo di selezione (calcolo del k-esimo elemento più piccolo in un array), modificando uno fra i
seguenti algoritmi di ordinamento:
- selection sort (caso peggiore H n^k) NO
- quick sort (caso medio O(n), caso pessimo theta(n^2)) => algoritmo QuickSelect

Il programma deve ricevere in input una sequenza di interi separati da spazio e, su una nuova riga, un ulteriore intero
positivo k; deve produrre in output il k-esimo elemento nella sequenza ordinata.

Esempio:
input=7 3 11 5
2
output=5

In entrambi i casi la complessità asintotica dell'algoritmo dovrà essere O(nk), dove n è la dimensione dell'array
fornito in input.
* Provare ad analizzare anche la complessità dei due algoritmi nel caso medio.

 *
 *      SELECTION con HEAP
 * input vettore+k
 * output k-esimo elemento più piccolo
 * complessità O(k*logk+n)
 * 1) faccio la minHeap A
 *                  - costo theta(n)
 * 2) inizializzo heap B che contiene elementi formati
 *    da struct<int,int> valore e posizione in heapA
 * 3) per k volte
 *    elimino la radice di heapB
 *    usando il puntatore(posizione dell'elemento nella heapA) del nodo tolto inserisco i suoi successori
*                   - costo n
 * 4) restituisco la radice di questa heapB
 *
 *      SELECTION con SELECT
 * implementa l'algoritmo select (la teoria sta sugli appunti) dopo aver cercato lo pseudocodice su internet
 * inziare a prendere le durate dei programmi usando il clock all'inizio e alla fine
 * però deve essere stoppato quando si prendono gli input
 */
#ifndef minMAXheap.h
#include "minMAXheap.h"
#endif

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

int es12selection(){
    vector<int> arrayOfNumbers;
    int number;
    cin>>arrayOfNumbers;
    cin>>number;
    /*
    int len = arrayOfNumbers.size();
    quickSelect(arrayOfNumbers,0,len-1,number-1);
    cout<<arrayOfNumbers[number-1]<<endl;
    */
    MinHeap heapA;
    heapA.build(arrayOfNumbers);
    arrayOfNumbers = heapA.getVector();
    // prova
    cout<<arrayOfNumbers<<endl;
    //int len = arrayOfNumbers.size();
    //quickSelect(arrayOfNumbers,0,len-1,number-1);
    //cout<<arrayOfNumbers<<endl;
    // prova
    DoubleMinHeap heapB;
    heapB.insert(arrayOfNumbers[0],0);
    valueIndex root;

    for(int i=0; i<number-1; i++){
        root = heapB.getRoot();
        int left = (root.index*2)+1;
        int right = (root.index*2)+2;
        heapB.extract();
        heapB.insert(arrayOfNumbers[left],left);
        heapB.insert(arrayOfNumbers[right], right);
    }

    root = heapB.getRoot();
    cout<<root.value<<endl;

    return 0;
}