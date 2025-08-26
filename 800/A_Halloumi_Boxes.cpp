#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, k;
        cin>>n>>k;

        vector<long long> a(n);

        for(int i = 0; i<n; i++){
            cin>>a[i];
        }

        vector<long long> a_copy = a;
        sort(a_copy.begin(), a_copy.end());

        if(a_copy == a || k > 1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }
}