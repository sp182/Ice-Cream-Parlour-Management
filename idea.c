#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 5
int push(char stack[max][80], int *top, char data[80]) //This function pushes the item (flavour) to stack (ice-cream) 
{
 if (*top == max - 1)
 return (-1);
 else
 {
 *top = *top + 1;
 strcpy(stack[*top], data);
 return (1);
 }
}
int pop(char stack[max][80], int *top, char data[80]) //This function removes the topmost item (flavour) from the stack (ice cream) 
{
 if (*top == -1)
 return (-1);
 else
 {
 strcpy(data, stack[*top]);
 *top = *top - 1;
 return (1);
 }
}
void display(char stack[max][80], int *top, char data[80]) //Displays the whole stack (ice cream)
{
 int i;
 for (i = *top; i >= 0; i--)
 {
 printf("The flavour in your ice-cream is: %s\n", stack[i]);
 }
 if (*top == -1)
 {
 printf("Stack is empty");
 }
}
int insq(char queue[max][80], int *rear, char data[80]) //Enqueues the name of the customer
{
 if (*rear == max - 1)
 return (-1);
 else
 {
 
 *rear = *rear + 1;
 strcpy(queue[*rear], data);
 return (1);
 }
}
int delq(char queue[max][80], int *front, int *rear, char data[80]) 
//Dequeues the name of the customer
{
 if (*front == *rear)
 return (-1);
 else
 {
 (*front)++;
 strcpy(data, queue[*front]);
 //printf("Element deleted from queue is : %s\n", queue[*front]);
 return (1);
 }
}
int main() //Main function 
{
 char queue[max][80], data[80];
 int front, rear, reply;
 int ch;
 char stack[max][80], nm[80];
 int top, chst, replyst;
 top = -1; // Initialize Stack
 front = rear = -1; //... Initialize a Queue
 printf("-------------------------------------------\n");
 printf("\t Welcome to \n\t 'Scoops n Smiles' \n\t Ice-cream Parlour");
 printf("\n-------------------------------------------\n");
 printf("\n 1. Write your name to stand in a Queue");
 printf("\n 2. Delete your name from a Queue if you don't want icecream");
 printf("\n 3. Choose your ice cream flavour");
 printf("\n 4. Good-bye");
 printf("\n------------------------------\n");
 while (1)
 
 {
 printf("Choose operation : ");
 scanf("%d", &ch);
 switch (ch)
 {
 case 1: // insert
 {
 printf("\nEnter your name : ");
 scanf("%s", data);
 reply = insq(queue, &rear, data);
 if (reply == -1)
 printf("\nQueue is Full \n");
 else
 printf("\n'%s' is standing in queue.\n\n", data);
 break;
 }
 case 2: // delete
 {
 reply = delq(queue, &front, &rear, data);
 if (reply == -1)
 printf("\nQueue is Empty \n");
 else
 printf("\nDeleted customer name from Queue is : %s\n", 
data);
 printf("\n");
 break;
 }
 case 3: //stack code
 {
 printf("\n");
 printf("\n----------------------------\n");
printf("\tMENU CARD");
 printf("\n----------------------------\n");
 printf("\n Make your own ice-cream here by choosing the below options.... :)\n");
 printf("\n");
 printf(" 1. Enter your flavour (Push)\n");
 printf(" 2. Remove your flavour (Pop)\n");
 printf(" 3. Here is your ice-cream\n");
 
 printf(" 4. Make your payment\n");
 printf("----------------------------\n");
 while (1)
 {
 printf("Choose operation from the above MENU CARD : ");
 scanf("%d", &chst);
 switch (chst)
 {
 case 1: // push
 printf("\nEnter the flavour : ");
 scanf("%s", nm);
 reply = push(stack, &top, nm);
 if (replyst == -1)
 printf("\n You can't add more flavours to the ice-cream (Stack is Full).\n");
 else
 printf("'%s' flavour has been added to your ice-cream (Pushed in Stack).\n\n", nm);
 break;
 case 2: // pop
 reply = pop(stack, &top, nm);
 if (replyst == -1)
 printf("\n No flavours has been added to the ice-cream (Stack is Empty) \n");
 else
 printf("Removed (Popped) flavour of the ice-cream is : %s\n", nm);
 printf("\n");
 break;
 case 3: //display
 display(stack, &top, nm);
 break;
 case 4:
 printf("Kindly make your payment...Hope you enjoyed the ice-cream, please visit us again!!!:)");
 exit(0);
 default:
 printf("Invalid operation \n");
 }
 
 }
 break;
 }
 case4:
 printf("Good-bye!!! :)");
 exit(0);
 default:
 printf("Invalid operation \n");
 }
 }
 return 0;
}