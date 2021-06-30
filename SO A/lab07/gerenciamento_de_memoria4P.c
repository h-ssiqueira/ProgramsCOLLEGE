#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 4096


int memory[max];

// Allocate a partition of memory
int *mallocMem(unsigned size){ // Return the pointer to allocated memory partition
	int *i = memory, *previousNode, j;
	do{
		if(*i == -1){
			previousNode = i;
			i += 2;
			if(*i >= size){ // Found a free region
				for(i = memory + *(i-1), j = size; j > 0; i++, j--){
					if(i >= memory + max) // If the pointer bypass the memory region
						return NULL;
					*i = 2; // Allocated region receives 2
				}
				if(*(previousNode + 2) > size+4 && (!(i + 4 >= memory + max) || (!(i + 4 >= *(previousNode + 3) + memory) && *(previousNode + 3) != 0))){ // If the region is bigger than the size and has space for a new region
					*i = -1; // Set the new region as free
					*(i+1) = *(previousNode + 1) + size + 4; // Set the initial position of new region
					*(i+2) = *(previousNode + 2) - (size + 4); // Set the remaining size of memory
					*(i+3) = *(previousNode + 3); // Next node of linked list is the next from previous node
					*previousNode = 1; // Set the previous region as allocated
					*(previousNode+2) = size; // Update the size of region
					*(previousNode+3) = *(previousNode + 1) + size; // Set the position of next node
					return previousNode + 4;
				}
				else if(i + 4 >= memory + max || size == *(previousNode + 2) || (i + 4 >= *(previousNode + 3) + memory && *(previousNode +3) != 0)){ // If the partition has the same size as required or the remaining region is less than 5, won't be possible to create a new region, then the allocated region is the same indicated in node (internal fragmentation)
					*previousNode = 1;
					return previousNode + 4;
				}
			}
			else
				i++;
		}
		else
			i += 3;
		i = memory + *i;
	}while(i != memory);
	return NULL;
}

// Free memory in a specific partition
void freeMem(int *ptr, unsigned size){ // Free memory, where *ptr is a pointer to allocated partition
	if(!ptr)
		return;
	int *i = memory, *previous = NULL, *next,j;
	do{
		i++;
		if(memory + *i != ptr){ // Check if the pointer is not in the partition
			previous = i - 1;
			i = memory + *(i+2);
		}
		else{
			for(next = ptr, j = 0; j < size; next++,j++) // Zero all positions
				*next = 0;
			*(i-1) = -1; // Set the partition as free
			// previous - i - next
			if(previous && next < memory + max && *previous == -1 && *next == -1){ // Both adjacent
				*(previous+2) += *(i+1) + *(next+2) + 8;
				*(previous+3) = *(next+3);
				*(i-1) = *(i) = *(i+1) = *(i+2) = *next = *(next+1) = *(next+2) = *(next+3) = 0;
			}
			else if(next < memory + max && *next == -1){ // Free partition on right
				*(i+1) += *(next+2) + 4;
				*(i+2) = *(next+3);
				*next = *(next+1) = *(next+2) = *(next+3) = 0;
			}
			else if(previous && *previous == -1){ // Free partition on left
				*(previous+2) += *(i+1) + 4;
				*(previous+3) = *(i+2);
				*(i-1) = *(i) = *(i+1) = *(i+2) = 0;
			}
			return;
		}
	}while(i != memory);
}

// Return the size of free memory
int getFreeMem(){ // Return the total of free bytes
	int *i = memory, sum = 0;
	do{
		if(*i == -1){ // If the node indicates that partition is free
			i += 2;
			sum += *i; // To increment the total number of free spaces
			i++;
		}
		else
			i += 3;
		i = memory + *i;
	}while(i != memory);
	return sum;
}

// Print all allocated partitions with the size of each one
void printAllocated(){
	int *i = memory;
	do{
		if(*i == 1) // If the node indicates that next partition is allocated
			printf("Partition %d (%d positions)\n", *(i+1), *(i+2));
		i = memory + *(i+3);
	}while(i != memory);
}

// Display all positions of memory
void showMem(){
	int *i;
	for(i = memory; i < (memory + max); i++)
		printf("%d ", *i);
}

// Get the position of the node in memory
int *getPos(int addr, int *size){
	int *i = memory;
	do{
		if(*(i+1) + memory == addr + memory){ // Check if the input address is the beggining of the partition
			*size = *(i+2);
			return addr + memory;
		}
		i = memory + *(i+3);
	}while(i != memory);
	*size = 0;
	return NULL;
}

int main(){
	int op = 1, *i, *ptr = NULL, addr;
	unsigned size = 0;
	bool done = true;

	*memory = -1; // First node of linked list indicating that the whole memory is free
	*(memory + 1) = 4;
	*(memory + 2) = max - 4;
	for(i = (memory + 3); i < (memory + max); i++)
		*i ^= *i; // Zero all positions of memory

	do{
		printf("\n\nThere are %d free positions in memory.\n\n0 - Exit.\n1 - Allocate memory.\n2 - Free memory.\n3 - Print memory.\n-> ", getFreeMem());
		scanf("%d", &op);

		switch(op){
			case 1:
				if(getFreeMem() == 0){
					printf("\n\nMemory full!\n\n");
					break;
				}
				do{
					printf("\nSelect the size of memory which will be allocated:\n-> ");
					scanf("%d", &size);
					if(size < 1 || size > getFreeMem())
						printf("\n\nPlease select a size between 1 and %d.\n\n", getFreeMem());
				}while(size < 1 || size > getFreeMem());
				// Allocate and create the node for linked list if necessary
				ptr = mallocMem(size);
				ptr ? printf("\n\nMemory allocated with success in address %ld.\n\n", (ptr - memory)) : printf("\n\nFailed to allocate memory (out of memory).\n\n");
				break;
			case 2:
				// Print the linked list and let the user choose the partition to liberate
				if(getFreeMem() == max - 4){
					printf("\n\nNo partitions allocated.\n\n");
					break;
				}
				do{
					printf("Choose the address of partition to be freed:\n");
					printAllocated();
					printf("\n-> ");
					scanf("%d", &addr);
					if(addr < 1 || addr > max)
						printf("\n\nPlease insert a valid partition.\n\n");
				}while(addr < 1 || addr > max);
				ptr = getPos(addr,&size);
				freeMem(ptr,size);
				ptr ? printf("\n\nMemory freed with success.\n\n") : printf("\n\nFailed to free memory (address error).\n\n");
				break;
			case 3:
				printf("\n\n\n");
				showMem();
				printf("\n\n\n");
				break;
		}
	}while(op != 0);
	return 0;
}