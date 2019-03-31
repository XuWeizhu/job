#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int edit_dis(string w1, string w2);

int main(){
    string word1 = "horse";
    string word2 = "rorse";
    int out = edit_dis(word1, word2);
    cout<<"your answer is :"<<out<<endl;
    cout<<"answer is : 1"<<endl;

    return 0;
}

void print_self(vector<int>*A){
    int N = (*A).size();
    for(int i = 0;i<N;++i){
        cout<<(*A)[i]<<'\t';
    }
    cout<<endl;
}

void exch(int* a, int* b){
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}


//Here is your code
//min heap
int edit_dis(string w1, string w2){
    int length1 = w1.length();
    int length2 = w2.length();
    vector<int> A(length1+1, 0);

    for(int i = 0;i<=length1;++i){
        A[i] = i;
    }

    for(int j = 1;j<=length2;++j){
        int pre = A[0];
        int tmp = pre;
        A[0] = j;

        for(int i = 1;i<=length1;++i){
            if(w1[i-1]==w2[j-1]){
                A[i] = pre;
            }else{
                tmp = A[i];
                A[i] = min(pre, min(A[i], A[i-1]))+1;
                pre = tmp;
            }
        }
    }
    return A[length1];

}

//end

