#include <iostream>

using namespace std;

int main(){
    int N, aux, cont, cont2;
    cin >> N;
    
    int vetor[N];
    for(int i=0; i<N; i++)
        cin >> vetor[i];
    
    for(int i=0; i<N; i++)
        for(int j=i; j<N; j++){
            if(vetor[i]>vetor[j]){
                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
        }
    cont=0;
    cont2=0;
    aux=0;
    for(int i=0; i<N; i++){
        cont++;
        
        if(vetor[i]!=vetor[i+1]){
            if(cont>=cont2){
                cont2=cont;
                aux=vetor[i];
            }
            cont=0;
        }
        
    }

    cout << aux << endl;
    

    return 0;
}