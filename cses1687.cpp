#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, q, t1, t2, bl[200001][20], dep[200001];
vector<int> e[200001];

void dfs(int g, int p, int d){
	bl[g][0] = p; dep[g] = d;
	for(int i = 1; i<=18; i++)
		bl[g][i] = bl[bl[g][i-1]][i-1];

	for(auto u : e[g]){
		if(u == p)continue;
		dfs(u, g, d+1);
	}
}

int jmp(int g, int k){
	for(int i = 18; i>=0; i--){
		if((1 << i) > k) continue;
		k -= (1 << i); g = bl[g][i];
	}

	return g;
}

int LCA(int a, int b){
	if(dep[a] < dep[b]) 
		swap(a, b);

	for(int i = 18; i>=0; i--){
		if(dep[bl[a][i]] < dep[b]) continue;
		a = bl[a][i];
	}

	if(a == b) return a;

	for(int i = 18; i>=0; i--){
		if(bl[a][i] == bl[b][i]) continue;
		a = bl[a][i]; b = bl[b][i];
	}

	return max(1,bl[a][0]);
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> q; dep[0] = 0;
	for(int i = 1; i<n; i++){
		cin >> t1 >> t2;
		e[t1].pb(t2);
		e[t2].pb(t1);
	}

	dfs(1, 0, 1);
	while(q--){
		cin >> t1 >> t2;
		int L = LCA(t1, t2);
		cout << (dep[t1] - dep[L]) + (dep[t2] - dep[L]) << endl;
	}

	cout.flush();
	return 0;
}