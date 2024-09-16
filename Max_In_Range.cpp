// Question :: Is i have to find maximum of the given range.
// TC=Q*logn
#include<iostream>
#include<climits>
#include<vector>
using namespace std;
vector<int>st; //st=Subtree
void buildTree(int arr[],int i,int lo,int hi){ // lo and hi are index from 
//lo to hi.actual range of array not the segment tree of an array.
    if(lo==hi){ //Base Case
        st[i]=arr[lo];
        return;
    }
    int mid=lo +(hi-lo)/2; // (lo+hi)/2
    buildTree(arr,2*i+1,lo,mid); //Left subtree
    buildTree(arr,2*i+2,mid+1,hi);//right subtree
    st[i]= max(st[2*i+1],st[2*i+2]);
}
int getMax(int i,int lo,int hi,int& l,int& r){
    if(l>hi || r<lo) return INT_MIN;  
    if(lo>=l && hi<=r) return st[i]; 
    int mid= lo+(hi-lo)/2; //(lo+hi)/2
    int leftMax=getMax(2*i+1,lo,mid,l,r);
    int rightMax=getMax(2*i+2,mid+1,hi,l,r);
    return max(leftMax,rightMax);
}
int main(){
    int arr[]={1,4,2,8,6,4,9,3}; // 0 to 7.
    int n=sizeof(arr)/4;
    st.resize(4*n);
    buildTree(arr,0,0,n-1);
    int q; cin>>q;
    while(q--){
    int l,r;
    cout<<"Enter the range:::";
    cin>>l>>r;
    cout<<getMax(0,0,n-1,l,r)<<endl; // 
}
}
// Maximum value of range from 1 to 5 is 8.

// 3
// Enter the range:::1 5
// 8
// Enter the range:::2 6
// 9
// Enter the range:::2 8
// 9