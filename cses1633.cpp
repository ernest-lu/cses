#include<bits/stdc++.h>
using namespace std;

//var 
long long n,dp[1000001],MOD = 1e9+7;

void dfs(int g){
	if(dp[g]!=0)return;
	if(g>=1 && g<=6)dp[g] = 1;
	for(int i = 1; i<=6; i++){
		if(g-i>=1){
			dfs(g-1);
			dp[g] += dp[g-i];
			dp[g]%=MOD;
		}
	}
}

int main(){
	cin >> n; 
	for(int i = 1; i<=n; i++)dp[i] = 0;
	dfs(n); cout << dp[n]%MOD << endl;
}