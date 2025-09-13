#include<bits/stdc++.h>
using namespace std;

//type names
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;

// macros
#define pb push_back
#define all(x) (x).begin(),(x).end()

#define loop(i, a, b) for(int i=a; i<b; i++)
#define rloop(i, a, b) for(int i=a-1; i>=b; i--)

class Helper {
    protected:
        vi arrayInput(){
            int n;
            cin>>n;
            vi arr(n);
            loop(i, 0, n) cin>>arr[i];
            return arr;
        }
        
        vi arrayInput(int n){
            vi arr(n);
            loop(i, 0, n) cin>>arr[i];
            return arr;
        }

        string stringInput(){
            string s;
            cin>>s;
            return s;
        }

        void printArray(const vi &arr){
            for(int i=0; i<arr.size(); i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

class Solution : public Helper {
    public:
        void solve(){
            // Your code here
            ll a, b;
            cin >> a >> b;
            if (a % 2 == 0 && b % 2 == 1) {
                cout << -1 << endl;
            } else if (a % 2 == 1 && b % 4 == 2) {
                cout << -1 << endl;
            } else {
                if (a % 2 == 0) {
                    ll candidate1 = a + b;
                    ll candidate2 = a * (b / 2) + 2;
                    cout << max(candidate1, candidate2) << endl;
                } else {
                    if (b % 2 == 1) {
                        ll candidate1 = a + b;
                        ll candidate2 = a * b + 1;
                        cout << max(candidate1, candidate2) << endl;
                    } else {
                        ll candidate1 = a * 2 + b / 2;
                        ll candidate2 = a * (b / 2) + 2;
                        cout << max(candidate1, candidate2) << endl;
                    }
                }
            }
        }
};

int main(){
    // fast input output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){ 
        Solution sol;
        sol.solve();
    }
    return 0;
}