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
    private:
        bool isDivisor(ll a, ll b){  // is b a divisor of a
            if(a == 0 || b == 0) return false;
            return a % b == 0;
        }
    public:
        void solve(){
            // Your code here
            ll x, k;
            cin>>x>>k;
            if(k>x){ 
                cout<<"1"<<endl;
                cout<<x<<endl;
            }
            else {
                rloop(i, x + 1, 0){
                    if(isDivisor(x - i, k) || isDivisor(i, k)){
                        continue;
                    }
                    else {
                        if(i == x){
                            cout<<"1"<<endl;
                            cout<<x<<endl;
                        } 
                        else {
                            cout<<"2"<<endl;
                            cout<<i<<" "<<(x - i)<<endl;
                        }
                        break;
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