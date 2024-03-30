#include <stdio.h>

int main(void) {
    int t,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
        int i1=0;
        int i2=0;
        n=0;
	    scanf("%d",&n);
	    int s[n];
	        for(int j=0;j<n;j++){
	            scanf("%d",&s[j]);
	           if(s[j]==1){
	               i1++;
	           }else{
	              i2++;
	          }
            }
            if(i1>i2){
    printf("%d\n",i1);
    }
else{
    printf("%d\n",i2);
}
	    }
}


