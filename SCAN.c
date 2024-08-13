#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,j,n,RQ[100],initial,move,size,index,TotalHeadMovement=0;
    printf("Enter the number of requests: ");
    scanf("%d",&n);
    printf("Enter the request sequence: ");
    for(i=0;i<n;i++)
        scanf("%d",&RQ[i]);
    printf("Enter the initial head position: ");
    scanf("%d",& initial);
    printf("Enter the total disk size: ");
    scanf("%d",&size);
    printf("Enter the head movement direction 1 for high and 0 for low: ");
    scanf("%d",&move);
    //sorting 
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(RQ[j]>RQ[j+1]){
                int temp;
                temp = RQ[j];
                RQ[j] = RQ[j+1];
                RQ[j+1] = temp;
            }
        }
    }     
    for(i=0;i<n;i++){
        if(initial<RQ[i]){
            index = i;
            break;
        }
    }
    //if movement is towards high value
    if(move ==1){
        for(i=index;i<n;i++){
            TotalHeadMovement = TotalHeadMovement + abs(RQ[i]-initial);
            initial = RQ[i];
        }
        //last movement for max size
        TotalHeadMovement = TotalHeadMovement + abs(size-RQ[i-1]-1);
        initial = size-1;
        for(i=index-1;i>=0;i--){
            TotalHeadMovement = TotalHeadMovement + abs(RQ[i]-initial);
            initial = RQ[i];
        }
    }
    //if movement is towards low value
    else{
        for(i=index-1;i>=0;i--){
            TotalHeadMovement = TotalHeadMovement + abs(RQ[i]-initial);
            initial = RQ[i];
        }
        //last movement for min size
        TotalHeadMovement = TotalHeadMovement + abs(RQ[i+1]-0);
        initial = 0;
        for(i=index;i<n;i++){
            TotalHeadMovement = TotalHeadMovement + abs(RQ[i]-initial);
            initial = RQ[i];
        }
    }    
    printf("Total head movement is: %d",TotalHeadMovement);
    return 0;
}
