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
 * Problem https://codeforces.com/problemset/problem/1777/A
 * Solution : if two consecutive elements are both even or both odd, increment the counter.
 * the couter is the number of pairs that we will choose and do the operation on. Odd * Odd = Odd and Even * Even = Even
 */

class Solution : public Helper {
public:
    void solve(){
        // Your code here
        vi arr = arrayInput();
        int n = arr.size();
        int ctr = 0;
        loop(i, 0 , n-1){
            // if(arr[i]%2 == 0 && arr[i+1]%2 == 0){
            //     ctr++;
            // }
            // else if(arr[i]%2 != 0 && arr[i+1]%2 != 0){
            //     ctr++;
            // }
            if((arr[i]%2) == (arr[i+1]%2)){ // this will check tha parity of adjacent elements
                ctr++;
            }
        }
        cout<<ctr<<endl;
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