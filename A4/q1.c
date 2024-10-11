/*

Name:        Evan Rutten
ID:          1189483
Date:        11/27/2022
Assignment:  4.1 Heaps

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int sum_key;    // key (sum of first three integers)
    int key[3];     // integers used to derive key
    int content[7]; // remaining integers
} node;

// function to print 2D array
void print(node array[])
{
    for (int i = 0; i < 20; i++) // row loop
    {
        for (int j = 0; j < 10; j++) // column loop
        {
            if (j < 3)
            {
                // for the first three integers, print the key values
                printf("%02d ", array[i].key[j]);
            }
            else
            {
                // for the remaining integers, print the content values
                printf("%02d ", array[i].content[j - 3]);
            }
        }
        printf("\n");
    }
}

// function to heapify subtree with "index" as the parent
void heapify(node array[], int index)
{
    int smallest = index;        // node to be heapified
    int left = (2 * index) + 1;  // left child
    int right = (2 * index) + 2; // right child

    // if left child is smaller than parent...
    // (ensure left child is in range)
    if (left < 20 && array[left].sum_key < array[smallest].sum_key)
    {
        smallest = left; // update smallest node
    }

    // if right child is smaller than parent...
    // (ensure right child is in range)
    if (right < 20 && array[right].sum_key < array[smallest].sum_key)
    {
        smallest = right; // update smallest node
    }

    // if smallest node is not the parent...
    if (smallest != index)
    {
        // swap parent node and smallest node
        node temp = array[index];
        array[index] = array[smallest];
        array[smallest] = temp;

        // run function recursively until subtree is complete
        heapify(array, smallest);
    }
}

int main()
{
    node nodes[20];

    FILE *f_dat;
    f_dat = fopen("f.dat", "r");

    // convert text file into 2D array:
    int input;
    for (int i = 0; i < 20; i++) // row loop
    {
        for (int j = 0; j < 10; j++) // column loop
        {
            // scan in next integer
            fscanf(f_dat, "%d", &input);

            // place integer in correct index:
            switch (j)
            {
            // first three integers are used for key
            case 0:
                nodes[i].key[0] = input;
                break;
            case 1:
                nodes[i].key[1] = input;
                break;
            case 2:
                nodes[i].key[2] = input;
                break;
            // remaining integers are used for content
            case 3:
                nodes[i].content[0] = input;
                break;
            case 4:
                nodes[i].content[1] = input;
                break;
            case 5:
                nodes[i].content[2] = input;
                break;
            case 6:
                nodes[i].content[3] = input;
                break;
            case 7:
                nodes[i].content[4] = input;
                break;
            case 8:
                nodes[i].content[5] = input;
                break;
            case 9:
                nodes[i].content[6] = input;
                break;
            }
        }

        // calculate sum for key once node is complete
        nodes[i].sum_key = nodes[i].key[0] + nodes[i].key[1] + nodes[i].key[2];
    }

    printf("\nBEFORE:\n\n");
    print(nodes);

    // apply downheap algorithm
    for (int i = 20; i >= 0; i--)
    {
        heapify(nodes, i);
    }

    printf("\nAFTER:\n\n");
    print(nodes);

    printf("\n");
    fclose(f_dat);
    return 0;
}