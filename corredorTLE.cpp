#include <iostream>

using namespace std;

int main(){

    int N, soma, maior=0;
    cin >> N;

    int vetor[N];

    for(int i=0; i<N; i++)
        cin >> vetor[i];
    
    for(int j=0; j<N; j++){
        soma = 0;
        for(int i=j; i<N; i++){
            soma+=vetor[i];
            maior = soma>maior? soma : maior;
        }
    }
    cout << maior << endl;

    return 0;
}