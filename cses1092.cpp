#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, su;
vector<LL> v1,v2;


int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	su = ((n) * (n+1))/2;
	if(su%2){
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	if(n%2){
		for(int i = 4; i<=3 + (n-3)/2; i++){
			if(i%2){v1.pb(i); v1.pb(n-i+4);}
			else {v2.pb(i); v2.pb(n-i+4);}
		} v1.pb(1); v1.pb(2); v2.pb(3);
	}
	else{
		for(int i = 1; i<=n/2; i++){
			if(i%2){v1.pb(i); v1.pb(n-i+1);}
			else {v2.pb(i); v2.pb(n-i+1);}
		}
	}

	cout << v1.size() << endl;
	for(auto u : v1) cout << u << " "; cout << endl;
	cout << v2.size() << endl;
	for(auto u : v2) cout << u << " "; cout << endl;

	cout.flush();
	return 0;
}