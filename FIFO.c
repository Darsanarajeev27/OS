#include<stdio.h>
void main(){
    int i,j,k,count =0,f,pf=0,rs[25],m[10],n;
    printf("Enter length of reference string: ");
    scanf("%d",&n);
    printf("Enter the reference sequence: ");
    for(i=0;i<n;i++)
        scanf("%d",&rs[i]);
    printf("Enter no of frames: ");
    scanf("%d",&f);
    for(i=0;i<f;i++)
        m[i]=-1;
    printf("Page replacement process is:\n");
    for(i=0;i<n;i++){
        for(k=0;k<f;k++){
            if(m[k]==rs[i]){
                break;
            }
        }
        if(k==f){
            m[count++]=rs[i];
            pf++;
        }
        for(j=0;j<f;j++)
            printf("\t%d",m[j]);
        if(k==f)
            printf("\tPF No. %d",pf);
        //else
            //printf("\n");
        printf("\n");
        if(count==f)
            count=0;
            
    }
    printf("No.of page faults using FIFO are : %d",pf);
}