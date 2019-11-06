//
// Created by stefano on 04/11/2019.
//
/*
Esercizio 9 - majority
Numero massimo di file: 3
Tipo di lavoro: Lavoro individuale

Scrivere un programma che riceva in input un array (non necessariamente ordinato) di interi di lunghezza arbitraria n
e restituisca in output, se esiste, l'elemento dell'array che occorre almeno ⌊n2⌋+1 volte. Se tale elemento non esiste,
l'algoritmo dovrà stampare la stringa "No majority".

Esempi:
input=5 0 3 1 13 7 5
output=No majority

input=5 0 3 0 5 0 0
output=0

Provare a implementare 2 versioni dell'algoritmo che abbiano i seguenti tempi asintotici di esecuzione:

- O(n2),
- Θ(n).
 */

void majority(vector<int>);
int possiblyMajorityCandidate(vector<int>);

int es9majority(){
    vector<int> arrayNumeri;
    cin >> arrayNumeri;
    majority(arrayNumeri);
    return 0;
}

void majority(vector<int> arrayNumeri){
    int majorityCandidate = possiblyMajorityCandidate(arrayNumeri);
    int counter = 0;
    int atLeast = arrayNumeri.size()/2 +1;
    for(int i=0; i<arrayNumeri.size(); i++){
        if(arrayNumeri[i]==majorityCandidate)
            counter++;
    }
    if(counter>=atLeast){
        cout << majorityCandidate << endl;
    } else {
        cout << "No majority" << endl;
    }
    //return 0;
}

int possiblyMajorityCandidate(vector<int> arrayNumeri){
    int counter = 0;
    int majorityCandidate = 0;
    for(int i=0; i<arrayNumeri.size(); ++i){
        if(counter==0){
            majorityCandidate = arrayNumeri[i];
            counter=1;
        } else {
            if(arrayNumeri[i]==majorityCandidate){
                counter++;
            } else {
                counter--;
            }
        }
    }
    return majorityCandidate;
}
