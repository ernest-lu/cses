#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
set<int> dp[200001];
int t1, t2, n, ans[200001];
vector<int> e[200001];

void dfs(int g, int p){
	for(auto u : e[g]){
		if(u == p)continue;
		dfs(u, g);
		if(dp[g].size() < dp[u].size())
            swap(dp[u], dp[g]);

		for(auto z : dp[u])
			dp[g].insert(z);

		//dp[u].clear();
	}

	ans[g] = dp[g].size();
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> t1;
		dp[i].insert(t1);
	}

	for(int i = 1; i<n; i++){
		cin >> t1 >> t2;
		e[t1].pb(t2);
		e[t2].pb(t1);
	}

	dfs(1, 0);
	for(int i = 1; i<=n; i++)
		cout << dp[i].size() << " ";
	cout << endl;

	cout.flush();
	return 0;
}