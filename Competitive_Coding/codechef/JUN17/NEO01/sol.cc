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

bool myfunction (int i,int j) { return (i>j); }

int main(int argc, char const *argv[])
{
	// For handling large inputs.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll int T, N, Arr[100005], sumP, sumN, Cp, Cn, num;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> T;
	while(T-- > 0) {			
		vector<ll> ansP, ansN;
		cin >> N;
		sumP  = 0;
		sumN = 0;
		Cp = 0; Cn = 0;
		for (ll int i = 0; i < N; ++i)
		{
			cin >> num;
			if(num >= 0){
				sumP += num;
				Cp++;
			}
			else{
				ansN.push_back(num);
			}
		}
		sort(ansN.begin(), ansN.end(), myfunction);
		ll total, flag, newTotal;
		flag = 0;
  		for (vector<ll>::iterator it=ansN.begin(); it!=ansN.end(); ++it){
  			total = sumP*Cp;  
  			newTotal = ((sumP+*it) * (Cp+1));
    		if(flag == 0 && (total < newTotal)){    			
    			Cp++;
    			sumP += *it;
    		}
    		else{
    			flag = 1;    			
    			sumN += *it;
    			Cn++;
    		}
		}
		cout << sumP * Cp +  sumN  << endl;
	}
	
	return 0;
}