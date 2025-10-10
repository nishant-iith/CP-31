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

/**
 * Problem: Given n, k and x find out wheater it is possible to get sum x using k elements from 1 to n
 * Approach: Find the minimum and maximum sum possible using k elements from 1 to n and the check if x lies in between them
 */

class Solution : public Helper {
private:
    ll totalSum(ll x){
        return (x*(x+1))/2;
    }
    ll minSum(ll k, ll n){
        if(k>n) return LLONG_MAX;
        return totalSum(k);
    }
    ll maxSum(ll k, ll n){
        if(k>n) return LLONG_MIN;
        return totalSum(n) - totalSum(n-k);
    }
public:
    void solve(){
        // Your code here
        ll n, k, x;
        cin>>n>>k>>x;
        bool possible = (x>=minSum(k, n) && x<=maxSum(k, n));
        if(possible) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
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