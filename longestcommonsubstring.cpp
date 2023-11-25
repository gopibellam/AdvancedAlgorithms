#include<iostream>
using namespace std;



//Method to find the longest common substring
void find_substring(string s1,string s2){
    int m=s1.length();
    int n=s2.length();

    //Matrix to store values of lengths of commmon substrings
    int dp[m+1][n+1];
    int maxlen=0;
    int maxind=0;
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
        
        
        if (i == 0 || j == 0)
           dp[i][j] = 0;

            //Matching characters
        else if(s1[i-1]==s2[j-1]){
            //Add one to the current length stored at previous diagonal element
            dp[i][j]=dp[i-1][j-1]+1;

                //updating maximum length
                if(maxlen<dp[i][j]){
                    maxlen=dp[i][j];
                    maxind=i-1;
                }
            }
            else{
                //no common substring
                dp[i][j]=0;
            }
        }
    }

    
    cout<<"The longest common substring of length "<<maxlen<<" is "<<s1.substr(maxind-maxlen+1,maxlen);

    cout<<endl<<"Lookup table"<<endl<<"  ";

    for(int i=0;i<n;i++){
        cout<<s2[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<=m;i++){
        if(i>0)
            cout<<s1[i-1]<<" ";
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }


}



int main(){
    string s1,s2;
    cout<<"Input strings"<<endl;
    cin>>s1;
    cin>>s2;
    
    find_substring(s1,s2);

    return 0;

}