#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii, pii> ppp;
#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, m, stx, sty;
char gr[1005][1005];
bool v[1005][1005];
pii par[1005][1005], fin, rec;
queue<ppp> bfs;
const pii badparent = mp(-1,-1);
const int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> m;
	FOR(i, n) FOR(j, m){
		cin >> gr[i][j];
		if(gr[i][j] == 'M')
			bfs.push(mp(mp(i,j), badparent));
		if(gr[i][j] == '#') v[i][j] = 1;
		if(gr[i][j] == 'A'){stx = i; sty = j;}
	}

	bfs.push(mp(mp(stx, sty), mp(0,0))); rec = badparent;

	while(!bfs.empty()){
		ppp tt = bfs.front();
		bfs.pop();
		//cout << tt.f.f << ' ' << tt.f.s << " " << tt.s.f << " " << tt.s.s << endl;
		if(v[tt.f.f][tt.f.s]) continue;
		v[tt.f.f][tt.f.s] = 1;

		if(tt.s != badparent) 
			par[tt.f.f][tt.f.s] = tt.s;

		if((tt.f.f == 1 || tt.f.f == n) && tt.s != badparent){
			rec = tt.f;
			break;
		}

		if((tt.f.s == 1 || tt.f.s == m) && tt.s != badparent){
			rec = tt.f;
			break;
		}

		for(int i = 0; i<4; i++){
			int nx = tt.f.f + dx[i], ny = tt.f.s + dy[i];
			if(nx < 0 || nx > n) continue;
			if(ny < 0 || ny > m) continue;
			if(v[nx][ny]) continue;
			if(tt.s != badparent) {
				//cout << "bruh" << endl;
				bfs.push(mp(mp(nx,ny),tt.f));
			}
			else bfs.push(mp(mp(nx,ny), badparent));
		}
	}

	if(rec == badparent){
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	string ans = "";
	while(rec != mp(stx, sty)){
		//cout << rec.f << " " << rec.s << endl;
		pii pp = par[rec.f][rec.s];
		if(pp.f + 1 == rec.f) ans += 'D';
		if(pp.f - 1 == rec.f) ans += 'U';
		if(pp.s + 1 == rec.s) ans += 'R';
		if(pp.s - 1 == rec.s) ans += 'L';
		rec = pp;
	}

	reverse(ans.begin(), ans.end());
	cout << ans.size() << endl << ans << endl;

	cout.flush();
	return 0;
}