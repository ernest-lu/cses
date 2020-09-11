#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, m, rec = 0, st;
vector<int> e[100005];
int v[100005], par[100005];

void dfs(int g, int p){
	v[g] = 1; par[g] = p;
	//cout << g << " " << p << endl;
	for(auto u : e[g]){
		if(u == p) continue;
		if(v[u] == 2) continue;
		if(v[u]){
			st = u;
			rec = g;
			return;
		}
		dfs(u, g);
	}
	v[g] = 2;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	FOR(i, m){
		int t1, t2;
		cin >> t1 >> t2;
		e[t1].pb(t2); e[t2].pb(t1);
	}

	FOR(i, n){
		if(v[i]) continue;
		dfs(i, 0);
		//cout << rec << ' ' << st << endl;
		swap(rec, st);
		if(rec){
			vector<int> ans;
			ans.pb(st);
			while(rec != st){
				ans.pb(rec);
				rec = par[rec];
			}
			ans.pb(st);
			cout << ans.size() << endl;
			for(auto u : ans)
				cout << u << " ";
			cout << endl;
			return 0;
		}
	}

	cout << "IMPOSSIBLE" << endl;

	cout.flush();
	return 0;
}