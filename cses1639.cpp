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
int n, m, dp[5005][5005]; 
string s1, s2;
bool v[5005][5005];

void dfs(int x, int y){
	v[x][y] = 1;
	if(x > 0) {
		if(!v[x-1][y])dfs(x-1, y);
		dp[x][y] = min(dp[x][y], dp[x-1][y] + 1);
	}
	if(y > 0){
		if(!v[x][y-1]) dfs(x, y-1);
		dp[x][y] = min(dp[x][y], dp[x][y-1] + 1);
	}
	if(x>0 && y>0) {
		if(!v[x-1][y-1]) dfs(x-1, y-1);
		dp[x][y] = min(dp[x][y], dp[x-1][y-1] + (s1[x-1] != s2[y-1] ? 1 : 0));
	}
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> s1 >> s2; n = s1.size(); m = s2.size();
	F0R(i, n+1) F0R(j, m+1) dp[i][j] = INT_MAX;
	v[0][0] = 1; dp[0][0] = 0;
	dfs(n, m); //prefix of s1 to s2 
	cout << dp[n][m] << endl;

	cout.flush();
	return 0;
}