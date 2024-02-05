#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> lados(4);

    int N=0, i=0;

    for(int i=0; i<4; i++)
        cin >> lados[i];
    
    while(i<4){
        if((lados[0]+lados[1]>lados[2])&&(lados[1]+lados[2]>lados[0])&&(lados[0]+lados[2]>lados[1])){
            cout << "S" << endl;
            N=1;
            break;
        }
        lados.insert(lados.begin(), lados.back());  
        lados.pop_back();
        i++;
    }

    if(N==0)
        cout << "N" << endl;
            
    return 0;
}