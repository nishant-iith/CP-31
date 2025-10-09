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
 * Problem : https://codeforces.com/problemset/problem/1766/A
 * Solution : We need to find number of elements which has only 1 non zero digit from 1 to n for the number n.
 * For example, for n=13, the numbers are 1,2,.........,12,13. Here the numbers which have only 1 non zero digit are 1,2,3,4,5,6,7,8,9 and 10. So the answer is 10.
 * Another example, for n=42, the numbers are 1,2,....,40,41 and 42. Here the numbers which have only 1 non zero digit are 1 to 9 and 10, 20, 30 40. So the answer is 13.
 * 
 * Here we will do precomputation of all the numbers which have only 1 non zero digit from 1 to 10^9 and store them in a vector.
 * 
 */

class Solution : public Helper {
private: 
    // bool isExtremelyRound(int n)
    bool isExtremelyRound(int n){
        ll countOfDigits = 0;
        ll countOfZeros = 0;
        while(n){
            if(n%10 == 0) countOfZeros++;
            countOfDigits++;
            n /= 10;
        }
        return (countOfDigits - countOfZeros) == 1;
    }

    vector<int> precompute;
    void pre(){
        loop(i, 1, 1e7){
            if(isExtremelyRound(i)){
                precompute.pb(i);
            }
        }
    }
public:
    void solve(){
        // Your code here
        int n; cin>>n;
        if(precompute.size() == 0) pre();
        // upper bound of n in the precompute array 
        int ans = upper_bound(all(precompute), n) - precompute.begin();
        cout<<ans<<endl;
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