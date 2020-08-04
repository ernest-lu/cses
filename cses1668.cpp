#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, m, t1, t2;
vector<int> e[100001];
queue<pii> bfs;
pii tt;
bool v[100001], ty[100001];

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	while(m--){
		cin >> t1 >> t2;
		e[t1].pb(t2);
		e[t2].pb(t1);
	}

	for(int i = 1; i<=n; i++){
		if(v[i])continue;
		bfs.push(mp(i, 0));
		while(!bfs.empty()){
			tt = bfs.front();
			bfs.pop();
			if(v[tt.f])continue;
			v[tt.f] = 1; ty[tt.f] = tt.s%2;
			for(auto u : e[tt.f]){
				if(v[u])continue;
				bfs.push(mp(u, tt.s+1));
			}
		}
	}

	bool ok = 1;
	for(int i = 1; i<=n; i++)
		for(auto u : e[i])
			if(ty[u] == ty[i]) ok = 0;

	if(!ok){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	for(int i = 1; i<=n; i++)
		cout << (ty[i] ? 2 : 1) << " ";
	cout << endl;


	cout.flush();
	return 0;
}