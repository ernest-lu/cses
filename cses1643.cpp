#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n,x[200001],cur = 0,ans = INT_MIN;

int main(){
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> x[i];
		ans = max(ans,x[i]);
		if(cur == 0){
			cur += x[i];
			ans = max(ans,cur);
			continue;
		}
		if(cur < 0){
			cur = 0;
			cur += x[i];
			ans = max(ans,cur);
			continue;
		}
		cur += x[i];
		ans = max(ans,cur);
	}
	cout << ans << endl;
}