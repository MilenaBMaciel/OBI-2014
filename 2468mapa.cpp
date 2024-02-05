#include <bits/stdc++.h> 
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define f first
#define s second
#define pb push_back
#define lli long long int

#define dgb(x) cout << #x << " = " << x << endl


typedef pair<int, int> ii;

vector<lli> id, sz;

int find(lli x){
    return id[x] = (id[x] == x? x : find(id[x]));
}

void uni(lli x, lli y){
    x = find(x);
    y = find(y);

    if(x == y) return ; //se os dois estão apontando pro mesmo id
    if(sz[x] > sz[y]) swap(x,y); // a menor árvore que se anexa à maior sempre 

    id[x] = y;
    sz[y] += sz[x];
    
}
int main(){ _ 
    lli n; cin >> n;
    vector<pair<lli,pair<lli,lli>>> ruas;
    
    id = vector<lli> (n+1);
    sz = vector<lli> (n+1,1); //todos os sz =1 no inicio
    iota(id.begin(), id.end(),0); //inicializando o id

    for(lli i=0; i<n-1; i++){
        lli a, b, status; cin >> a >> b >> status;
        ruas.pb(make_pair(status,make_pair(a,b))); 
    }
    
    lli res = 0;
    for(auto i: ruas){
        if(find(i.s.f) != find(i.s.s) && i.f == 0){ //só adiciona as ruas não importantes
            uni(i.s.f,i.s.s);
        }
    }
    for(int i=1; i <= n; i++){
        if(id[i]==i){ //verifica somente os "representantes" das diversas arvores formadas
            res += (n - sz[i])* sz[i]; 
        }
    }
    cout << res/2 << endl;
    
    return 0;
}