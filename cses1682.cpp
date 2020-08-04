#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n,m, t1, t2, cmps = 0;
vector<int> e[100001], ek[100001], kos, cmp, ans;
bool v[100001];

void kfs(int g){
	v[g] = 1;
	for(auto u : e[g]){
		if(v[u]) continue;
		kfs(u);
	}
	kos.pb(g);
}

void dfs(int g){
	v[g] = 1;
	cmp.pb(g);
	for(auto u : ek[g]){
		if(v[u])continue;
		dfs(u);
	}
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i<=m; i++){
		cin >> t1 >> t2;
		e[t1].pb(t2);
		ek[t2].pb(t1);
	}

	for(int i = 1; i<=n; i++){
		if(v[i])continue;
		kfs(i);
	}

	reverse(kos.begin(),kos.end());
	/*for(auto u : kos)
		cout << u << " ";
	cout << endl;*/ 
	for(int i = 1; i<=n; i++)
		v[i] = 0;

	for(auto u : kos){
		if(v[u])continue;
		dfs(u);
		ans.pb(u);
		if(cmp.size() == n){
			cout << "YES" << endl;
			return 0;
		}
		cmp.clear();
	}

	cout << "NO" << endl;
	cout << ans[1] << " " << ans[0] << endl;

	cout.flush();
	return 0;
}