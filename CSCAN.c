#include<stdio.h>
#include<stdlib.h>
void main(){
    int i,j,n,size,move, index= -1,temp,initial,RQ[100],TotalHeadMovements=0;
    printf("Enter the no of requests: ");
    scanf("%d",&n);
    printf("Enter request sequence: ");
    for(i=0;i<n;i++){
        scanf("%d",&RQ[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d",&initial);
    printf("Enter the size of the disk: ");
    scanf("%d",&size);
    printf("Enter the head movement position for high 1 and for low 0: ");
    scanf("%d",&move);

    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(RQ[j]>RQ[j+1]){
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

    if(initial == -1){
        index = n;
    }

    //for movement to high side
    if(move == 1){
        for(i=index;i<n;i++){
            TotalHeadMovements += abs(RQ[i]-initial);
            initial = RQ[i];
        }
        TotalHeadMovements += abs(size-1-initial);
        initial = 0;
        TotalHeadMovements += abs(size-1-initial);
        for(i=0;i<index;i++){
            TotalHeadMovements += abs(RQ[i]-initial);
            initial = RQ[i];
        }
    }
    else{
        for(i=index-1;i>=0;i--){
            TotalHeadMovements += abs(RQ[i]-initial);
            initial = RQ[i];
        }
        TotalHeadMovements += abs(initial-0);
        initial = size-1;
        TotalHeadMovements += abs(initial-0);
        for(i=n-1;i>=index;i--){
            TotalHeadMovements += abs(RQ[i]-initial);
            initial = RQ[i];
        }
    }
    printf("Total head movement is : %d",TotalHeadMovements);
}