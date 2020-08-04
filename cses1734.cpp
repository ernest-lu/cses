#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
#define mp make_pair
#define pb push_back
#define f first
#define s second
 
//var 
const int BLCK = 450;
int n, q, ans[200001], a[200001], l, r, t1, t2, cur = 0;
vector<ppi> qu;
unordered_map<int,int> fq;
 
struct cmp{
	bool operator()(ppi a1, ppi a2){
		return mp(a1.f.f/BLCK, a1.f.s) < mp(a2.f.f/BLCK, a2.f.s);
	}
};
 
void ad(int g){
	if(!fq[a[g]])cur++;
	fq[a[g]]++;
}
 
void rem(int g){
	fq[a[g]]--;
	if(!fq[a[g]])cur--;
}
 
int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
 
	cin >> n >> q;
	for(int i = 1; i<=n; i++)
		cin >> a[i];
	
	for(int i = 1; i<=q; i++){
		cin >> t1 >> t2;
		qu.pb(mp(mp(t1,t2), i));
	}
 
	sort(qu.begin(), qu.end(), cmp());
 
	l = 0, r = 0;
	for(auto u : qu){
		//cout << u.f.f << " " << u.f.s << endl;
		while(r < u.f.s){
			r++;
			ad(r);
		}
		while(r > u.f.s){
			rem(r);
			r--;
		}
		while(l < u.f.f){
			rem(l);
			l++;
		}
		while(l > u.f.f){
			l--;
			ad(l);
		}
		ans[u.s] = cur;
	}	
 
	for(int i = 1; i<=q; i++)
		cout << ans[i] << endl;
 
	cout.flush();
	return 0;
}