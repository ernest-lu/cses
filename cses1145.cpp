#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, a[200005], tr[400005];
vector<pii> nds, tou, vltou;

void upd(int g, int k){
	for(tr[g += n] = k; g>1; g/=2)
		tr[g/2] = max(tr[g], tr[g^1]);
}

LL ge(int l, int r){
	LL res = 0;
	for(l += n, r += n; l < r; l/=2, r/=2){
		if(l%2) res = max(res, tr[l++]);
		if(r%2) res = max(res, tr[--r]);
	} return res;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	FOR(i, n){
		cin >> a[i];
		nds.pb(mp(a[i], i));
	} sort(nds.begin(), nds.end(), greater<pii>());

	while(nds.size()){
		pii g = nds.back(); tou.clear(); vltou.clear();
		nds.pop_back(); tou.pb(g);
		while(nds.size() && nds.back().f == g.f){
			tou.pb(nds.back());
			nds.pop_back();
		}
		for(auto u : tou)
			vltou.pb({u.s, ge(0, u.s-1) + 1});
		for(auto u : vltou)
			upd(u.f-1, u.s);
	}

	cout << ge(0, n) << endl;

	cout.flush();
	return 0;
}