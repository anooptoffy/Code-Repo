#include <bits/stdc++.h>

using namespace std;

#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define ll long long
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626

typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vll;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vll>		vvl;

const ll mod = 2e18;
const int N = 3e5;

int main(int argc, char const *argv[])
{
	// For handling large inputs.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll int T, P, q, count;

	cin >> T;
	while(T-- > 0) {
	    cin >> P;
	    count = 0;
	    if(P >=  2048){
	    	q = P / 2048;
	    	count = count + q;
	    	P = P - q* 2048;
	    }
	    if(P >=  1024){
	    	q = P / 1024;
	    	count = count + q;
	    	P = P - q* 1024;
	    }
	    if(P >=  512){
	    	q = P / 512;
	    	count = count + q;
	    	P = P - q* 512;
	    }
	    if(P >=  256){
	    	q = P / 256;
	    	count = count + q;
	    	P = P - q* 256;
	    }
	    if(P >=  128){
	    	q = P / 128;
	    	count = count + q;
	    	P = P - q* 128;
	    }
	    if(P >=  64){
	    	q = P / 64;
	    	count = count + q;
	    	P = P - q* 64;
	    }
	    if(P >=  32){
	    	q = P / 32;
	    	count = count + q;
	    	P = P - q* 32;
	    }
	    if(P >=  16){
	    	q = P / 16;
	    	count = count + q;
	    	P = P - q* 16;
	    }
	    if(P >=  8){
	    	q = P / 8;
	    	count = count + q;
	    	P = P - q* 8;
	    }
	    if(P >=  4){
	    	q = P / 4;
	    	count = count + q;
	    	P = P - q* 4;
	    }
	    if(P >=  2){
	    	q = P / 2;
	    	count = count + q;
	    	P = P - q* 2;
	    }
	    if(P >=  1){
	    	q = P / 1;
	    	count = count + q;
	    	P = P - q* 1;
	    }
	    cout << count << endl;
	}
	
	return 0;
}