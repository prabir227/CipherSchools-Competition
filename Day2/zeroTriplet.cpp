#include<iostream>
using namespace std;
int main(){
    int n;
    bool condition=0;
    cout<<"Enter the number of elements in array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the space separated elements of the array: "<<endl;
    for (int l=0;l<n;l++){
        cin>>arr[l];
    }
    for(int i=0;i<(n-2);i++){
        for (int j=0;j<(n-1);j++){
            for(int k=0;k<(n-2);k++){
                if ((arr[i]+arr[j]+arr[k])==0){
                    condition =1;
                    break;
                }
            }
        }
    }
    cout<<"The required output is: "<<condition;
    return 0;
}
