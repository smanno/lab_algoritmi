//
// Created by stefano on 10/12/2019.
//

//using namespace std;
using namespace std::chrono;

    /** modificare le costanti a seconda delle esigenze */
const int DIMENSIONEMAX = 2; // inteso come 10^DIMENSIONEMAX, es 3 avrò vettori da 10, 100, 1000 elementi
const int VETTORIPERDIMENSIONE = 5; // quanti vettori per ognuna delle categorie (10,100,1000...)
const int TESTPERINDICE = 5; // quanti test effettuare per ogni singolo K
    /** scegliere quale unità di tempo usare */
//typedef std::chrono::milliseconds unitaTempo;
//typedef std::chrono::microseconds unitaTempo;
typedef std::chrono::nanoseconds unitaTempo;

vector<int> inizializzaVettore(int);
vector<int> testaAlgoritmo(vector<int>,int);
int calcolaMedia(vector<int>);
vector<int> calcolaDeviazione(vector<int>,int);
float calcolaDeviazioneStandard(vector<int>,int,int);
void stampaTest(ofstream&,int,int,int,float,vector<int>,vector<int>);

//finding median of the ungrouped data in the array
int findMedian(vector<int> vect){
    //sort the array
    sort(vect.begin(), vect.end());
    if(vect.size() % 2 == 0)
        return (vect[vect.size()/2 - 1] + vect[vect.size()/2])/2;
    return vect[vect.size()/2];
}

void stimaTempiOld(){
    std::ofstream myfile;
    myfile.open ("stimaTempiOld.csv");
    for(int i=1;i<=DIMENSIONEMAX;i++){
        for(int j=0;j<VETTORIPERDIMENSIONE;j++) {
            myfile<<"vettore num "<<j;
            int N = pow(10,i);
                /** crea un vettore con N numeri random() */
            vector<int> vettoreCasuale = inizializzaVettore(N);
            for(int K=0; K < N; K++) {
                    /** crea un vettore con i tempi impiegati nei test */
                vector<int> vettoreTempi = testaAlgoritmo(vettoreCasuale, K);
                    /** calcola il tempo medio */
                int tempoMedio = calcolaMedia(vettoreTempi);
                    /** calcola la deviazione per ogni tempo */
                vector<int> vettoreDeviazione = calcolaDeviazione(vettoreTempi, tempoMedio);
                    /** calcola la deviazione standard */
                float deviazioneStandard = calcolaDeviazioneStandard(vettoreTempi, tempoMedio, N);
                    /** stampa i dati sul file csv */
                stampaTest(myfile,N,K,tempoMedio,deviazioneStandard,vettoreTempi,vettoreDeviazione);
            }
        }
    }
    myfile.close();
}

vector<int> inizializzaVettore(int N){
    vector<int> vettoreCasuale;
    for(int i=0; i < N; i++){
        int temp = rand()%((N+1)*10);           // genero un valore da 0 a N*10 compresi
        if(rand()<0.4){ temp=-1*temp; }         // 40% dei valori sarà negativo
        vettoreCasuale.push_back(temp);
    }
    return vettoreCasuale;
}

vector<int> testaAlgoritmo(vector<int> vettore, int K){
    vector<int> vettoreTempi;
    for(int i=0;i<TESTPERINDICE;i++){
        vector<int> vettoreCasuale = vettore;
        //auto start = chrono::steady_clock::now();
        steady_clock::time_point start = /**chrono::*/steady_clock::now();

            /** scegliere quale funzione testare */
        //sort(vettoreCasuale.begin(), vettoreCasuale.end());
        quickSelect(vettoreCasuale,K);
        //heapSelect(vettoreCasuale,K);
        // medianSelect

        auto stop = chrono::steady_clock::now();
        duration<float> period = stop-start;
        auto durationNano = duration_cast<unitaTempo>(period);
        vettoreTempi.push_back(durationNano.count());
    }
    return vettoreTempi;
}

int calcolaMedia(vector<int> vettore){
    int measures = vettore.size(), total = 0;
    while(!vettore.empty()){
        total = total + vettore.back();
        vettore.pop_back();
    }
    return total/measures;
}

vector<int> calcolaDeviazione(vector<int> vettoreTempi,int tempoMedio){
    vector<int> vettoreDeviazione;
    for(int i=0; i<vettoreTempi.size(); i++){
        int deviazione = abs(vettoreTempi[i]-tempoMedio);
        vettoreDeviazione.push_back(deviazione);
    }
    return vettoreDeviazione;
}

float calcolaDeviazioneStandard(vector<int> vettoreTempi,int tempoMedio,int N){
    float a=0, b=0;
    a=1.0/(N-1);
    for(int i=0;i<N;i++) {
        b = b + pow((vettoreTempi[i] - tempoMedio), 2);
    }
    return sqrt(a*b);
}

void stampaTest(ofstream &myfile,int N,int K,int tempoMedio,float deviazioneStandard,vector<int> vettoreTempi,vector<int> vettoreDeviazione){
    myfile<<"\nN: "<<N<<";K: "<<K+1<<";";
    for(int m=0;m<TESTPERINDICE;m++){
        myfile<<"T"<<m+1<<": "<<vettoreTempi[m]<<";";
    }
    myfile<<";V.medio: "<<tempoMedio<<"\n;;";
    for(int n=0;n<TESTPERINDICE;n++){
        myfile<<"D"<<n+1<<": "<<vettoreDeviazione[n] << ";";
    }
    myfile<<";Dev.Standard: "<<deviazioneStandard<<"\n";
}