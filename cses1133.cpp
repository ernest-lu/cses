#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, t1, t2, sub[200001], dep[200001], ans[200001];
vector<LL> e[200001];

void dfs1(LL g, LL p, LL d){
	dep[g] = d; sub[g] = 1;
	for(auto u : e[g]){
		if(u == p)continue;
		dfs1(u, g, d+1);
		sub[g] += sub[u];
	}
}

void dfs2(LL g, LL p){
	if(g != 1){
		ans[g] = ans[p];
		ans[g] -= sub[g];
		ans[g] += n - sub[g];
	}
	for(auto u : e[g]){
		if(u == p)continue;
		dfs2(u, g); 
	}
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	for(LL i = 1; i<n; i++){
		cin >> t1 >> t2;
		e[t1].pb(t2);
		e[t2].pb(t1);
	}

	dfs1(1, 0, 0);
	for(LL i = 1; i<=n; i++)
		ans[1] += dep[i];
	
	dfs2(1, 0);
	for(LL i = 1; i<=n; i++)
		cout << ans[i] << " ";
	cout << endl;

	cout.flush();
	return 0;
}