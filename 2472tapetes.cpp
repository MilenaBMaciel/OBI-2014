#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;

int main(){ //_

    int N, L; cin >> L >> N;
    
    int maiorTam = L - N + 1;
    ll area = (ll)maiorTam*maiorTam + (N-1);
    cout << area << endl;
    
    return 0;
}