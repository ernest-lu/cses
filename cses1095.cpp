#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, a, b, c, MOD = 1e9+7;

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
	while(n--){
		cin >> a >> b >> c;
		cout << pwo(pwo(a,b), c) << endl;
	}

	cout.flush();
	return 0;
}