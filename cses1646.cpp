#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n,q,x[200001], l, r;

int main(){
	cin >> n >> q;
	for(int i = 1; i<=n; i++){
		cin >> x[i];
		x[i] ^= x[i-1];
	} 
	for(int i = 1; i<=q; i++){
		cin >> l >> r;
		cout << (x[r] ^ x[l-1]) << endl;
	}
}