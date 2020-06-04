#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL dp[100001], n, x, h[1001], s[1001], ans = 0;

int main(){
	cin >> n >> x;
	for(int i = 1; i<=n; i++)
		cin >> h[i];
	for(int i = 1; i<=n; i++)
		cin >> s[i];
	for(int i = 1; i<=x; i++)
		dp[i] = -1;
	dp[0] = 0;
	for(int i = 1; i<=n; i++){
		for(int j = x; j>=h[i]; j--){
			if(dp[j-h[i]] <= -1)continue;
			dp[j] = max(dp[j],dp[j-h[i]] + s[i]);
			ans = max(dp[j],ans);
			//cout << j << " " << dp[j-h[i]] << " " << s[i] << " " << dp[j] << endl;
		}
	}
	cout << ans << endl;
}