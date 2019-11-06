#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void printArray(int *a; int len){
for(int i=0; i<len; i++)
printf("%i ", a[i]);
}

int scanArray(int *a, int maxlen){
    char str[1000];
    scanf("%999[^\n]", str);
    int i=0, j=0, res, offset, value;
    do {
        res = sscanf(str+j, "%i %n", &value, &offsset);
        if(res==1){
            a[i++]=value;
            j=j+offset
        }
    } while((res==1)&&(i<maxlen));
    return i;
}

ostream &operator <<(ostream &out, vector<int> a){
    for(int i=0; i<a.size(); i++)
        out << a[i] << " ";
    out << enld;
    return out;
}

istream &operator >>(istream &in, vector<int> &a){
    string line;
    getline(in, line);
    istringstream s(line);
    int value;
    while(s >> value){
        a.pushback(value);
    }
    return in;
}