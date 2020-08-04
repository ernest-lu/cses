#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n,x[101], dp[100001], ans = 0;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	for(int i = 1; i<=n; i++)
		cin >> x[i];

	dp[0] = 1;
	for(int i = 1; i<=n; i++){
		for(int c = 100000; c>=0; c--){
			if(c - x[i] >= 0)
				dp[c] = max(dp[c],dp[c-x[i]]);
		}
	}

	for(int i = 1; i<=100000; i++)
		if(dp[i])ans++;

	cout << ans << endl;
	for(int i = 1; i<=100000; i++)
		if(dp[i])cout << i << " ";
	cout << endl;



	cout.flush();
	return 0;
}