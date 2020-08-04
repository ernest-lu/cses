#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi; // goto, pp, dis
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n,m,t1,t2, pp[100001], cur;
vector<int> e[100001], ans;
bool v[100001], go = 0;
queue<ppi> bfs;
ppi tt;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i<=m; i++){
		cin >> t1 >> t2;
		e[t1].pb(t2);
		e[t2].pb(t1);
	}

	bfs.push(mp(mp(1,-1),1));
	while(!bfs.empty()){
		tt = bfs.front();
		bfs.pop();
		if(v[tt.f.f])continue;
		//cout << tt.f.f << endl;
		v[tt.f.f] = 1; pp[tt.f.f] = tt.f.s; cur = tt.s;
		if(tt.f.f == n){go = 1; break;}
		for(auto u : e[tt.f.f]){
			if(v[u])continue;
			bfs.push(mp(mp(u,tt.f.f),tt.s+1));
		}
	}	

	if(!go){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	cout << cur << endl;
	int g = n;
	while(g != -1){
		ans.pb(g);
		g = pp[g];
	}
	reverse(ans.begin(),ans.end());
	for(auto u : ans)
		cout << u << ' ';
	cout << endl;
	

	cout.flush();
	return 0;
}