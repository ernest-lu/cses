#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, q, ar[200001], eul[600001], t1 ,t2, cur = 1, st[200001], en[200001], tr[600005];
vector<LL> e[200001];

void upd(LL g, LL k){
	for(; g <= cur; g+=(g&-g))
		tr[g] += k;
}

LL ge(LL g){
	LL res =0;
	for(; g>0; g-=(g&-g))
		res += tr[g];
	return res;
}

void dfs(LL g, LL p){
	//cout << g << endl;
	st[g] = cur; cur++;
	for(auto u : e[g]){
		if(u == p)continue;
		dfs(u, g);
	}
	en[g] = cur; cur++;
}


int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> q;
	for(LL i = 1; i<=n; i++)
		cin >> ar[i];

	for(LL i = 1; i<n; i++){
		cin >> t1 >> t2;
		e[t1].pb(t2);
		e[t2].pb(t1);
	}

	dfs(1 ,0);
	for(LL i = 1; i<=n; i++)
		upd(st[i], ar[i]);

	while(q--){
		LL tt;
		cin >> tt; tt--;
		if(tt){
			LL g; cin >> g;
			cout << ge(en[g]) - ge(st[g]-1) << endl;
			continue;
		}

		cin >> t1 >> t2;
		upd(st[t1], -ar[t1]); ar[t1] = t2;
		upd(st[t1], t2);
	}

	cout.flush();
	return 0;
}