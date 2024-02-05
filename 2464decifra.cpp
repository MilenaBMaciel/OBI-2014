#include <iostream>
#include <string>

using namespace std;

int main(){
    string frase, cript;
    string alf ("abcdefghijklmnopqrstuvwxyz");
    int tamF;
    
    getline(cin,cript);
    getline(cin,frase);

    tamF = frase.size();

    
    for(int i=0; i<tamF; i++)
        for(int j=0; j<26; j++)
            if(frase[i] == cript[j]){
                frase[i] = alf[j];
                break;
            }
    
    cout << frase << endl;
    return 0;
}