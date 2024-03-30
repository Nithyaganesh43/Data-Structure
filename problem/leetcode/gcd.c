#include<stdio.h>
int main(){int n,n1,n2,gcd=1;
    scanf("%d%d",&n1,&n2);
    n=(n1>n2)?n2:n1;
    for(int i=1;i<=n;i++){
        if(n1%i==0 && n2%i==0)gcd=i;
    }
    printf("%d",gcd);
}