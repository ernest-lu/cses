#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n,m,t1,t2, par[100001], sz[100001];
vector<pii> ans;

int fn(int g){
	if(par[g] == g)return g;
	return par[g] = fn(par[g]);
}

void uni(int a, int b){
	a = fn(a); b = fn(b);
	if(a == b)return;
	if(sz[a] < sz[b])swap(a,b);
	par[b] = a;
	sz[a] += sz[b];
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		par[i] = i; sz[i] = 1;
	}

	for(int i = 1; i<=m; i++){
		cin >> t1 >> t2;
		uni(t1,t2);
	}

	for(int i = 1; i<n; i++){
		int a = fn(i), b = fn(i+1);
		if(a == b)continue;
		uni(a,b); ans.pb(mp(a,b));
	}	

	cout << ans.size() << endl;
	for(auto u : ans)
		cout << u.f << " " << u.s << endl;

	cout.flush();
	return 0;
}