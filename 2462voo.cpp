#include <bits/stdc++.h> 
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define f first
#define s second
#define pb push_back

#define dgb(x) cout << #x << " = " << x << endl 


typedef pair<int, int> ii;

int main(){ _ 
    int hr[4];
    int v1,v2;
    
    for(int i=0; i<4; i++){
        int a, b;
        char c;
        cin >> a >> c >> b;
        hr[i] = a*60 + b;
    }
    if(hr[0] > hr[1]) v1 = 1440 - hr[0] + hr[1];
    else v1 = hr[1] - hr[0];

    if(hr[2] > hr[3]) v2 = 1440 - hr[2] + hr[3];
    else v2 = hr[3] - hr[2];
    
    int tvoo = ((v1+v2)/2);
    if(v1+v2>24*60) tvoo -= 12*60;
    int fuso = v1 - tvoo;
    if(abs(fuso)>12*60) fuso -=24*60;
    cout <<  tvoo << " " << fuso/60 << endl ;
    
    return 0;
}