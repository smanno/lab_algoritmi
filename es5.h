/*
Esercizio 5 - binary search
Numero massimo di file: 3
Tipo di lavoro: Lavoro individuale

Implementare in l'algoritmo binary search su array ordinati di interi.

Il programma deve ricevere
- un array ordinato di interi, rappresentato da una sequenza di numeri separati da spazi e terminata da "end of line",
- una chiave, rappresentata da un numero su una nuova riga
e deve ritornare
- la posizione della chiave nell'array, se esiste (0 = prima posizione)
- oppure -1 se la chiave non e' presente nell'array

La complessità asintotica dell'algoritmo dovrà essere O(log n).

Esempio:

input: 3 7 8 11 15 24
15
output: 4
 */
int BinarySearch(vector<int>,int,int,int);
int BetterBinarySearch(vector<int>,int);

int es5binarySearch() {
    cout << "Digitare una sequenza crescente di numeri" << endl;
    vector<int> arrayOrdinato;
    cin >> arrayOrdinato;
    cout << "Digitare il numero da trovare" << endl;
    int key;
    cin >> key;
    int len = arrayOrdinato.size();
    int start=0, end=len-1;
    int result = -1;
    while(start<=end){
        int index = (start+end)/2;
        if(arrayOrdinato[index]==key){
            result = index;
            break;
        }
        else if(arrayOrdinato[index]<key){
            start = index+1;
        }
        else{
            end = index-1;
        }
    }
    cout << result << endl;
    return 0;
}

int BinarySearch(vector<int> arrayOrdinato, int start, int end, int number){
    if(start==end) {
        if (arrayOrdinato[start] == number) {
            return start;
        } else {
            return -1;
        }
    } else {
        int index = (start+end)/2;
        if(arrayOrdinato[index]==number){
            return index;
        } else if(arrayOrdinato[index]>key){
            return binarySearch(arrayOrdinato, start, index-1, number);
        } else {
            return binarySearch(arrayOrdinato, index+1, end, number);
        }
    }
}

int Approssima(vector<int> arrayOrdinato, int number){
    int j=0;
    while(arrayOrdinato[j]<x){
        j=2*j;
    }
    return j;
}

int BetterBinarySearch(vector<int> arrayOrdinato, int number){
    int j = Approssima(arrayOrdinato, number);
    return BinarySearch(arrayOrdinato, j/2, j, number);
}