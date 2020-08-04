#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, ans = 0;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	while(n > 0){
		ans += n/5;
		n/=5;
	}
	cout << ans << endl;

	cout.flush();
	return 0;
}