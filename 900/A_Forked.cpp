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
 * Question : https://codeforces.com/problemset/problem/1904/A
 * Solution : https://codeforces.com/contest/1904/submission/342875032
 */

class Solution : public Helper {
public:
    vector<int> dx = {1, 1, -1, -1};
    vector<int> dy = {1, -1, 1, -1};

    void solve(){
        // Your code here
        ll a, b; // movement in one direction and other direction
        ll kx, ky; // King's initial position
        ll qx, qy; // Queen's initial position
        cin>>a>>b>>kx>>ky>>qx>>qy;

        // king can be attacked from exactly 8 positions by knight and same goes for queen
        // In each quadrant there will be (a, b) and (b, a) positions
        // So total 8 positions

        set<pair<ll, ll>> kingAttackPositions;
        set<pair<ll, ll>> queenAttackPositions;

        loop(i, 0, 4){
            // king can be attacked from 
            kingAttackPositions.insert({kx + dx[i]*a, ky + dy[i]*b}); // a,b for king
            kingAttackPositions.insert({kx + dx[i]*b, ky + dy[i]*a}); // b,a for king


            // queen can attack from
            queenAttackPositions.insert({qx + dx[i]*a, qy + dy[i]*b}); // a,b for queen
            queenAttackPositions.insert({qx + dx[i]*b, qy + dy[i]*a}); // b,a for queen
        }

        // Now we need to take the intersection of both the sets for a position of common attack possible
        ll count = 0LL;
        for(auto pos : kingAttackPositions){
            if(queenAttackPositions.find(pos) != queenAttackPositions.end()){
                count++;
            }
        }

        cout<<count<<endl;

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