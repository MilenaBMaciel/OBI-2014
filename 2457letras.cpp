#include <iostream>
#include <string>
#include <iomanip> //precisa disso pra imprimir um numero com casa decimal

using namespace std;

int main(){
    string frase, letra;
    int contador=0, tam, numPalavras=1, ultimoNumPalavraComLetra=0;

    getline(cin,letra);
    getline(cin,frase);

    tam = frase.size();
    
    for(int i=0; i<tam; i++){
        
        //verifica quantas palavras a frase tem
        if(frase[i]==' ')
            numPalavras++;

        //caso a última palavra a ter a letra especificada seja a ultima contadas
        //siginifica que a palavra tem essa letra mais de uma vez, então não deve ser contado outra vez
        if(frase[i]==letra[0] && ultimoNumPalavraComLetra!=numPalavras){
            contador++;
            ultimoNumPalavraComLetra = numPalavras;
        }
    } 
    
    // o fixed e setprecision é para imprimir o num com casa decimal
    cout << fixed << setprecision(1) << ((float)(contador*100)/numPalavras) << endl;
    return 0;
}