#include <bits/stdc++.h>
using namespace std;
#define dgb(x) cout << #x << " = " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

int main(){ _
    int F,R; cin >> F >> R;
    ll anterior,maior=0;
    for(int i=0; i<R; i++){
        ll a; cin >> a;
        if(i==0){ 
            if(a-1 > maior) maior = a-1;
            if(R==1&&F-a>maior) maior = F-a;
        }
        else if(i == R-1){
            if(F-a > maior) maior = F-a;
            if((int)(a-anterior)%2==0){
                if((int)(a-anterior)/2 > maior) maior = (int)(a-anterior)/2;
            }
            else{
                if(((int)(a-anterior)/2) > maior) maior = ((int)(a-anterior)/2);
            }
        } 
        else{
            if((int)(a-anterior)%2==0){
                if((int)(a-anterior)/2 > maior) maior = (int)(a-anterior)/2;
            }
            else{
                if(((int)(a-anterior)/2) > maior) maior = ((int)(a-anterior)/2);
            }
        }
        
        anterior=a;
    }
    cout << maior << endl;
    
    return 0;
}