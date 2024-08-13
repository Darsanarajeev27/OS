#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    int size;
    int id;
    struct Block *next;
} Block;

typedef struct Process {
    int size;
    int id;
    struct Process *next;
} Process;

Block *createBlock(int size, int id) {
    Block *newBlock = (Block *)malloc(sizeof(Block));
    newBlock->size = size;
    newBlock->id = id;
    newBlock->next = NULL;
    return newBlock;
}

Process *createProcess(int size, int id) {
    Process *newProcess = (Process *)malloc(sizeof(Process));
    newProcess->size = size;
    newProcess->id = id;
    newProcess->next = NULL;
    return newProcess;
}

void firstFit(Block *blocks, Process *processes) {
    Block *currentBlock;
    Process *currentProcess = processes;

    printf("First Fit Allocation:\n");
    printf("Process ID\tBlock ID\n");

    while (currentProcess) {
        currentBlock = blocks;
        while (currentBlock) {
            if (currentBlock->size >= currentProcess->size) {
                printf("%d\t\t%d\n", currentProcess->id, currentBlock->id);
                currentBlock->size -= currentProcess->size;
                break;
            }
            currentBlock = currentBlock->next;
        }
        if (!currentBlock) {
            printf("%d\t\tNot Allocated\n", currentProcess->id);
        }
        currentProcess = currentProcess->next;
    }
}

void bestFit(Block *blocks, Process *processes) {
    Block *currentBlock, *bestBlock;
    Process *currentProcess = processes;

    printf("Best Fit Allocation:\n");
    printf("Process ID\tBlock ID\n");

    while (currentProcess) {
        bestBlock = NULL;
        currentBlock = blocks;
        while (currentBlock) {
            if (currentBlock->size >= currentProcess->size) {
                if (!bestBlock || currentBlock->size < bestBlock->size) {
                    bestBlock = currentBlock;
                }
            }
            currentBlock = currentBlock->next;
        }
        if (bestBlock) {
            printf("%d\t\t%d\n", currentProcess->id, bestBlock->id);
            bestBlock->size -= currentProcess->size;
        } else {
            printf("%d\t\tNot Allocated\n", currentProcess->id);
        }
        currentProcess = currentProcess->next;
    }
}

void worstFit(Block *blocks, Process *processes) {
    Block *currentBlock, *worstBlock;
    Process *currentProcess = processes;

    printf("Worst Fit Allocation:\n");
    printf("Process ID\tBlock ID\n");

    while (currentProcess) {
        worstBlock = NULL;
        currentBlock = blocks;
        while (currentBlock) {
            if (currentBlock->size >= currentProcess->size) {
                if (!worstBlock || currentBlock->size > worstBlock->size) {
                    worstBlock = currentBlock;
                }
            }
            currentBlock = currentBlock->next;
        }
        if (worstBlock) {
            printf("%d\t\t%d\n", currentProcess->id, worstBlock->id);
            worstBlock->size -= currentProcess->size;
        } else {
            printf("%d\t\tNot Allocated\n", currentProcess->id);
        }
        currentProcess = currentProcess->next;
    }
}

int main() {
    Block *blocks = createBlock(100, 1);
    blocks->next = createBlock(200, 2);
    blocks->next->next = createBlock(300, 3);
    blocks->next->next->next = createBlock(400, 4);
    blocks->next->next->next->next = createBlock(500, 5);

    Process *processes = createProcess(210, 1);
    processes->next = createProcess(100, 2);
    processes->next->next = createProcess(75, 3);
    processes->next->next->next = createProcess(125, 4);
    processes->next->next->next->next = createProcess(300, 5);

    firstFit(blocks, processes);

    // Reset blocks for next allocation strategy
    blocks = createBlock(100, 1);
    blocks->next = createBlock(200, 2);
    blocks->next->next = createBlock(300, 3);
    blocks->next->next->next = createBlock(400, 4);
    blocks->next->next->next->next = createBlock(500, 5);

    bestFit(blocks, processes);

    // Reset blocks for next allocation strategy
    blocks = createBlock(100, 1);
    blocks->next = createBlock(200, 2);
    blocks->next->next = createBlock(300, 3);
    blocks->next->next->next = createBlock(400, 4);
    blocks->next->next->next->next = createBlock(500, 5);

    worstFit(blocks, processes);

    return 0;
}

