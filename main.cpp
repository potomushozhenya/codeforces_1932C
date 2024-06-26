#include <iostream>

void build(unsigned short* t, int &n, int&m) {  // build the tree
    for (int i = n - 1; i > 0; --i) t[i] = (t[i<<1] * t[i<<1|1])%m;
}

void modify(unsigned short* t, int &n, int&m, int p, int value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = (t[p] * t[p^1])%m;
}

int query(int l, int r, const unsigned short* t, int &n, int &m) {  // mod multiply on interval [l, r]
    unsigned short res = 1;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
        if (l&1) res = (res*t[l++])%m;
        if (!(r&1)) res = (res*t[r--])%m;
    }
    return res;
}

int main() {
    int t;
    std::cin>>t;
    for (int i = 0; i < t; ++i) {
        int n,m;
        std::cin>>n>>m;
        unsigned short a[2*n];
        char s[n];
        for (int j = 0; j < n; ++j) {
            std::cin>>a[j+n];
            a[j+n]=a[j+n]%m;
        }
        for (int j = 0; j < n; ++j) {
            std::cin>>s[j];
        }
        build(a,n,m);
        int l=0,r=n;
        int c=0;
        while (c<n){
            std::cout<<query(l,r-1,a,n,m)<<' ';
            if (s[c]=='L'){
                ++l;
            } else{
                --r;
            }
            ++c;
        }
        std::cout<<'\n';
    }
}
