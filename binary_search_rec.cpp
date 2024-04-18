#include<iostream>
#include<fstream>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;

const int size = 100000;



void sorted_generator(int a[],int n){
 for(int i=0;i<n;i++){
    a[i]= i;
 } 
}

void binary_search(int a[],int stop,int n_to_search,int start=0){
    int mid=start+(stop-start)/2;
    if(start>stop){
      //cout<<"number not found in array"<<endl;
      return;
    }
    else{
      if(a[mid]==n_to_search){
         //cout<<"number found "<<endl;
         return;
      }
      else if(a[mid]>n_to_search){
         stop = mid-1;
         binary_search(a,stop,n_to_search,start);
      }
      else{
         start = mid+1;
         binary_search(a,stop,n_to_search,start);
      }
    }
   
}

int main(){
 int a[size];
 fstream file;
 file.open("binary_search_result.txt",ios::out);
 for(int i=1; i<=size;i=i*10){
    int avg_time =0;
    int total_time = 0;
    sorted_generator(a,i);
    for (int m=0;m<10;m++){
    auto start = high_resolution_clock::now();
    binary_search(a,i-1,3000001);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    total_time +=duration.count();
    }
    avg_time = total_time/10;
    cout<<"avg time taken for size of array = "<<i<<" is "<<avg_time<<" microseconds"<<endl;
     file<<i<<"   "<<avg_time<<endl;
   
 }
 return 0;
}
