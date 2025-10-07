# include <bits/stdc++.h>
using namespace std;

void update(vector <int> &fen,int ind, int val){
    while(ind<fen.size()){
        fen[ind]+=val;
        ind=ind+(ind & (-ind));
    }
    return;
}

int query(vector <int> &fen,int ind){
    if(ind<0 || ind>=fen.size()) return -1;
    int val=0,hval=0;
    while(ind>0){
        val+=fen[ind];
        ind=ind&(ind-1);
    }
    return val;
}

void build(vector <int> arr, vector <int> &fen){
    for(int i=0;i<arr.size();i++){
        update(fen,i+1,arr[i]);
    }
    return;
}

int main(){
    int n;
    vector <int> arr={1,0,2,1,1,3,0,4,2,5,2,2,3,1,0,2};
    n=arr.size();
    cout<<"Size of arr: "<<n<<endl;
    vector <int> fenwick(n+1,0);
    build(arr,fenwick);
    for(auto it:fenwick) cout<<it<<" ";
    cout<<endl;
    int l,r;
    cout<<"Query 1-based indexing:";
    cin>>l>>r;
    cout<<query(fenwick,r)-query(fenwick,l-1)<<endl;
    return 0;
}
