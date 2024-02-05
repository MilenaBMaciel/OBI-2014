#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int N, I, J, I2;
    cin >> N;

    int quad[N][N], sLinha[N], sColuna[N];

    for(int i=0; i<N; i++){
        sLinha[i]=0;
        sColuna[i]=0;
    }

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> quad[i][j];

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            sLinha[i] += quad[i][j];
            sColuna[j] += quad[i][j];
        }
    
    for(int i=0; i<N; i++){
        if(i == 0){
            if(sLinha[i]!=sLinha[i+1] && sLinha[i]!=sLinha[i+2]){
                I=i;
                I2=i+1;
            }   
            if(sColuna[i]!=sColuna[i+1] && sColuna[i]!=sColuna[i+2])
                J=i; 
        }
        else if(i == N-1){
            if(sLinha[i]!=sLinha[i-1] && sLinha[i]!=sLinha[i-2]){
                I=i;
                I2=i-1;
            }
            if(sColuna[i]!=sColuna[i-1] && sColuna[i]!=sColuna[i-2])
                J=i;
        }
        else{
            if(sLinha[i]!=sLinha[i-1] && sLinha[i]!=sLinha[i+1]){
                I=i;
                I2=i+1;
            }
            if(sColuna[i]!=sColuna[i-1] && sColuna[i]!=sColuna[i+1])
                J=i;
        }
    }       
    cout << abs(sLinha[I2]-(sLinha[I]-quad[I][J])) << " ";
    cout << quad[I][J] << endl;

    return 0;
}