#include <bits/stdc++.h> 
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define f first
#define s second
#define pb push_back
#define ii pair<int,int>
#define mp make_pair

#define dgb(x) cout << #x << " = " << x << endl


struct arvFen {
	int arv[100100];
	
	void add(int i) { 
		while (i <= 100100) { //esse 100100 é como o tamanho do vetor com uma sobra, já que ele pode ir até 10^5
			arv[i] += 1; //add o valor novo na posição i do vetor
			i += i&(-i); //vai add em i com a conta de fenwick para apenas os elementos influenciados seja alterado
		}
	}
    void remove(int i){
        while(i<-100100){
            arv[i] -= 1;
            i += i&(-i);
        }
    }

	int le(int i) {  
		int freq = 0;
		while (i > 0) { 
			freq += arv[i]; //soma de todos os elementos
			i -= i&-i; //le os bits de tras pra frente
		}
		return freq;
	}
};

arvFen vLinha[51], vColuna[51]; //uma arvore para cada num possivel nas linhas colunas

//vai guardar quando a ultima alteração foi feita na posicao da linha e qual o valor que foi colocado ali
vector<ii> alteraLinhas, alteraColunas; //alteracoes nas linhas afetam as colunas e vice-versa


int main(){ _ 
    int n, q; cin >> n >> q;
    int op, lc, valor;
    int maisFreq, valorFreq, cont;
    alteraLinhas = vector<ii> (n+10);
    alteraColunas = vector<ii> (n+10);
    for (int i = 0; i <= n; i++)
        alteraLinhas[i] = alteraColunas[i] = mp(0, 0);
    
    vector<int> result;

    for(int i=0; i<q; i++){
        cin >> op >> lc;
        maisFreq=0;
        valorFreq=0;
        cont=0;
        switch(op){
            case 1:
                cin >> valor;
                if(alteraLinhas[lc].s != 0) vColuna[valor].remove(alteraLinhas[lc].f); //remove o valor
                alteraLinhas[lc]=mp(i,valor);
                vColuna[valor].add(i);
            break;
            case 2:
                cin >> valor;
                if(alteraColunas[lc].s != 0) vLinha[valor].remove(alteraColunas[lc].f); //remove o valor
                alteraColunas[lc]=mp(i,valor);
                vLinha[valor].add(i);
            break;
            case 3:
                for(int j=1;j<52;j++){
                    if(alteraLinhas[lc].s!=j){
                        int freq = vColuna[j].le(i) - vColuna[j].le(alteraLinhas[lc].f); 
                        cont += freq;
                        if(freq>=maisFreq){
                            valorFreq = alteraLinhas[lc].s;
                            maisFreq = freq;
                        }
                    }
                }
                if(n-cont>maisFreq || (n-cont==maisFreq&&valorFreq<alteraLinhas[lc].s)){
                    valorFreq = alteraLinhas[lc].s;
                }
                result.pb(maisFreq);
            break;
            case 4:
                for(int j=1;j<52;j++){
                    if(alteraColunas[lc].s!=j){
                        int freq = vLinha[j].le(i) - vLinha[j].le(alteraColunas[lc].f); 
                        cont += freq;
                        if(freq>=maisFreq){
                            valorFreq = alteraColunas[lc].s;
                            maisFreq = freq;
                        }
                    }
                }
                if(n-cont>maisFreq || (n-cont==maisFreq&&valorFreq<alteraColunas[lc].s)){
                    valorFreq = alteraColunas[lc].s;
                }
                result.pb(maisFreq);

            break;
        }
        
    }
    int tam = result.size();
    for(int i=0; i<tam; i++) cout << result[i] << endl;
    return 0;
}