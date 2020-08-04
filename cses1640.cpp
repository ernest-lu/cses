#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, x, a[200005];
pii ar[200005];

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> x;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
		ar[i] = mp(a[i], i);
	}

	sort(ar+1, ar+n+1);
	sort(a+1, a+n+1);
	for(int i = 1; i<=n; i++){
		if(a[i] >= x)continue;
		if(a[i] == a[i+1])continue;
		int l = 1, r = n, mid;
		while(l < r){
			mid = (l + r)/2;
			if(a[mid] >= x-a[i])r = mid;
			else l = mid+1;
		} 

		if(i == l)continue;
		if(a[i] + a[l] == x){
			cout << ar[i].s << " " << ar[l].s << endl;
			return 0;
		}

	}

	cout << "IMPOSSIBLE" << endl;

	cout.flush();
	return 0;
}