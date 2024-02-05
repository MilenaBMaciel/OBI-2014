#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);


const int INF = 0x3f3f3f3f;

int main (){
    int N, valor;
    cin >> N;

    vector<int> corredor;

    for(int i=0; i<N; i++){
        cin >> valor;
        corredor.push_back(valor);
    }

    int somaMax = -INF, soma_anterior = -INF; //começa com "-infinito" sendo o menor num possível
    
    for(int i=0; i<N; i++){
        if(soma_anterior < 0) soma_anterior = corredor[i];
        else soma_anterior += corredor[i];
        somaMax = max(soma_anterior, somaMax);
    }
    cout << somaMax << endl;
    return 0;
}