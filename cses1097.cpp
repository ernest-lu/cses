#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
#define FOR(i, ff) for(int i = 1; i<=ff; i++)
#define F0R(i, ff) for(int i = 0; i<ff; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
const LL INF = 1e13;
LL n, a[5005];
pii dp[5005][5005][2];
bool v[5005][5005][2];

void dfs(int l, int r, int p){
	v[l][r][p] = 1;
	if(l+1 <= r){
		if(!v[l+1][r][p^1]) 
			dfs(l+1, r, p^1);
		
		if(p == 0){
			if(dp[l+1][r][p^1].f + a[l] > dp[l][r][p].f){
				dp[l][r][p] = dp[l+1][r][p^1];
				dp[l][r][p].f += a[l];
			}
		}
		else{
			if(dp[l+1][r][p^1].s + a[l] > dp[l][r][p].s){
				dp[l][r][p] = dp[l+1][r][p^1];
				dp[l][r][p].s += a[l];
			}
		}
	}

	if(r-1 >= l){
		if(!v[l][r-1][p^1]) dfs(l, r-1, p^1);
		if(p == 0){
			if(dp[l][r-1][p^1].f + a[r] > dp[l][r][p].f){
				dp[l][r][p] = dp[l][r-1][p^1];
				dp[l][r][p].f += a[r];
			}
		}
		else{
			if(dp[l][r-1][p^1].s + a[r] > dp[l][r][p].s){
				dp[l][r][p] = dp[l][r-1][p^1];
				dp[l][r][p].s += a[r];
			}
		}
	}

	//cout << l << " " << r << ' ' << p << ' ' << dp[l][r][p].f << ' ' << dp[l][r][p].s << endl;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	FOR(i, n) cin >> a[i];
	/*FOR(i,n) FOR(j,n) F0R(k, 2) {
		//cout << i << ' ' << j << ' ' << k << endl;
		dp[i][j][k] = mp(-INF, -INF);
	}*/
	FOR(i, n){
		dp[i][i][0] = mp(a[i], 0);
		dp[i][i][1] = mp(0, a[i]);
	}
	//dfs(1, n, 0);
	for(int sz = 2; sz<=n; sz++){
		for(int st = 1; st+sz-1<=n; st++){
			if(st+sz-1-1>0){
				//cout << st << ' ' << sz << endl;
 				dp[st][st+sz-1][0] = dp[st][st+sz-1-1][1];
				dp[st][st+sz-1][1] = dp[st][st+sz-1-1][0];
				dp[st][st+sz-1][0].f += a[st+sz-1];
				dp[st][st+sz-1][1].s += a[st+sz-1];
			}
			if(st+1<=n){
				if(dp[st+1][st+sz-1][1].f + a[st] > dp[st][st+sz-1][0].f){
					dp[st][st+sz-1][0] = dp[st+1][st+sz-1][1];
					dp[st][st+sz-1][0].f += a[st];
				}

				if(dp[st+1][st+sz-1][0].s + a[st] > dp[st][st+sz-1][1].s){
					dp[st][st+sz-1][1] = dp[st+1][st+sz-1][0];
					dp[st][st+sz-1][1].s += a[st];
				}
			}
		}
	}
	cout << dp[1][n][0].f << endl;

	cout.flush();
	return 0;
}