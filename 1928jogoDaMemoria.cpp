#include <bits/stdc++.h> 
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define f first
#define s second
#define pb push_back

#define dgb(x) cout << #x << " = " << x << endl 
#define lli long long int


map<int, pair<int,int>> cor; //guarda o num das cartas com as posições em que se encontram

vector<vector<lli>> cartas; 
vector<lli> nivel;
vector<vector<lli>> pai;
lli l;

void dfs(lli a, lli b){
	
	
	for(int i = 1; i<=l; i++) pai[a][i] = pai[pai[a][i-1]][i-1];
	for(int v: cartas[a]){ 
		if(v != b){
			nivel[v] = nivel[a] + 1;
			pai[v][0] = a;
			dfs(v,a);
		}
	}
	
}

lli lca(lli a, lli b){
	if(nivel[a] < nivel[b]) swap(a,b);

	for(int i=l; i>=0; i--) if((nivel[a] - pow(2,i)) >= nivel[b]){
		a = pai[a][i];
	}

	if(a == b) return a;

	for(int i = l; i>=0; i--) if(pai[a][i] != pai[b][i]){
		a = pai[a][i];
		b = pai[b][i];
	}

	return pai[a][0];
}

int main(){_

	int n; cin >> n;
	lli total=0;

	l = (int)ceil(log2(n));
	pai = vector<vector<lli>> (n, vector<lli>(l+1));
	nivel = vector<lli>(n);
	cartas = vector<vector<lli>> (n);
	

	for(int i=0; i<n; i++){
		int a; cin >> a; 
		if(cor.find(a) == cor.end()) cor[a] = make_pair(i,-1);
		else cor[a].s = i;
	}

	for(int i=0; i<n-1; i++){
		int a,b; cin >> a >> b;
		
		cartas[a-1].pb(b-1);
		cartas[b-1].pb(a-1);
	}
    
	
	dfs(0,0);

	for(auto i: cor){
		total += nivel[i.s.f] + nivel[i.s.s] - nivel[lca(i.s.f, i.s.s)];
		
	}

    cout << total << endl; 
	
	return 0;
}