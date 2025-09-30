// Range Query Sum
// Lazy propagation in Fenwick Tree

# include <bits/stdc++.h>
using namespace std;

class ST{
    vector <int> seg,lazy;

    public:
        ST(int n){
            seg.resize(4*n);
            lazy.resize(4*n);
        }

        void printt(){
            for(auto it:seg) cout <<it<<" ";
            cout<<endl;
        }

        void build(int ind,vector<int> &arr,int l, int h){
            if(l==h){
                seg[ind]=arr[l];
                return;
            }
            int mid=(l+h)/2;
            build(2*ind+1,arr,l,mid);
            build(2*ind+2,arr,mid+1,h);
            seg[ind]=seg[2*ind+1]+seg[2*ind+2];
            return;
        }

        int query(int ind,int low, int high,int gl,int gh){
            if(lazy[ind]!=0){
                seg[ind]+=(high-low+1)*lazy[ind];
                if(low!=high){
                    lazy[2*ind+1]+=lazy[ind];
                    lazy[2*ind+2]+=lazy[ind];
                }
                lazy[ind]=0;
            }
            if(gh<low || high<gl) return 0;
            if(low>=gl && high<=gh) return seg[ind];
            int mid=(low+high)/2;
            int q1=query(2*ind+1,low,mid,gl,gh);
            int q2=query(2*ind+2,mid+1,high,gl,gh);
            return q1+q2;
        }

        void update(int ind, int val, int l, int h, int gl,int gh){
            if(lazy[ind]!=0){
                seg[ind]+=(h-l+1)*lazy[ind];
                if(l!=h){
                    lazy[2*ind+1]+=lazy[ind];
                    lazy[2*ind+2]+=lazy[ind];
                }
                lazy[ind]=0;
            }
            if(h<gl || l>gh) return;

            if(l>=gl && h<=gh){
                seg[ind]+=(h-l+1)*val;
                if(l!=h){
                    lazy[2*ind+1]+=val;
                    lazy[2*ind+2]+=val;
                }
                return;
            }

            int mid=(l+h)>>1;
            update(2*ind+1,val,l,mid,gl,gh);
            update(2*ind+2,val,mid+1,h,gl,gh);
            seg[ind]=seg[2*ind+1]+seg[2*ind+2];
            return;
        }
};

int main(){
    int n;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    ST st(n);
    st.build(0,arr,0,n-1);
    st.printt();
    int t,gl,gh,type,val;
    cin>>t;
    while(t--){
        cin>>type>>gl>>gh;
        if(type==1){
            cout<<st.query(0,0,n-1,gl,gh)<<endl;
        }else{
            cin>>val;
            st.update(0,val,0,n-1,gl,gh);
        }
        st.printt();
    }
    return 0;
}
