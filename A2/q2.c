/*

Name:        Evan Rutten
ID:          1189483
Date:        10/15/2022
Assignment:  2.2 Stacks

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Char_Node_
{
    char character;
    float number;
    struct _Char_Node_ *next;
} Node;

// generate new node
Node *createNode(char character, float number)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->character = character;
    new->number = number;
    new->next = NULL;
    return new;
}

// add node to top of stack
void pushToStack(Node **head, char character, float number)
{
    Node *node = createNode(character, number);
    node->next = *head;
    *head = node;
}

// remove node from top of stack
Node *popFromStack(Node **head)
{
    Node *node = *head;
    *head = (*head)->next;
    return node;
}

int main(int argc, char *argv[])
{
    // ensure proper number of arguments
    if (argc == 2)
    {
        // create separate stacks for input and output
        Node *input = (Node *)malloc(sizeof(Node));
        Node *result = (Node *)malloc(sizeof(Node));
        // fill input stack with argument
        for (int i = strlen(argv[1]); i > -1; i--)
        {
            pushToStack(&input, argv[1][i], 0);
        }
        // create values for use in arithmetic
        float num_1;
        float num_2;
        // read through input stack
        Node *current = input;
        while (current->next->next != NULL)
        {
            // if node is operand, push it to the output stack
            if (current->character >= '0' && current->character <= '9')
            {
                pushToStack(&result, '\0', (float)(current->character - 48));
            }
            // if node is operator...
            else
            {
                // pop two values
                num_1 = popFromStack(&result)->number;
                num_2 = popFromStack(&result)->number;
                // determine specific operator and perform operation
                switch (current->character)
                {
                // addition
                case '+':
                    pushToStack(&result, '\0', num_2 + num_1);
                    break;
                // subtraction
                case '-':
                    pushToStack(&result, '\0', num_2 - num_1);
                    break;
                // multiplication
                case '*':
                    pushToStack(&result, '\0', num_2 * num_1);
                    break;
                // division
                case '/':
                    pushToStack(&result, '\0', num_2 / num_1);
                    break;
                }
            }
            current = current->next;
        }
        // print result
        printf("Input: %s\n", argv[1]);
        printf("Output: %0.2f\n\n", result->number);
        printf("[Press any key to quit]\n");
        getchar();
    }
    // cases for wrong number of arguments
    else if (argc > 2)
    {
        printf("Too many arguments\n");
    }
    else
    {
        printf("One argument expected\n");
    }
    return 0;
}