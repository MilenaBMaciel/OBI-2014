#include <iostream>
#include <string>

using namespace std;

int main(){
    int N, contador=0, maior=0;
    
    cin >> N;

    string mapa[N];

    //Armazena as entradas
    for(int i=0; i<N; i++){
        cin >> mapa[i];
    }

    //Le intercalando a direcao
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            //se a linha for par, le da esquerda para direita
            if(i%2==0){
                if(mapa[i][j]=='o')
                    contador++;
                else if(mapa[i][j]=='A')
                    contador=0;
            }

            //se a linha for impar, le da direita para esquerda
            else{
                if(mapa[i][N-j-1]=='o')
                    contador++;
                else if(mapa[i][N-j-1]=='A')
                    contador=0;
            }
            //verifica se o contador atingiu o maior
            if(contador>maior)
                maior=contador;
        }
        
    cout << maior <<endl;
    
    return 0;
}
