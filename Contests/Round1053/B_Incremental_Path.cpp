#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;

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
        ll n,m;
        cin>>n>>m;
        string s=stringInput();

        set<ll> white;
        loop(i, 0, 2 * (n + m)) white.insert(i + 1);
        set<ll> black;
        loop(i, 0, m){
            ll t;
            cin>>t;
            white.erase(t);
            black.insert(t);
        }

        // solution;
        ll cur = 1;

        loop(i, 0, n){
            // operation A: move to the next cell and if it is white turn it black
            if(s[i] == 'A'){
                // go to the next cell
                cur++;

                // if current cell is white turn it black
                if(white.count(cur)){
                    white.erase(cur);
                    black.insert(cur);
                }
            }
            // operation B: 
            else {
                // find the next white cell 
                cur = *white.upper_bound(cur);
                auto temp = cur; // the next white cell
                cur = *white.upper_bound(cur); // move to the next cell
                // turn the temp cell black
                white.erase(temp);
                black.insert(temp);
            }
        }
        cout<<black.size()<<endl;
        for(auto x : black) cout<<x<<" ";
        cout<<endl;
        return;
    }
};

int main(){
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