#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
typedef pair<LL, pii> ppi;
#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, k, m, t1, t2, t3;
vector<pii> e[100005];
LL dis[100005][15];
priority_queue<ppi, vector<ppi>, greater<ppi>> dij;
bool v[100005][15];

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m >> k;
	FOR(i, m){
		cin >> t1 >> t2 >> t3;
		e[t1].pb(mp(t3, t2));
	}

	dij.push(mp(0, mp(1,1)));
	while(!dij.empty()){
		ppi tt = dij.top();
		dij.pop();
		for(int i = tt.s.s; i<=k; i++){
			if(v[tt.s.f][i]) continue;
			tt.s.s = i;
			break;
		}
		if(v[tt.s.f][tt.s.s]) continue;
		//cout << tt.s.f << " " << tt.s.s << " " << tt.f << endl;
		v[tt.s.f][tt.s.s] = 1; dis[tt.s.f][tt.s.s] = tt.f;
		for(auto u : e[tt.s.f]){
			FOR(i, k){
				if(v[u.s][i]) continue;
				dij.push(mp(tt.f + u.f, mp(u.s,i)));
				break;
			}
		}
	}

	FOR(i, k)
		cout << dis[n][i] << " ";
	cout << endl;

	cout.flush();
	return 0;
}