#include<iostream>
using namespace std;
typedef long long LL;
 
//var 
const LL MOD = 1e9+7;
LL dp[1000005], n, x, c[105];
 
int main(){
	/*ios_base::sync_with_stdio(0); 
	cin.tie(0);*/
 
	cin >> n >> x;
	for(int i = 1; i<=n; i++)
		cin >> c[i];
 
	dp[0] = 1;
	for(int i = 1; i<=x; i++){
		for(int j = 1; j<=n; j++){
			if(i - c[j] < 0)continue;
			dp[i] += dp[i-c[j]];
			dp[i] %= MOD;
		}
		//cout << i << " " << dp[i] << endl;
	}
 
	cout << dp[x] << endl;
 
	//cout.flush();
	return 0;
}