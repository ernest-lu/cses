#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, t1, t2, dp[200001][2], ans = 0;
vector<int> e[200001];

void dfs(int g, int p){
	int mxdf = 0;
	if(g != 1) dp[g][1] = 1;
	for(auto u : e[g]){
		if(u == p)continue;
		dfs(u, g);
		dp[g][1] += dp[u][0];
		mxdf = max(mxdf, dp[u][1] - dp[u][0]);
		dp[g][0] += dp[u][0];
	}
	dp[g][0] += mxdf;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	for(int i = 1; i<n; i++){
		cin >> t1 >> t2;
		e[t1].pb(t2);
		e[t2].pb(t1);
	}

	dfs(1, 0);
	ans = max(ans, max(dp[1][1], dp[1][0]));
	cout << ans << endl;

	cout.flush();
	return 0;
}