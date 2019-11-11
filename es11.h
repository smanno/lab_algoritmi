/*
 Esercizio 11 - heap
Numero massimo di file: 3
Tipo di lavoro: Lavoro individuale

Implementare la struttura dati "min heap", ovvero un albero binario quasi completo in cui il valore di un nodo é sempre
minore o uguale ai valori dei suoi figli (se ve ne sono). Tale struttura dovrà supportare le seguenti operazioni:

- build x1x2x3…: inizializzazione della heap tramite sequenza di elementi interi (non necessariamente ordinati)
- length: restituzione del numero di elementi nella heap
- getmin: restituzione del valore del nodo radice
- extract: rimozione del nodo radice
- insert x: inserimento di un nuovo nodo con valore intero x
- change ix: assegnazione di un nuovo valore x al nodo con indice i (secondo la codifica in vettore dell'albero binario)

Il programma dovrà essere di tipo interattivo: a ogni iterazione, l'utente potrà indicare una fra le operazioni sopra
riportate (ad es., "insert 5", oppure "build 50 30 10"), e in output verrà fornito il contenuto della heap aggiornata
(nella codifica in vettore), eventualmente preceduto dal valore calcolato dall'operazione (solo per le operazioni
"length" e "getmin"). Il programma terminerà ogni qualvolta l'utente inserisca un'operazione non supportata (es "exit").

Di seguito si riporta un esempio di esecuzione attesa dal programma (per convenienza, le stringhe di input e output
sono intercalate in modo da rispettare il tipo di interazione):

input=build 50 30 10
output=10 30 50

input=length
output=3
            10 30 50

input=getmin
output=10
            10 30 50

input=insert 40
output=10 30 50 40

input=insert 20
output=10 20 50 40 30

input=extract
output=20 30 50 40

input=change 2 10
output=10 30 20 40

input=getmin
output=10
            10 30 20 40

input=exit
 */
#ifndef minMAXheap.h
#include "minMAXheap.h"
#endif
/*
#ifndef funzioni.h
#include "funzioni.h"
#endif
*/
enum Options{
    invalid, build, length, getmin, extract, insert, change
};

Options resolveOption(string);

int es11minHeap(){
    string useFunction = "func";
    vector<int> arrayOfNumbers;
    MinHeap heapToUse;
    string stampa = "";
    int result = 0;

    do{
        cin >> useFunction >> arrayOfNumbers;
        switch (resolveOption(useFunction)) {
            case build:{
                heapToUse.build(arrayOfNumbers);
                stampa = heapToUse.toString();
                cout<<stampa<<endl;
                break;
            }
            case length:{
                result = heapToUse.length();
                stampa = heapToUse.toString();
                cout<<result<<endl<<stampa<<endl;
                break;
            }
            case getmin:{
                result = heapToUse.getRoot();
                stampa = heapToUse.toString();
                cout<<result<<endl<<stampa<<endl;
                break;
            }
            case extract:{
                heapToUse.extract();
                stampa = heapToUse.toString();
                cout<<stampa<<endl;
                break;
            }
            case insert:{
                heapToUse.insert(arrayOfNumbers[0]);
                stampa = heapToUse.toString();
                cout<<stampa<<endl;
                break;
            }
            case change:{
                heapToUse.change(arrayOfNumbers[0], arrayOfNumbers[1]);
                stampa = heapToUse.toString();
                cout<<stampa<<endl;
                break;
            }
        }
    } while(resolveOption(useFunction)!=invalid);
    return 0;
}

Options resolveOption(string inputFunction){
    if(inputFunction == "build") return build;
    if(inputFunction == "length") return length;
    if(inputFunction == "getmin") return getmin;
    if(inputFunction == "extract") return extract;
    if(inputFunction == "insert") return insert;
    if(inputFunction == "change") return change;
    return invalid;
}