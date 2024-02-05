#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    int bolas[N][N];
    for(int i=0; i<N; i++){
        cin >> bolas[0][i];
    }

    for(int i=1; i<N;i++)
        for(int j=0; j<N-i;j++){
            if(bolas[i-1][j]==bolas[i-1][j+1])
                bolas[i][j]=1;
            else
                bolas[i][j]=-1;
        }
    if(bolas[N-1][0]==1)
        cout << "preta" << endl;
    else 
        cout << "branca" << endl;

    return 0;
}