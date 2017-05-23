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
	long long int R, L, flag, wrong;
	char ch;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> R;
	while(R-- > 0) {
		flag = 0;
		wrong = 0;
	    cin >> L;
	    for (int i = 0; i < L; ++i)
	    {
	    	cin >> ch;
	    	if (ch == '.')
	    	{
	    		continue;
	    	}
	    	if(ch == 'T' && flag == 0){
	    		wrong = 1;
	    	}
	    	else if(ch == 'H' && flag == 1){
	    		wrong = 1;
	    	}
	    	else if (ch == 'H'){
	    		flag = 1;
	    	}
	    	else if (ch == 'T' and flag == 1)
	    	{
	    		flag = 0;
	    	}
	    	else
	    	{
	    		//cout << ch << endl;
	    		wrong = 1;
	    	}
	    	
	    }
	    if (wrong == 1)
	    {
	    	cout << "Invalid";
	    }
	    else{
	    	if (flag == 1)
	    	{
	    		cout << "Invalid";
	    	}
	    	else
	    		cout << "Valid";
	    }
	    cout << endl;
	}
	return 0;
}