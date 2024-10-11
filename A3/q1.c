/*

Name:        Evan Rutten
ID:          1189483
Date:        10/31/2022
Assignment:  3.1 Binary Expression Tree

*/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// multi-purpose node (tree and stack)
typedef struct _node_
{
    char data[10];
    // tree nodes:
    struct _node_ *left;
    struct _node_ *right;
    // stack node:
    struct _node_ *next;
} node;

// create new node
node *createNode(char data[])
{
    // allocate memory
    node *new = (node *)malloc(sizeof(node));
    // set data
    strcpy(new->data, data);
    // set children
    new->left = NULL;
    new->right = NULL;
    new->next = NULL;

    return new;
}

// push node to top of stack
void push(node **head, node *input)
{
    // if stack is empty, add node as head
    if ((*head) == NULL)
    {
        (*head) = input;
    }
    // if stack has items, replace the head
    else
    {
        input->next = (*head);
        (*head) = input;
    }
}

// pop node from top of stack
node *pop(node **head)
{
    // save head node
    node *output = (*head);
    // replace head
    (*head) = (*head)->next;

    return output;
}

// print tree elements (inorder traversal)
void printTree(node *current)
{
    // if node is empty, end recursive step of function
    if (current == NULL)
    {
        return;
    }
    else
    {
        // print left bracket before traversing left tree
        // also ensure node is not a number/variable
        if (current->left != NULL && current->right != NULL)
        {
            printf("(");
        }

        printTree(current->left);    // run function recursively on left child
        printf("%s", current->data); // print data
        printTree(current->right);   // run function recursively on right child

        // print right bracket before traversing right tree
        // also ensure node is not a number/variable
        if (current->left != NULL && current->right != NULL)
        {
            printf(")");
        }
    }
}

int main(int argc, char *argv[])
{
    // if one argument (other than execution) is present...
    if (argc == 2)
    {
        // print input
        printf("\nInput postorder:\n%s\n", argv[1]);

        // create head node and helper variables
        node *head = NULL;
        node *operand, *operator_A, *operator_B, *temp;
        char input[10];

        // parse input string and add elements to tree
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            // save element string up to space character
            while (argv[1][i] != ' ' && i != strlen(argv[1]))
            {
                strncat(input, &argv[1][i], 1);
                i++;
            }
            // if element is an operand...
            if (strcmp(input, "+") == 0 || strcmp(input, "-") == 0 || strcmp(input, "*") == 0 || strcmp(input, "/") == 0)
            {
                operand = createNode(input); // create parent node
                operator_B = pop(&head);     // pop second operator
                operator_A = pop(&head);     // pop first operator
                operand->left = operator_A;  // add left child (first operator)
                operand->right = operator_B; // add right child (second operator)
                push(&head, operand);        // push parent to stack
            }
            // if element is a number/variable...
            else
            {
                temp = createNode(input); // create new node
                push(&head, temp);        // push it to the stack
            }

            // clear input string
            strcpy(input, "");
        }

        // print output
        printf("\nOutput inorder:\n");
        printTree(operand);

        // wait for input
        printf("\n\nPress any key to quit:\n> ");
        getch();
    }

    // if more than one argument (other than execution) are present...
    else if (argc > 2)
    {
        printf("Too many arguments\n");
    }
    // if no arguments (other than execution) are present...
    else
    {
        printf("One argument expected\n");
    }

    return 0;
}