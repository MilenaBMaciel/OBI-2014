#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

struct BIT {
	int tree[110000];
	
	void add(int idx, int delta) { 
		while (idx <= 100100) { //esse 100100 é como o tamanho do vetor com uma sobra, já que ele pode ir até 10^5
			tree[idx] += delta; //add o valor delta na posição idx do vetor
			idx += idx&-idx; //vai add em idx com a conta de fenwick para apenas os elementos influenciados seja alterado
		}
	}

	int read(int idx) { //tem uma árvore 
		int s = 0;
		while (idx > 0) { 
			s += tree[idx]; //s é a soma de todos os elementos afetados pelo idx
			idx -= idx&-idx; //le de tras pra frente
		}
		return s;
	}
};

int n, q, op, x, rr;
int treeColuna[110000];
int treeLinha[110000];
pair<int, int> ultLinha[110000], ultColuna[110000]; //recebe quando a op foi feita e o valor colocado

BIT ColunaFreq[51], LinhaFreq[51]; //uma árvore pra cada um dos 50 números possiveis, e recebe os i de quando apareceram
int temp[51];

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= q; i++) {
		int best = -1;
		int best_val = -1;
		int temp = 0;
		int tot = 0;

		scanf("%d %d", &op, &x);
		if (op == 1) {  //atribuir o valor rr aos elementos da linha x 
			scanf("%d", &rr);
			if (ultLinha[x].first != 0) //se já ter acontecido op nessa linha antes
				ColunaFreq[ultLinha[x].second].add(ultLinha[x].first, -1); //a arvore ColunaFreq[valor colocado em x anteriormente] adiciona quando a ultima op aconteceu e -1
			//acredito que essas duas linhas anteriores seja pra "apagar" o valor colocado em x anteriormente

            ultLinha[x] = make_pair(i, rr); //ultLinha[x (linha alterada)] recebe quando a op foi feita e o valor colocado em x
			ColunaFreq[rr].add(i, 1); //ColunaFreq[valor novo colocado em x] adiciona quando a op foi feita e 1
		}
		else if (op == 2) {
			scanf("%d", &rr);
			if (ultColuna[x].first != 0) //se já ter acontecido op nessa coluna antes
				LinhaFreq[ultColuna[x].second].add(ultColuna[x].first, -1); //a arvore LinhaFreq[valor colocado na coluna antes] adiciona quando a ultima op aconteceu e -1
			ultColuna[x] = make_pair(i, rr);// ultColuna[x (coluna alterada)] recebe quando a op foi feita e o valor colocado em x
			LinhaFreq[rr].add(i, 1); //LinhaFreq[novo valor colocado em x] adiciona quando a op foi feita e 1
		}
		else if (op == 3) {
			for (int val = 0; val <= 50; val++) if (val != ultLinha[x].second) { //se val é diferente do último valor colocado na linha x
				//o cnt será a soma da freq daquele valor no intervalo do i atual até o i de quando o num foi inserido na matriz pela última vez
				int cnt = LinhaFreq[val].read(i) - LinhaFreq[val].read(ultLinha[x].first);
				tot += cnt; //esse total vai sendo incrementado com a quantidade de vezes em que as colunas foram alteradas

				if (cnt >= best) { //verifica qual numero apareceu mais vezes e quantas vezes ele apareceu
					best = cnt;
					best_val = val;
				}
			}
			//Quando o tamanho do tabuleiro - num de operações na colunas, ou seja, quantas colunas não foram modificadas, for maior que a freq do num que apareceu mais vezes
			//ou, se o num de colunas não modificadas for igual a maior freq. mas o maior num for o valor colocado na linha anteriormente
			//o maior valor frequente na linha será o colocado nela diretamente
			if (n-tot > best || (n-tot == best && best_val < ultLinha[x].second)) {  
				best_val = ultLinha[x].second;
			}

			printf("%d\n", best_val);
		}
		else if (op == 4) {
			for (int val = 0; val <= 50; val++) if (val != ultColuna[x].second) {
				int cnt = ColunaFreq[val].read(i) - ColunaFreq[val].read(ultColuna[x].first);
				tot += cnt;

				if (cnt >= best) {
					best = cnt;
					best_val = val;
				}
			}

			if (n-tot > best || (n-tot == best && best_val < ultColuna[x].second)) {
				best_val = ultColuna[x].second;
			}

			printf("%d\n", best_val);
		}
	}
}
