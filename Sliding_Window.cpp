Mtlb jaise do window  ko slide kiya jata hai waise usi type ka technique.

// Example:-> i have to find the maximum sum  of the given array from the 
// taking range of first four indexing.


//  0 1 2 3 4 5 (Index)
//  3 4 5 6 7 8 (Number)

 int current=0;
 for(int i=0;i<w;i++){
    current+=arr[i];
 }
 int maxx=current;
 for(int i=1;i<n-w;i++){
    current=current-arr[i-1]+arr[i+w-1];
    if(current > maxx){
        maxx=current;
    }
 }
 return maxx;