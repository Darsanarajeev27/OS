#include<stdio.h>
void main(){
    int bsize[20],psize[20];
    int all[20],m,n,i,j;
    printf("\n\t\tMemory management scheme-Best Fit");
    
    printf("\nEnter no. of blocks: ");
    scanf("%d",&m);
    printf("\nEnter no. of processes: ");
    scanf("%d",&n);
    printf("Enter the size of the blocks:\n");
    for(i=0;i<m;i++){
        printf("\nBlock size of B%d: ",i+1);
        scanf("%d",&bsize[i]);
    }
    printf("Enter the size of the processes:\n");
    for(i=0;i<n;i++){
        printf("\nBlock size of P%d: ",i+1);
        scanf("%d",&psize[i]);
        all[i]=-1;
    }
    
    for(i=0;i<n;i++){
        int workspace = -1;
        for(j=0;j<m;j++){
            if(bsize[j]>=psize[i]){
                if(workspace==-1){
                    workspace = j;
                }
                else if(bsize[workspace]<bsize[j])
                    workspace = j;
            }
        }
        if(workspace!=-1){
            all[i]=workspace;
            bsize[workspace]-=psize[i];
        }
    }
    printf("\nProcess no\tProcess size\tBlock no\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t",i+1,psize[i]);
        if(all[i]!=-1)
            printf("%d\n",all[i]+1);
        else
            printf("Not allocated");
    }
}    