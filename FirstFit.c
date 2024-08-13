#include<stdio.h>
void main(){
    int bno,pno,bsize[10],psize[10],flags[10],allocation[10],i,j;
    for(i=0;i<10;i++){
        flags[i]=0;
        allocation[i]=-1;
    }
    printf("\nEnter no. of blocks: ");
    scanf("%d",&bno);
    printf("\nEnter size of each block with one space gap: ");
    for(i=0;i<bno;i++)
        scanf("%d",&bsize[i]);
        
    printf("\nEnter no. of processes: ");
    scanf("%d",&pno);
    printf("\nEnter size of each process with one space gap: ");
    for(i=0;i<pno;i++)
        scanf("%d",&psize[i]); 
        
    for(i=0;i<pno;i++){
        for(j=0;j<bno;j++){
            if(bsize[j]>psize[i]){
                allocation[i] = j;
                bsize[j] -= psize[i];
                break;
            }
        }
    }
    printf("\nProcess no.\tProcess size\tBlock number\n");
    for(i=0;i<pno;i++){
        printf("%d\t\t%d\t\t",i+1,psize[i]);
        if(allocation[i]!=-1){
            printf("%d\n",allocation[i]+1);
        }
        else
            printf("No allocation");
    }
}