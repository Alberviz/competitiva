#include<bits/stdc++.h>
using namespace std;


long long sum(vector<int> &v, vector<long long> &b,int B, int l , int r){
    long long sum = 0;
    int bloqueizq = (l+B-1)/B;
    int bloquedcha = r/B;
    if(bloqueizq>=bloquedcha){
        for(int i=l;i<r;i++){
            sum += v[i];
        }
    }else{
            for(int i=l;i<bloqueizq*B;i++){
            sum += v[i];
        }
        for(int i=bloqueizq;i<bloquedcha;i++){
            sum += b[i];
        }
        for(int i=bloquedcha*B;i<r;i++){
            sum += v[i];
        }
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n,0);
    for (int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<int> u = v;
    sort(u.begin(),u.end());
    int B = sqrt(n);
    int cbloq = (n+B-1)/B;
    vector<long long> b1(cbloq,0);
    for(int i=0;i<cbloq;i++){
        long long sumbloq = 0;
        for(int j=i*B;j<i*B+B && j<n;j++){
            sumbloq += v[j];
        }
        b1[i]=sumbloq;
    }
    vector<long long> b2(cbloq,0);
    for(int i=0;i<cbloq;i++){
        long long sumbloq = 0;
        for(int j=i*B;j<i*B+B && j<n;j++){
            sumbloq += u[j];
        }
        b2[i]=sumbloq;
    }

    int m;
    cin >> m;
    while(m--){
        int type;
        cin >> type;
        int l,r;
        cin >> l >> r;
        l--;
        if(type == 1){
            cout << sum(v,b1,B,l,r) << endl;
        }else{
            cout << sum(u,b2,B,l,r) << endl;
        }
    }
}

