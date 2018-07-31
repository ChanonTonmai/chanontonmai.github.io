// Program to implement Heap Sort Algorithm avoiding two recursions
// This program is the sample code given an I500/CSCI609 lab of Introduction to Algorithms class
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10 //maximum number of elements

struct TreeNode
{
  int data; //store an element in the tree node
};
//the prototypes of functions we defines
void Max_heapify(struct TreeNode* node, int index, int size);
void buildHeap(struct TreeNode* node);
void print_out(struct TreeNode* node);
void heapSort(struct TreeNode* node);
void swap(struct TreeNode* me, struct TreeNode* you);
int left(int index);
int right(int index);

//Start of main
int main(int argc, char* argv[]) {
  int i, j,d,n;

  //assign a dynamic memory to an array of structs
  struct TreeNode* node = (struct TreeNode*) malloc( MAXSIZE * sizeof(struct TreeNode));

        for (d= 0; d < MAXSIZE; d++)
        {
                node[d].data=0;
        }


    int i =0;
    int j = MAXSIZE;

    printf("Please type %d digitals here, each number a line\n",j);
    for(i =0; i< MAXSIZE; i++) {
        scanf("%d",&node[i].data);
    }
    n=MAXSIZE;



    printf("Before sorting by Heapsort,\n");
    print_out(node);

    heapSort(node); //call Heap sort

    printf("\nAfter sorting by Heapsort,\n");
    print_out(node);

    free(node);

    return 0;
}
// End of main
void heapSort(struct TreeNode* node)
{
  int i, size;

  buildHeap(node);
  size = MAXSIZE;

  for(i = MAXSIZE - 1; i >= 1; i--)
    {
      swap(&node[i], &node[0]); //exchange the largest element into its location at decreasing space in node
      Max_heapify(node, 0, --size); //reinstate the heap property
    }

  return;
}

void swap(struct TreeNode* me, struct TreeNode* you)
{
  int temp;
  temp = (*me).data;
  (*me).data = (*you).data;
  (*you).data = temp;
}


void buildHeap(struct TreeNode* node)
{
  int i;
  for(i = ( MAXSIZE / 2) ; i >= 0; i--)
    Max_heapify(node, i, MAXSIZE);

}

void Max_heapify(struct TreeNode* node, int i, int size)
{
  int l, r, largest;
  l = left(i);
  r = right(i);

  //check if the node 'r' or 'l' is largest or not
  if(l < size && node[l].data > node[i].data)
    largest = l;
  else
    largest = i;

  if(r < size && node[r].data > node[largest].data)
    largest = r;


  if(largest != i)
    {

    }

  return;
}

int left(int index)
{
  return 2 * index + 1; //return each index of the left child
}

int right(int index)
{
  return 2 * index + 2; //return each index of the right child
}


void print_out(struct TreeNode* node)
{
  int i;

  for(i = 0; i < MAXSIZE; i++){
    printf("%d\n", node[i].data);
  }
  printf("\n");

  return;
}
