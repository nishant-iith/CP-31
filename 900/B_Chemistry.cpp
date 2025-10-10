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
 * Problem : A string s of length n and integer k and we can remove exactly k characters from s to make it palindrome.
 * Solution : For any palindromic string there can be at most 1 character with odd frequency.
 */

class Solution : public Helper {
public:
    void solve(){
        // Your code here
        // if string is odd then there should be 1 odd frequency character
        // if string is even then there should be 0 odd frequency character
        ll n, k;
        cin >> n >> k;
        string s = stringInput();
        map<char, int> freq;
        for(char c : s) freq[c]++; 
        int countOfOddFreq = 0;
        for(auto it : freq) if(it.second % 2 != 0) countOfOddFreq++;
        if(countOfOddFreq <= k + 1) cout << "YES" << endl;
        else cout << "NO" << endl;
        return ;
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