#include <bits/stdc++.h> 
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);


#define dgb(x) cout << #x << " = " << x << endl


typedef pair<int, int> ii;


int main(){ _ 

    int n, m; cin >> n >> m;
    
    int erro;
    unordered_set<int> j1, j2;
    
    bool result=true;

    for (int i = 0; i < n; i++){
        int a; cin >> a;
        j1.insert(a);
    }
    
    for (int i = 0; i < m; i++){
        bool teste=false;
        int a; cin >> a;

        if(j1.find(a)!=j1.end()){
            teste=true;
            j2.insert(a);
        } 
        else if(a%2==0 && j2.find(a/2)!=j2.end()){
            j2.insert(a);
            teste=true;  
        } 
        else{
            for(auto i : j2){
                if(j2.find(a-i)!=j2.end()){
                    j2.insert(a);
                    teste=true;
                    break;
                }
            }
        }
        if(!teste && result){
            result = false;
            erro = a;
        } 
    }

    if(result) cout << "sim" << endl;
    else cout << erro << endl;

    
    return 0;
}