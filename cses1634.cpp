#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second
 
//var 
LL n,q, t[1001][1001],a1,a2,b1,b2,tt, st[1001][10001];
string s;
 
void upd(LL x, LL y){
	int yn = y, xn = x;
	LL og = st[xn][yn];
	for(; x<=1000; x+=(x&-x)){
		y = yn;
		for(; y<=1000; y+=(y&-y))
			t[x][y]+=(og?-1:1);
	}
}
 
LL ge(LL x, LL y){
	LL res = 0; LL yn = y;
	for(; x>0; x-=(x&-x)){
		y = yn;
		for(; y>0; y-=(y&-y))
			res += t[x][y];
	}
	return res;
}
 
int main(){
	cin >> n >> q;
	for(int i = 1; i<=n; i++){
		cin >> s;
		for(int j = 0; j<n; j++){
			if(s[j] == '*'){
				upd(i,j+1);
				st[i][j+1] = 1;
			}
			//cout << i << " " << j+1 << " " << ge(i,j+1) << endl;
		}
	}
	for(int i = 1; i<=q; i++){
		cin >> tt; tt--;
		if(!tt){
			cin >> a1 >> a2;
			upd(a1,a2);
			st[a1][a2]^=1;
			continue;
		}
		cin >> a1 >> a2 >> b1 >> b2;
		LL res = 0;
		res += ge(b1,b2);
		res += ge(a1-1,a2-1);
		res -= ge(a1-1,b2);
		res -= ge(b1,a2-1);
		cout << res << endl;
	}
 
}