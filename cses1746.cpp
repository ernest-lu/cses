#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL ar[200001], dp[200001][101], MOD = 1e9+7; 

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i<=n; i++)
		cin >> a[i];

	for(int i = 1; i<=m; i++)
		dp[0][i] = 0;

	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=m; j++)
			dp[i][j] = dp[i-1][j]
		if(a[i] != 0)continue;
		
	}

	cout.flush();
	return 0;
}