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
};

class Solution : public Helper {
    public:
        void solve(){
            // Your code here
            // using the combination of 2 and 3 we can create the number
            ll n, k, x;
            cin>>n>>k>>x;

            if(x != 1){
                cout<<"Yes"<<endl;
                cout<<n<<endl;
                loop(i, 0, n){
                    cout<<"1"<<" ";
                }
                cout<<endl;
            }
            else {
                // if x is 1 and k is also 1 then it is not possible
                // if x is 1 and k is 2 then we can create only even number
                if(k == 1 || (k == 2 && n % 2 == 1)){
                    cout<<"No"<<endl;
                }
                else {
                    // it will always be possible
                    cout<<"Yes"<<endl;

                    // now if n is even then we can create using 2
                    if(n % 2 == 0){
                        cout<<n/2<<endl;
                        loop(i, 0, n/2){
                            cout<<"2"<<" ";
                        }
                        cout<<endl;
                    }
                    else {
                        cout<<((n - 3)/2)+1<<endl; // number of integers used
                        loop(i, 0, ((n - 3)/2)){
                            cout<<"2"<<" ";
                        }
                        cout<<"3"<<endl;
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