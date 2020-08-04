#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second
 
 
//var 
LL n,dp[1000001], c[101], INF = 1000000000, ans = 0, x, MOD = 1e9 + 7;
 
int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x; ans = INF;
	for(int i = 1; i<=n; i++)
		cin >> c[i];
	
	dp[0] = 1;
	for(int i = 1; i<=n; i++){
		for(int j = c[i]; j<=(LL)x; j++){
			dp[j] += dp[j-c[i]];
			dp[j] %= MOD;
		} //0 INF
	}
 
	cout << (dp[x]) << endl;
	cout.flush();
}