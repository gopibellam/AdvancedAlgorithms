#include <bits/stdc++.h> 
using namespace std;

int main(){
    int n,t;
    cout<<"Enter number of integers in array ";
    cin>>n;
    int arr[n];
    cout<<"Enter array numbers\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter target number ";
    cin>>t;
    int ans[2];
    
    //method
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j){
                if(arr[i]+arr[j]==t){
                    ans[0]=i;
                    ans[1]=j;
                }
            }
        }
    }
    
    cout<<"The solution is \n";
    cout<<ans[0]<<" "<<ans[1];

}