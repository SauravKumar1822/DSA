# include <bits/stdc++.h>
using namespace std;

void build(int ind,int low,int high,vector<int> &arr,vector<int> &seg){
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,arr,seg);
    build(2*ind+2,mid+1,high,arr,seg);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    return;
}

int query(int ind,int low, int high,int l,int r,vector <int> &seg){
    if(r<low || high<l) return INT_MAX;
    if(low>=l && high<=r) return seg[ind];
    int mid=(low+high)/2;
    int q1=query(2*ind+1,low,mid,l,r,seg);
    int q2=query(2*ind+2,mid+1,high,l,r,seg);
    return min(q1,q2);
}

void update(int ind,int low,int high,int newi,int newv,vector<int> &seg){
    if(low==high){
        seg[ind]=newv;
        return;
    }
    int mid=(low+high)/2;
    if(newi<=mid) update(2*ind+1,low,mid,newi,newv,seg);
    else update(2*ind+2,mid+1,high,newi,newv,seg);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
    return;
}

int main(){
    cout <<"size of arr:";
    int n=6;
    // cin>> n;
    vector <int> arr={2,1,0,4,3,7};
    // for(int i=0;i<n;i++)cin>>arr[i];
    vector<int> seg(4*n);
    build(0,0,n-1,arr,seg);
    cout<<"\n"<<"segment Tree:";
    for(int i=0;i<4*n;i++)cout<<seg[i]<<" ";
    cout<<"\n"<<"Query:";

    // int l,r;
    // for(int i=0;i<2;i++){
    //     cin>>l>>r;
    //     cout<<query(0,0,n-1,l,r,seg)<<endl;
    // }

    int newi,newv;
    cin>>newi>>newv;
    update(0,0,n-1,newi,newv,seg);
    cout<<"\n"<<"segment Tree: "<<endl;
    for(int i=0;i<4*n;i++)cout<<seg[i]<<" ";
    return 0;
}
