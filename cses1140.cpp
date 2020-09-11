#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
typedef pair<pii,LL> ppi;
#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, sz, tr[800005], cur, dp[400005];
map<LL, LL> itpo;
vector<LL> tpo;
vector<ppi> pts;
vector<pii> ricky[400005];

void upd(LL g, LL k){
	for(tr[g += cur] = k; g>1; g/=2)
		tr[g/2] = max(tr[g], tr[g^1]);
}

LL ge(LL l, LL r){
	LL res = 0;
	for(l += cur, r += cur; l<r; l/=2, r/=2){
		if(l%2) res = max(res, tr[l++]);
		if(r%2) res = max(res, tr[--r]);
	} return res;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	FOR(i, n){
		LL t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		tpo.pb(t1); tpo.pb(t2);
		pts.pb(mp(mp(t1,t2),t3));
	}

	sort(tpo.begin(), tpo.end()); cur = 0;
	for(int i = 0; i<tpo.size(); i++){
		if(itpo[tpo[i]]) continue;
		cur++;
		itpo[tpo[i]] = cur;
	}

	for(auto u : pts)
		ricky[itpo[u.f.f]].pb(mp(itpo[u.f.s], u.s));

	/*for(auto u : itpo){
		cout << u.f << ' ' << u.s << endl;
	}*/

	FOR(i, cur){
		for(auto u : ricky[i]){
			dp[u.f] = max(dp[u.f], u.s + ge(0, i-1));
			upd(u.f-1, dp[u.f]);
		}
		//cout << i << " " << dp[i] << endl;
	}

	cout << ge(0, cur) << endl;

	cout.flush();
	return 0;
}