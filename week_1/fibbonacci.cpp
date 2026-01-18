#include <iostream>
using std::cout;
using std::cin;

int fibbonacci_iter(int n){
    if (n<=1) return n;
    int a = 0, b = 1;
    int c;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return b;
}

struct Mat {
    int a, b, c, d;   // [[a,b],[c,d]]
};

Mat mul(Mat x, Mat y) {
    return {
        x.a*y.a + x.b*y.c,
        x.a*y.b + x.b*y.d,
        x.c*y.a + x.d*y.c,
        x.c*y.b + x.d*y.d
    };
}

Mat mat_pow(int n) {
    Mat T={1,1,1,0};
    Mat res={1,0,0,1};

    while(n>0){
        if(n & 1){
            res=mul(res,T);
        }
        n>>1;
        T=mul(T,T);
    }
    return res;
}

int fibbonacci_mat(int n){
    if(!n) return 0;
    Mat R=mat_pow(n-1);
    return R.a;
}

int main(){
    int n;
    cin>>n;
    cout<<fibbonacci_iter(n);
    return 0;
}