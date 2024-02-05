#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define f first
#define s second
#define pb push_back

int main(){ _
    int nCasa; cin >> nCasa;
    int nEnc; cin >> nEnc;

    vector<int> casas;
    casas.pb(0);
    for(int i=1; i<=nCasa; i++){
        int a; cin >> a;
        casas.pb(a);
    }

    //vector<int> encs;
    int soma=0, indiceAnt=1;

    for(int i=0; i<nEnc; i++){
        int a; cin >> a;
        int indice=1;
        while(a!=casas[indice]) indice++;
        soma+= abs(indice-indiceAnt);
        indiceAnt = indice;
    }
    cout << soma << endl;

    return 0;
}