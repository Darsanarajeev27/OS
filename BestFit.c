#include<stdio.h>

int main(){
    int i, j, bno, pno, b[20], p[20], fragment[20], temp, lowest=9999;
    static int parray[20], barray[20] = {0}; // Initialize barray to 0

    printf("Enter the number of blocks: ");
    scanf("%d", &bno);
    printf("Enter the block sizes with a space gap: ");
    for(i=0; i<bno; i++){
        scanf("%d", &b[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &pno);
    printf("Enter the sizes of processes with a space gap: ");
    for(i=0; i<pno; i++){
        scanf("%d", &p[i]);
    }

    for(i=0; i<pno; i++){
        lowest = 9999; // Reset lowest for each process
        for(j=0; j<bno; j++){
            if(barray[j] == 0){ // Block is free
                temp = b[j] - p[i];
                if(temp >= 0 && temp < lowest){
                    parray[i] = j;
                    lowest = temp;
                }
            }
        }
        if(lowest == 9999){
            // No suitable block found
            parray[i] = -1;
            fragment[i] = -1;
        } else {
            fragment[i] = lowest;
            barray[parray[i]] = 1; // Mark block as allocated
        }
    }    

    printf("\n\nProcess No\tProcess Size\tBlock No\tBlock Size\tFragment\n");
    for(i=0; i<pno; i++){
        if(parray[i] != -1){
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, p[i], parray[i]+1, b[parray[i]], fragment[i]);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\n", i+1, p[i]);
        }
    }

    return 0;
}
