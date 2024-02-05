#include <iostream>
#include <string>

using namespace std;

int main(){

    string fraseP, frase;
    
    getline(cin,fraseP);

    int tam;
    tam = fraseP.size();

    for(int i=1; i<tam; i+=2){
        cout << fraseP[i];
        if(i<tam-2 && fraseP[i+1]==' '){
            i++;
            cout << fraseP[i];
        }
    }

    cout << endl;

    return 0;
}