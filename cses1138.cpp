#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, cur = 1, q, t1, t2, t3, dep[200001], a[200001], st[200001], en[200001], tr[600001];
vector<LL> e[200001];

void upd(LL g, LL k){
	for(; g <= cur; g += (g&-g))
		tr[g] += k;
}

LL ge(LL g){
	LL res = 0;
	for(; g>0; g-=(g&-g))
		res += tr[g];
	return res;
}

void dfs(LL g, LL p){
	st[g] = cur; cur++;
	//cout << g << " " << d << endl;
	for(auto u : e[g]){
		if(u == p)continue;
		dfs(u, g);
	}
	//cout << g << " " << cur << endl;
	en[g] = cur; cur++;
}


int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> q;
	for(LL i = 1; i<=n; i++)
		cin >> a[i];
	for(LL i = 1; i<n; i++){
		cin >> t1 >> t2;
		e[t1].pb(t2);
		e[t2].pb(t1);
	} dfs(1, 0);

	for(int i = 1; i<=n; i++){
		upd(st[i], a[i]);
		upd(en[i], -a[i]);
	}

	while(q--){
		LL tt;
		cin >> tt;
		if(tt == 2){
			LL gg; cin >> gg;
			cout << ge(st[gg]) << endl;
			continue;
		}
		LL gg, kk;
		cin >> gg >> kk;
		upd(st[gg], kk-a[gg]);
		upd(en[gg], a[gg]-kk);
		a[gg] = kk;
	}

	cout.flush();
	return 0;
}