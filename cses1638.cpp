#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, ar[1001][1001], dp[1001][1001], MOD = 1e9+7, dx[2] = {-1,0}, dy[2] = {0,-1};
string s;

void dfs(LL x, LL y){
	if(dp[x][y] != -1)return;
	LL res = 0;
	//cout << x << " " << y << endl;
	for(int i = 0; i<2; i++){
		if(x+dx[i] <= 0)continue;
		if(y+dy[i] <= 0)continue;
		if(ar[x+dx[i]][y+dy[i]])continue;
		dfs(x+dx[i],y+dy[i]);
		res += (dp[x+dx[i]][y+dy[i]] <= -1 ? 0 : dp[x+dx[i]][y+dy[i]]);
		res %= MOD;
	} dp[x][y] = res;
}

int main(){
	cin >> n;
	for(int i = 1; i<=n; i++)
		for(int j = 1; j<=n; j++)
			dp[i][j] = -1;

	dp[1][1] = 1;

	for(int i = 1; i<=n; i++){
		cin >> s;
		for(int j = 0; j<n; j++){
			if(s[j] == '.')ar[i][j+1] = 0;
			else {
				//cout << i << " " << j+1 << endl;
				ar[i][j+1] = 1; //blcoekd
			}
		}
	} 
	if(ar[n][n]){
		cout << 0 << endl;
		return 0;
	}
	dfs(n,n);
	cout << dp[n][n] << endl;
	return 0;
}