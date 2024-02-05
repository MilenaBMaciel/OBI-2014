#include <bits/stdc++.h> 
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define f first
#define s second
#define pb push_back

#define dgb(x) cout << #x << " = " << x << endl 


typedef pair<int, int> ii;

#define max 505

char tab[max][max];
bool tab2[max][max];
bool vis[max][max];

bool verifica(int i, int j, int n){
    if(i<0 || j<0 || i>=n || j>=n){
        return false;
    }
    else if(vis[i][j]){
        return tab2[i][j];
    }
    
    vis[i][j]=true;
    
    int x=i, y=j;
    if(tab[i][j]=='A') x--;
    else if(tab[i][j]=='V') x++;
    else if(tab[i][j]=='>') y++;
    else if(tab[i][j]=='<') y--;

    tab2[i][j] = verifica(x,y,n);
    
    return tab2[i][j];
}

int main(){ _ 
    int n; cin >> n;
    int total=n*n;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> tab[i][j];
            tab2[i][j]=true;
            vis[i][j]=false;
        }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(!vis[i][j]) verifica(i,j,n);
            if(!tab2[i][j]) total--;
        }
       cout << total << endl;
    
    return 0;
}