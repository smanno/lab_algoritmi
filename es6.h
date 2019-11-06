/*
Esercizio 6 - pair of positions with given sum
Numero massimo di file: 3
Tipo di lavoro: Lavoro individuale

Scrivere un programma che riceva in input un array V ordinato di interi e, su una nuova riga, un ulteriore intero S.
Il programma deve restituire una qualunque coppia ordinata (i,j) di posizioni nell'array V tale che i<j e V[i]+V[j]=S.
Se una tale coppia (i,j) di interi non esiste, il programma deve segnalare il caso ritornando la coppia (−1,−1).
Nota: le coppie di interi dovranno essere stampate in output senza parentesi né virgola (ad es. -1 -1).

Esempio:
input: 3 7 8 11 15 24
23
output: 2 4

Provare a implementare 3 versioni dell'algoritmo che abbiano i seguenti tempi asintotici di esecuzione:
- O(n2),
- O(n log n)
- O(n).
*/

int es6pairOfPositionsWithGivenSum(){
    cout << "Digitare una sequenza crescente di numeri" << endl;
    vector<int> arrayOrdinato;
    cin >> arrayOrdinato;
    cout << "Digitare la somma da trovare" << endl;
    int sum;
    cin >> sum;

    int firstIndex = -1;
    int secondIndex = -1;
    int i=0;
    int j=arrayOrdinato.size()-1;

    while(i<j && arrayOrdinato[i]+arrayOrdinato[j]!=sum){
        if(arrayOrdinato[i]+arrayOrdinato[j]>sum){
            --j;
        } else {
            ++i;
        }
    }
    if(i<j && arrayOrdinato[i]+arrayOrdinato[j]==sum){
        firstIndex = i;
        secondIndex = j;
    }

    cout << firstIndex << " " << secondIndex << endl;
    return 0;
}