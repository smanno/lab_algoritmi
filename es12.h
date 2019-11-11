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

** Infine, provare a implementare una variante dell'algoritmo di selezione basata su heap (usare una heap ausiliaria,
 * ad esempio una min-heap, per estrarre in sequenza i primi k elementi dall'array ordinato). In quest'ultimo caso la
 * complessità asintotica nel caso pessimo e medio dovrebbe risultare O(klogk).
 * => perchè vado a lavorare sui primi k elementi tralasciando gli altri
 *
** Usando le heap senza HeapSort
 * -- uso k volte extract theta(k*logn)
 *
** Heap 2° limito heapify ad altezza 2^k
 * -- theta(k*log2^k) = theta(k^2)
 *
** Heap 3° in tempo O(k*logk) -> k estrazioni da una heap ausiliaria di puntatori
 * HeapA di dimensione n
 * HeapB di dimensione 0,1,2,...,2k (da vuota si riempie)
 * ad ogni iterazione inserisco due elementi
 */