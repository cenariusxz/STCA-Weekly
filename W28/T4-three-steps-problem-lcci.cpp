class Solution {
public:
    typedef long long ll;
    const int mod = 1e9 + 7;
    struct mat{
        int r,c;
        ll m[4][4];
        mat(){}
        mat(int r,int c):r(r),c(c){}
    };

    void clear(mat &a){
        memset(a.m,0,sizeof(a.m));
    }

    mat mul(mat a,mat b){
        mat tmp(a.r,b.c);
        int i,j,k;
        for(i=1;i<=tmp.r;i++){
            for(j=1;j<=tmp.c;j++){
                tmp.m[i][j]=0;
                for(k=1;k<=a.c;k++){
                    tmp.m[i][j]=(tmp.m[i][j]+(a.m[i][k]*b.m[k][j])%mod)%mod;
                }
            }
        }
        return tmp;
    }

    mat QP(mat a,int n){
        mat ans(a.r,a.r),tmp(a.r,a.r);
        memcpy(tmp.m,a.m,sizeof(tmp.m));
        clear(ans);
        for(int i=1;i<=ans.r;i++){
            ans.m[i][i]=1;
        }
        while(n){
            if(n&1)ans=mul(ans,tmp);
            n>>=1;
            tmp=mul(tmp,tmp);
        }
        return ans;
    }

    void print(mat a){
        for(int i=1;i<=a.r;++i){
            for(int j=1;j<=a.c;++j){
                printf("%lld",a.m[i][j]);
                if(j==a.c)printf("\n");
                else printf(" ");
            }
        }
    }

    int waysToStep(int n) {
        mat a;
        a.r = 3; a.c = 1;
        a.m[1][1] = 1;
        a.m[2][1] = 1;
        a.m[3][1] = 2;
        mat t; clear(t);
        t.r = 3;
        t.c = 3;
        t.m[1][2] = t.m[2][3] = t.m[3][1] = t.m[3][2] = t.m[3][3] = 1;
        mat tmp = QP(t, n);
        tmp = mul(tmp, a);
        return (int)tmp.m[1][1];
    }
};