#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, m, t1, t2, v[100001];
vector<int> e[100001], topo;
bool cyc = 0;

void dfs(int g){
	v[g] = 1;
	for(auto u : e[g]){
		if(v[u] == 2)continue;
		if(v[u] == 1){cyc = 1; continue;}
		dfs(u);
	}
	topo.pb(g);
	v[g] = 2;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i<=m; i++){
		cin >> t1 >> t2;
		e[t1].pb(t2);
	}

	for(int i = 1; i<=n; i++){
		if(v[i])continue;
		dfs(i);
	}

	reverse(topo.begin(), topo.end());
	if(cyc){
		cout << "IMPOSSIBLE"<< endl;
		return 0;
	}

	for(auto u : topo){
		cout << u << ' ';
	} cout << endl;

	cout.flush();
	return 0;
}