#include <iostream>

using namespace std;

int main(){

    int N, M;

    cin >> N >> M;

    int matriz[N][M], uZ=-3, aZ=-1;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) cin >> matriz[i][j];
            
    
    for(int i=0; i<N; i++){
        aZ=-1;
        for(int j=0; j<M; j++){
            if(matriz[i][j]!=0){
                aZ=j;
                break;
            }
        }
        if(uZ>=aZ && aZ!=-1){
            cout << "N" << endl;
            return 0;
        }
        if(uZ==-1 && aZ > uZ){
            cout << "N" << endl;
            return 0;
        }
        uZ=aZ;
    }
    if(uZ==0 && aZ==0)
        cout << "N" << endl;
    else
        cout << "S" << endl;
        
    return 0;
}