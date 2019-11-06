/*
Esercizio 10 - sort
        Numero massimo di file: 3
Tipo di lavoro: Lavoro individuale

Implementare uno o più algoritmi di ordinamento (quick sort, merge sort, heap sort, selection sort, insertion sort,
bubble sort, ...) su array di interi. Il programma deve ricevere in input una sequenza di interi separati da spazio e
deve produrre in output la sequenza ordinata.

Esempio:
input=7 3 11 5
output=3 5 7 11
 */

using namespace std;

void insertionSort(vector<int>&);
void mergeSort(vector<int>&,int,int);
void merge(vector<int>&,int,int,int);
void quickSort(vector<int>&,int,int);
int partition(vector<int>&,int,int);

int es10sort(){
    vector<int> arrayOfNumbers;
    cin >> arrayOfNumbers;
    //insertionSort(arrayOfNumbers);
    int len = arrayOfNumbers.size();
    mergeSort(arrayOfNumbers,0,len-1);
    //quickSort(arrayOfNumbers,0,len-1);      // len-1 visto che non è pseudocodice
    cout << arrayOfNumbers << endl;
    return 0;
}

    // INSERTION SORT
void insertionSort(vector<int> &arrayOfNumbers){
    int i=1, j=0, key=0;
    while(i<arrayOfNumbers.size()){
        key = arrayOfNumbers[i];
        j = i-1;
        while(j>=0 && arrayOfNumbers[j]>key){
            arrayOfNumbers[j+1]=arrayOfNumbers[j];
            j--;
        }
        arrayOfNumbers[j+1]=key;
        i++;
    }
}

    // MERGE SORT
void mergeSort(vector<int> &arrayOfNumbers, int start, int end){
    if(start<end){
        int index = (start+end)/2;
        mergeSort(arrayOfNumbers,start,index);
        mergeSort(arrayOfNumbers,index+1,end);
        merge(arrayOfNumbers,start,end,index);
    }
    return;
}
/*
 * ci sono errori gravi
 */
void merge(vector<int> &arrayOfNumbers, int start, int end, int index){
    vector<int> copyArray = arrayOfNumbers;
    for(int k=start; k<=end; k++){
        if(copyArray[start] <= copyArray[index]){
            arrayOfNumbers[k] = copyArray[start];
            start++;
        } else {
            arrayOfNumbers[k] = copyArray[index];
            index++;
        }
    }
    return;
}

    // QUICK SORT
void quickSort(vector<int> &arrayOfNumbers, int start, int end){
    if(start<end){
        int index = partition(arrayOfNumbers,start,end);
        quickSort(arrayOfNumbers,start,index-1);
        quickSort(arrayOfNumbers,index+1,end);
    }
    return;
}

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