#include<iostream>
using namespace std;
int main(){
    int max_water=0,width,test;
    cout<<"Enter the length of array: ";
    cin>> width ;
    int arr[width];
    cout<<"Enter space separated elements of the array: "<<endl;
    for (int k=0;k<width;k++){
        cin>>arr[k];
    }
    for(int i=0;i<width;i++){
        for (int j= (i+1);j<width;j++){
            if (arr[i]<=arr[j]){
                test = arr[i]*(j-i);
            }
            else if (arr[i]>arr[j]){
                test=arr[j]*(j-i);
            }
            if(max_water<test){
                max_water=test;
            }
        }
    }
    cout<<"The maximum area of water that can be stored is: "<<max_water<<endl;
    return 0;
}
