/**
 * file: prim.c
 * author: yusuf shakeel
 * date: 2014-03-02
 *
 * description: find MST using prim's algorithm
 *
 * vertices are represented using numbers.
 * vertex A becomes 0
 * vertex B becomes 1
 * and so on...
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * contant to represent infinity
 * it is assumed that edges of the graph will have weight less than this value
 */
#define INF 9999

/**
 * total number of vertices in the graph
 */
#define V 4

/**
 * this function will display the MST
 */
void displayMST(int graph[V][V], int markedCell[V][V]) {


}

/**
 * prim&aposs algorithm function
 */
void prim(int A[V][V]) {



	displayMST(A, markedCell);

}

/**
 * this is the main function
 */
int main(void) {

	int A[V][V] = {
		{0, 5, 10, INF},
		{5, 0, 4, 11},
		{10, 4, 0, 5},
		{INF, 11, 5, 0}
	};

	/**
	 * find MST using prim
	 */
	prim(A);

	return 0;
}
