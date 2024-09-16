 #include<iostream>
 #include<vector>
 using namespace std;
 vector<int>st;
 void buildTree(int arr[],int i,int lo,int hi){
    if(lo==hi){ //base case 
    st[i]=arr[lo];
    return ;

 }
        int mid=lo+(hi-lo)/2;  //(lo+hi)/2
        buildTree(arr,2*i+1,lo,mid); // left subtree
        buildTree(arr,2*i+2,mid+1,hi);// right subtree
         st[i]=st[2*i+1] + st[2*i+2];
    }

    int getSum(int i,int lo,int hi,int& l,int& r){
        if(l>hi || r<lo) return 0;
        if(lo>=l && hi<=r) return st[i];
        int mid=lo+(hi-lo)/2; // (lo+hi)/2
        int leftSum= getSum(2*i+1,lo,mid,l,r);
        int rightSum=getSum(2*i+2,mid+1,hi,l,r);
        return leftSum+rightSum;
    }
//     int sumRange(int left,int right){
//         return getSum(0,0,n-1,left,right);
//     }
// };
int main(){
    int arr[]={1,4,2,8,6,4,9,3}; //0 to 7
    int n=sizeof(arr)/4;
    st.resize(4*n);
    buildTree(arr,0,0,n-1);
    int l,r;
    cout<<"Enter the range";
    cin>>l>>r;
    cout<<getSum(0,0,n-1,l,r)<<endl;
}