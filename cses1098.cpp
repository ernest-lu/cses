#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, dp[65005], MOD = 1e9+7, mxv, INF = 1e16;

LL pwo(LL a1, LL b1){
	if(b1 == 0)return 1;
	LL ans = a1, cur = a1; b1--;
	while(b1){
		if(b1&1) {ans *= cur; ans%=MOD;}
		cur *= cur; cur %= MOD;
		b1>>=1;
	} return ans;
}


int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	mxv = ((n) * (n+1))/2;
	if(mxv%2){
		cout << 0 << endl;
		return 0;
	} mxv/=2;

	dp[0] = 1;

	for(int i = 1; i<=n; i++){
		for(int j = mxv; j>=0; j--){
			if(j-i < 0)continue;
			dp[j] += dp[j-i];
			dp[j] %= MOD; 
		}
	}

	dp[mxv] *= pwo(2, MOD-2);
	dp[mxv] %= MOD;
	cout << dp[mxv] << endl;

	cout.flush();
	return 0;
}