#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n,x,p[200001], l, r, mid, g, ans = 0;
bool u[200001];

bool valid(){
	return p[mid] <= g;
}

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> x;
	for(int i = 1; i<=n; i++)
		cin >> p[i];
	sort(p+1,p+n+1);

	l = 1, r = n;
	for(int i = 1; i<=n; i++){
		if(u[i])continue;
		l = i+1; 
		if(r < l)continue;
		u[i] = 1;  g = x-p[i]; ans++;
		if(i == n)break;
		while(l < r){
			mid = (l+r+1)/2;
			if(valid())l = mid;
			else r = mid-1;
		}
		if(p[l] <= g){
			//cout << l << " " << i << endl;
			u[l] = 1;
			r = l-1;
		}
		else{
			break;
		}
	}

	for(int i = 1; i<=n; i++)
		if(!u[i])ans++;
	
	cout << ans << endl;

	cout.flush();
	return 0;
}