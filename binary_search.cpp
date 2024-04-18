#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

const int size = 300000;



void sorted_generator(int a[],int n){
 for(int i=0;i<n;i++){
    a[i]= i;
 } 
}

int binary_search(int a[],int n , int n_to_search){
    int start = 0;
    int end = n-1;
    int mid=start+(end-start)/2;
    while(start<=end){
    if(n_to_search<a[mid])
    end=mid-1;
    else if(n_to_search>a[mid])
    start=mid+1;
    else if(n_to_search==a[mid]){
       return mid;
    }
     mid=start+(end-start)/2;}
    return -1;
}

int main(){
 int a[size];
 fstream file;
 file.open("binary_search_ite.txt",ios::out);
 for(int i=1; i<=size;){
    int avg_time =0;
    int total_time = 0;
    sorted_generator(a,i);
    for (int m=0;m<10;m++){
    auto start = high_resolution_clock::now();
    int index = binary_search(a,i,3000001);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    total_time +=duration.count();
    }
    avg_time = total_time/10;
    cout<<"avg time taken for size of array = "<<i<<" is "<<avg_time<<" microseconds"<<endl;
     file<<"("<<i<<","<<avg_time<<")"<<endl;
      if(i<1000)
     i *=10;
     else if(i>=1000 && i<5000)
     i=5000;
     else
     i +=5000;
 }
}
