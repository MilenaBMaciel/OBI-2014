#include <bits/stdc++.h> 
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define dgb(x) cout << #x << " = " << x << endl

typedef long long ll;

int main(){ _ 
    int N, M; cin >> N >> M;

    int vetor[N], total=0, diferenca=0;
    for(int i=0; i<N; i++){ 
        cin >> vetor[i];
        vetor[i]+=diferenca;
        total+=abs(diferenca);
        diferenca = M-vetor[i];
    }
    cout << total << endl;

    return 0;
}
