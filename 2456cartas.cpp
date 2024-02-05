#include <iostream>

using namespace std;

int main(){
    int cartas[5], testOrdem=0;

    for(int i=0; i<5; i++)
        cin >> cartas[i];
    
    for(int i=1; i<5; i++){
        if(cartas[i]>cartas[i-1])
            testOrdem++;
        else
            testOrdem--;
    }
    
    if(testOrdem==4)
        cout << "C" << endl;
    else if(testOrdem==-4)
        cout << "D" << endl;
    else
        cout << "N" << endl;
}