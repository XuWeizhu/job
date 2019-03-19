#include<iostream>
#include<string>
#include <fstream>
#include <vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> sorted(vector<int> A);
void exch(int* a, int* b);
void merge(vector<int>* Ap, vector<int>* Auxp, int a, int b, int c);
void sort_core(vector<int>* A, int a, int b);
void print_self(vector<int>*A);
void swim(vector<int>* A, int k);
void sink(vector<int>* A, int k, int MAX_n=-2);

int main(){
    ifstream fin("sort");
    int length = 0;
    int tmp;
    fin >> length;
    fin.get();
    
    vector<int> str_random, str_sorted;
    for(int i = 0;i<length;++i){
        fin >> tmp;
        str_random.push_back(tmp);
    }

    fin.get();
    for(int i = 0;i<length;++i){
        fin >> tmp;
        str_sorted.push_back(tmp);
    }
    fin.close();

    if(str_random.size()!=str_sorted.size()){
        cout<<" error"<<endl;
        return 0;
    }
    
    vector<int> out_array;
    out_array = sorted(str_random);
    if(out_array==str_sorted){
        cout<<"great!"<<endl;
        cout<<"\nanswer : "<<endl;
        for(int i = 0;i<str_sorted.size();++i){
            cout<<str_sorted[i]<<'\t';
        }
        cout<<"\nyour answer : "<<endl;
        for(int i = 0;i<out_array.size();++i){
            cout<<out_array[i]<<'\t';
        }
        cout<<endl;        

    }else{
        cout<<"error\n"<<endl;

        cout<<"input : "<<endl;
        for(int i = 0;i<str_random.size();++i){
            cout<<str_random[i]<<'\t';
        }        
        cout<<"\nanswer : "<<endl;
        for(int i = 0;i<str_sorted.size();++i){
            cout<<str_sorted[i]<<'\t';
        }
        cout<<"\nyour answer : "<<endl;
        for(int i = 0;i<out_array.size();++i){
            cout<<out_array[i]<<'\t';
        }
        cout<<endl;
        
    }
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

vector<int> sorted(vector<int> A){
    A.push_back(A[0]);
    int N = A.size()-1;
    int tmp = log(N)/log(2);
    
    for(int i = pow(2,tmp)-1;i>=1;--i){
        sink(&A, i);
    }
    

    for(int i = N;i>=1;--i){
        exch(&(A[i]), &(A[1]));
        sink(&A, 1, i-1);
    }

    reverse(A.begin(), A.end());
    A.pop_back();
    return A;
}

void swim(vector<int>* A, int k){
    while(k>1){
        if((*A)[k]<(*A)[k/2]){
            exch(&((*A)[k]), &((*A)[k/2]));
            k /= 2;
        }
    }
}

void sink(vector<int>* A, int k, int MAX_n){
    int N = MAX_n;
    if(MAX_n==-2) N = (*A).size()-1;
    while(k*2<=N){
        int j = k*2;
        if(j<N && (*A)[j]>(*A)[j+1]) ++j;
        if((*A)[j]<(*A)[k]){
            exch(&((*A)[k]), &((*A)[j]));
            k = j;
        }else break;
        }
}

//end

