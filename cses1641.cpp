#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n,x, a[5001], cs = 0, l, r, mid;
pii g[5001];

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> x;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
		g[i] = mp(a[i],i);
	}

	sort(g+1, g+n+1);

	for(int i = 1; i<n; i++){
		for(int j = i+1; j<n; j++){
			cs = g[i].f + g[j].f;
			if(x <= cs)continue;
			l = j+1; r = n;
			while(l < r){
				mid = (l+r+1)/2;
				if(g[mid].f <= x - cs)l = mid;
				else r = mid-1;
			}

			if(g[l].f + g[i].f + g[j].f == x){
				cout << g[i].s << ' ' << g[j].s << ' ' << g[l].s << endl;
				return 0;
			}
		}
	}

	cout << "IMPOSSIBLE" << endl;

	cout.flush();
	return 0;
}