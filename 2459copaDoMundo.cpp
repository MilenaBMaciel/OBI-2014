#include <bits/stdc++.h> 
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define f first
#define s second
#define pb push_back

#define dgb(x) cout << #x << " = " << x << endl


typedef pair<int, int> ii;
vector<int> id, sz;
int find(int x){
    return id[x] = (id[x] == x? x : find(id[x]));
}
void uni(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return;
    if(sz[x] > sz[y]) swap(x,y);
    id[x] = y;
    sz[y] += sz[x];
}

int main(){ _ 
    int n, f, r; cin >> n >> f >> r;
    vector< pair<int, pair<int,int> > > fer, rod;

    id = vector<int> (n+1);
    sz = vector<int> (n+1,1);
    iota(id.begin(), id.end(), 0);

    for(int i=0; i < f; i++){
        int a, b, custo; cin >> a >> b >> custo;
        fer.pb(make_pair(custo, make_pair (a, b)));
    }
    sort(fer.begin(), fer.end());
    for(int i=0; i < r; i++){
        int a, b, custo; cin >> a >> b >> custo;
        rod.pb(make_pair(custo, make_pair (a, b)));
    }
    sort(rod.begin(), rod.end());
    fer.insert(fer.end(), rod.begin(), rod.end());
    int tot=0;
    
    for(auto i : fer){
        
        if(find(i.second.first) !=  find(i.second.second)){
            uni(i.second.first,i.second.second);
            tot += i.first;
        }
    }
    cout << tot << endl;
    return 0;
}