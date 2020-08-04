#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
typedef pair<pii, LL> ppi;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, m, t1, t2, t3, dis[100001][2];
vector<pii> e[100001];
priority_queue<ppi, vector<ppi>, greater<ppi>> dik;
ppi tt;
bool v[100001][2];

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i<=m; i++){
		cin >> t1 >> t2 >> t3;
		e[t1].pb(mp(t2, t3));
	}

	dik.push(mp(mp(0, 1), 0)); //taken half
	while(!dik.empty()){
		tt = dik.top();
		dik.pop();
		if(v[tt.f.s][tt.s])continue;
		v[tt.f.s][tt.s] = 1; dis[tt.f.s][tt.s] = tt.f.f;
		for(auto u : e[tt.f.s]){
			ppi nt = tt;
			nt.f.s = u.f; nt.f.f += u.s;
			dik.push(nt);
			if(nt.s) continue;
			nt.s = 1; nt.f.f -= u.s; nt.f.f += u.s/2;
			dik.push(nt);
		}
	}

	cout << dis[n][1] << endl;

	cout.flush();
	return 0;
}