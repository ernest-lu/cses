#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, t1, t2, bl[200001][30], dep[200001];
queue<int> bfs;
bool v[200001];
vector<int> e[200001];

void dfs(int g, int p, int d){
	dep[g] = d;
	bl[g][0] = p;
	for(int i = 1; i<=20; i++)
		bl[g][i] = bl[bl[g][i-1]][i-1];

	for(auto u : e[g]){
		if(u == p)continue;
		dfs(u, g, d+1);
	}
}

int LCA(int a, int b){
	if(dep[a] > dep[b])
		swap(a, b);

	for(int i = 20; i>=0; i--){
		if(dep[bl[b][i]] < dep[a]) continue;
		b = bl[b][i];
	} if(b == a)return b;

	for(int i = 20; i>=0; i--){
		if(bl[b][i] == bl[a][i])continue;
		a = bl[a][i]; b = bl[b][i];
	} return (bl[a][0]);
}

int dis(int a, int b){
	int L = LCA(a, b);
	return (dep[a] - dep[L]) + (dep[b] - dep[L]);
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	for(int i = 1; i<n; i++){
		cin >> t1 >> t2;
		e[t1].pb(t2);
		e[t2].pb(t1);
	} bfs.push(1);
	while(!bfs.empty()){
		t1 = bfs.front();
		bfs.pop();
		if(v[t1])continue;
		v[t1] = 1; 
		for(auto u : e[t1]){
			if(v[u])continue;
			bfs.push(u);
		}
	}

	for(int i = 1; i<=n; i++)
		v[i] = 0;

	bfs.push(t1);
	while(!bfs.empty()){
		t2 = bfs.front();
		bfs.pop();
		if(v[t2])continue;
		v[t2] = 1; 
		for(auto u : e[t2]){
			if(v[u])continue;
			bfs.push(u);
		}
	}

	dfs(1, 0, 1);
	for(int i = 1; i<=n; i++){
		cout << max(dis(i, t1), dis(i, t2)) << " ";
	} cout << endl;

	cout.flush();
	return 0;
}