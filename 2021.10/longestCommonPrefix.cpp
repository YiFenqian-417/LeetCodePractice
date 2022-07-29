#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<2)return strs[0];
        int len = strs.size();
        sort(strs.begin(),strs.end());
        string str="";
        int flag=1;
        for(int i=0;i<strs[0].size();i++){
            char ch=strs[0][i];
            for(int j=0;j<strs.size();j++){
                if(i>=strs[j].size()||strs[j][i]!=ch){
                    flag=0;
                    break;
                }
            }
            if(flag==0)break;
            str+=ch;
        }
    return str;
}

int main()
{
    vector<string>strs;
    string a="flower";
    string b="flow";
    string c="flight";
    strs.push_back(a);
    strs.push_back(b);
    strs.push_back(c);
    a=longestCommonPrefix(strs);
    cout<<a<<endl;
    return 0;
}