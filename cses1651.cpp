#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n,q,x[200005], t[200005], u, a, b, k, tt;

void upd(int g, LL u){
	for(; g <= n; g += (g&-g))
		t[g] += u;
}

LL ge(int g){
	LL res = 0;
	for(; g>0; g -= (g&-g))
		res += t[g];
	return res;
}

int main(){
	cin >> n >> q;
	for(int i = 1; i<=n; i++){
		cin >> x[i];
		upd(i,x[i]); upd(i+1,-x[i]);
	}
	for(int i = 1; i<=q; i++){
		cin >> tt; tt--;
		if(tt){
			cin >> k;
			cout << ge(k) << endl;
			continue;
		}
		cin >> a >> b >> u;
		upd(a,u);
		upd(b+1,-u);
	}
}