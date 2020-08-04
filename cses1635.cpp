#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int dp[1000001], n, x, c[101], MOD = 1000000007;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> x;
	for(int i = 1; i<=n; i++)
		cin >> c[i];

	dp[0] = 1;
	for(int i = 1; i<=x; i++){
		for(int j = c[j]; j<=n; j++){
			(dp[i] += dp[i-c[j]]) %= MOD;
		}
		//cout << i << " " << dp[i] << endl;
	}

	cout << dp[x] << endl;

	cout.flush();
	return 0;
}