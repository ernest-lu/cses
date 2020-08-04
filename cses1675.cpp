#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<int,pii> ppi;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n,m,t1,t2,t3, cmps, par[100001], sz[100001], ans = 0;
vector<ppi> e;

LL fnd(LL g){
	if(g == par[g])return g;
	return par[g] = fnd(par[g]);
}

void uni(int a, int b){
	a = fnd(a); b = fnd(b);
	if(a == b)return;
	if(sz[a] < sz[b])swap(a,b);
	par[b] = a; sz[a] += sz[b]; cmps--;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i<=m; i++){
		cin >> t1 >> t2 >> t3;
		e.pb(mp(t3,mp(t1,t2)));
	}

	sort(e.begin(), e.end()); cmps = n;

	for(int i = 1; i<=n; i++){
		par[i] = i;
		sz[i] = 1;
	}

	for(auto u : e){
		//cout << u.f << " " << u.s.f << " " << u.s.s << endl;
		if(fnd(u.s.f) == fnd(u.s.s))continue;
		//cout << u.f << " " << u.s.f << " " << u.s.s << endl;
		ans += u.f; uni(u.s.f,u.s.s);
	}

	if(cmps == 1){
		cout << ans << endl;
		return 0;
	}

	cout << "IMPOSSIBLE" << endl;

	cout.flush();
	return 0;
}