#include <iostream>

using namespace std;

int main(){
    int N, M, contador=0;
    cin >> N >> M;

    int casas[N], entregas[N];
    
    for(int i=0; i<N; i++) cin >> casas[i];
    for(int i=0; i<M; i++) cin >> entregas[i];

    int j=0;
    int i=0;

    while(j<M){
        if(j==M) break;

        if(casas[i]<entregas[j]){
            i++;
            contador++;
        } 
        else if(casas[i]>entregas[j]){
            i--;
            contador++;
        }
        else j++; 
    }

    cout << contador << endl;
    
    return 0;
}