#include <iostream>

using namespace std;

int main(){

    int v1[6], v2[6];
    int contador=0;

    for(int i=0; i<6; i++)
        cin >> v1[i];

    for(int i=0; i<6; i++)
        cin >> v2[i];

    for(int i=0; i<6; i++)
        for(int j=0; j<6; j++)
            if(v1[i]==v2[j])
                contador++;
    if(contador==3)
        cout << "terno" << endl;
    else if(contador==4)
        cout << "quadra" << endl;
    else if(contador==5)
        cout << "quina" << endl;
    else if(contador==6)
        cout << "sena" << endl;    
    else 
        cout << "azar" << endl;

    return 0;
}