#include<stdio.h>
#include<stdlib.h>

int main() {
    int i,n,initial,RQ[100],TotalHeadMovement=0;
    
    printf("Enter no of requests: ");
    scanf("%d",&n);
    printf("Enter the request sequence: ");
    for(i=0;i<n;i++)
        scanf("%d",&RQ[i]);
    printf("Enter the initial request: ");
    scanf("%d",&initial);
    
    for(i=0;i<n;i++){
        TotalHeadMovement = TotalHeadMovement + abs(RQ[i]-initial);
        initial = RQ[i];
    }
    
    printf("The Total head movement is: %d",TotalHeadMovement);
    return 0;
}
