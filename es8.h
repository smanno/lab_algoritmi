/*
Esercizio 8 - array interval with given sum
Numero massimo di file: 3
Tipo di lavoro: Lavoro individuale

Scrivere un programma che riceva in input un array V di interi non-negativi (non necessariamente ordinati) e,
su una nuova riga, un intero S, e restituisca, se esiste, un intervallo [i,j] di posizioni nell'array V tale che
 V[i]+V[i+1]+…+V[j]=S.

Esempio:
input=5 0 3 1 13 7 5
17
output=2 4

Provare a implementare 2 versioni dell'algoritmo che abbiano i seguenti tempi asintotici di esecuzione:
- O(n logn),
- Θ(n).
 */
int sumInterval(vector<int>,int,int);

int es8arrayIntervalWithGivenSum(){
    cout << "Digitare una sequenza di numeri non negativi" << endl;
    vector<int> arrayOfNumbers;
    cin >> arrayOfNumbers;
    cout << "Digitare la somma di un intervallo da trovare" << endl;
    int key;
    cin >> key;

    int startIndex = 0;
    int endIndex = 0;

    if(!arrayOfNumbers.empty()) {
        int len = arrayOfNumbers.size();
        int sum = sumInterval(arrayOfNumbers, startIndex, endIndex);

        while (endIndex < len && sum != key) {
            if (arrayOfNumbers[startIndex] == 0) {
                startIndex++;
            } else if (sum < key) {
                endIndex++;
            } else {
                startIndex++;
                endIndex = startIndex;
            }
            sum = sumInterval(arrayOfNumbers, startIndex, endIndex);
        }
        if (sum != key) {
            startIndex = -1;
            endIndex = -1;
        }
    } else {
        startIndex = -1;
        endIndex = -1;
    }

    cout << startIndex << " " << endIndex << endl;
    return 0;
}

int sumInterval(vector<int> arrayOfNumbers, int index, int end){
    int sum = arrayOfNumbers[index];
    while(index<end){
        index++;
        sum = sum + arrayOfNumbers[index];
    }
    return sum;
}