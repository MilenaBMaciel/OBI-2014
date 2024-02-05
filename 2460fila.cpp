#include <bits/stdc++.h> 
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define f first
#define s second
#define pb push_back

#define dgb(x) cout << #x << " = " << x << endl 


typedef pair<int, int> ii;

int main(){ _ 
    int N; cin >> N;
    map<int,int> fila;
    for(int i=0;i<N;i++){
        int a; cin >> a;
        fila[a]=i;
    }
    int M; cin >> M;
    for(int i=0;i<M;i++){
        int a; cin >> a;
        fila.erase(a);
    }
    
    map<int,int> fila2;
    for(auto i : fila) {
       fila2[i.second]=i.first;
    }
    int a=0;
    for(auto i : fila2) {
       cout << i.second;
        if(!(a == N-M-1))cout << " ";
        a++;
    }
    cout << endl;

	return 0;
}