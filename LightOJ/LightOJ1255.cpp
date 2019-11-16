#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
int kmp(string text, string  pattern){
    int l = pattern.size();
    int *lps = (int *)malloc(sizeof(int)*l);
    int index = 0,i;
    //create a lps arrray
    for (i =1; i<l;i++){
        if(pattern[index] == pattern[i]){
            lps[i] = index+1;
            index++;
        }
        else{
            if(index!=0){
                index = lps[index-1];
            }
            else{
                lps[i] = 0 ;
            }
        }
    }
    index= 0;
    i =0 ;
    int cnt = 0;
    //find a substruing
        while(i<text.length()){
        if(text[i] == pattern[index]){
            index++;
            i++;
            if(index==l){
                cnt ++;
            }
        }
        else{
            if(index!=0)  index = lps[index-1];
            else i++;
        }
    }
    return cnt;
}
//Driver code
int main(){
    string text,pat;
    int n, c = 1;
    cin>> n;
    while(c <= n){
        cin>> text >> pat;
        printf("Case %d: %d\n",c,kmp(text,pat));
        c++;
    }
    return 0 ;
}
