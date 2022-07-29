#include<iostream>
#include<vector>

using namespace std;

bool findNumberIn2DArray(vector <vector <int> >& matrix, int target) {
    int hang = 0;
    int lie = matrix[0].size()-1;
    int hangs = matrix.size()-1;
    do{
        if(matrix[hang][lie]==target){
            return true;
        }else if(matrix[hang][lie]<target){
           hang++;
        }else{
           lie--;
        }
    }while(hang<=hangs&&lie>=0);
    return false;       
}

int main(){

    vector<vector<int> > matrix= {
       {-1,3}
    };
    cout<<findNumberIn2DArray(matrix,-1)<<endl;;
    return 0;
}


