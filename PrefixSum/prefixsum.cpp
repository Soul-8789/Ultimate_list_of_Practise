#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    
    vector<int> prefixSum(n+1);
    for(int i=1;i<=n;i++){
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    for(int i=1;i<=n;i++){
        cout<<prefixSum[i]<<" ";
    }
    cout<<endl;

    return 0;
}