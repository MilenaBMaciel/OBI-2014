#include <iostream>

using namespace std;


int procura(int *vetor, int *bandeiras, int N, int i, int j){
    int contador=0;

    //for(int i=0; i<N*N; i++)
    //    cout << vetor[i] << " ";

    /*cout << "num: "<< vetor[N*i+j] << endl;
    cout << "lado: "<< vetor[N*i+(j+1)] << endl;
    cout << "baixo: "<< vetor[N*(i+1)+j] << endl;
    cout << "outrolado: "<< vetor[N*i+(j-1)] << endl;
    cout << "cima: "<< vetor[N*(i-1)+j] << endl;
    */

    if((j<N-1)&&(vetor[N*i+(j+1)]>=vetor[N*i+j])&&(bandeiras[N*i+(j+1)]==0)){
        bandeiras[N*i+(j+1)]=1;
        contador+= procura(vetor,bandeiras, N,i,j+1);
        contador++;
    }
    if((i<N-1)&&(vetor[N*(i+1)+j]>=vetor[N*i+j])&&(bandeiras[N*(i+1)+j]==0)){
        bandeiras[N*(i+1)+j]=1;
        contador+= procura(vetor,bandeiras, N,i+1,j);
        contador++;
    }
    if((j>0)&&(vetor[N*i+(j-1)]>=vetor[N*i+j])&&(bandeiras[N*i+(j-1)]==0)){
        bandeiras[N*i+(j-1)]=1;
        contador+= procura(vetor,bandeiras, N,i,j-1);
        contador++;
    }
    if((i>0)&&(vetor[N*(i-1)+j]>=vetor[N*i+j])&&(bandeiras[N*(i-1)+j]==0)){
        bandeiras[N*(i-1)+j]=1;
        contador+= procura(vetor,bandeiras, N,i-1,j);
        contador++;
    }
    
    return contador;
}
int main(){
    
    int N, I, J, contador=1;

    cin >> N;
    cin >> I >> J;
    
    I -= 1;
    J -= 1;

    int vetor[N*N], bandeiras[N*N];

    for(int i=0; i<N*N; i++)
        cin >> vetor[i];
    
    for(int i=0; i<N*N; i++)
        bandeiras[i]=0;

    
    bandeiras[N*I+J]=1;
    contador += procura(vetor, bandeiras, N, I, J);
    cout << contador << endl;

    return 0;
}