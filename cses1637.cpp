#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL dp[1000001], INF = 1e9, g,n;

int main(){
	cin >> n;
	dp[n] = 0;
	for(int i = 0; i<n; i++)
		dp[i] = INF;
	for(int i = n; i>=0; i--){
		g = i;
		while(g>0){
			//cout << g << endl;
			dp[i-g%10] = min(dp[i-g%10],dp[i]+1);
			g/=10;
		}
	}

	cout << dp[0] << endl;
}