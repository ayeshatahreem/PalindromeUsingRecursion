// Recursive program to check if a given string is palindrome
//Time Complexity: O(n)
#include <iostream>
#include <stdlib.h>										// for malloc,calloc and free (dynamic memory management)

using namespace std;

struct node												// definition of node
{
    char data;
    node *next;
};

bool findPal(struct node **leftNode, struct  node *rightNode)
{
   if (rightNode == NULL)									// stop recursion if current= NULL 
      {
		  return true;
      }
   bool found = findPal(leftNode, rightNode->next);
   if (found == false)									// If string is not palindrome then return false 
      {
		  return false;
      }
   bool check = (rightNode->data == (*leftNode)->data);		// Check values 
   *leftNode = (*leftNode)->next;								// Move left to next node 
   return check;
}

bool isPalindrome(node *head)
{
   if(findPal(&head, head))
	   return true;
   else 
	   return false;
}

void push(node **head, char data)						//Push a node to linked list. this function changes the head
{
    node *newNode = (node*) malloc(sizeof(node));		// allocate node 
    newNode->data  = data;
    newNode->next = (*head);
    (*head) = newNode;
}

void printString(node *ptr)								//  print the string
{
    while (ptr != NULL)
    {
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
   cout<<"NULL"<<endl;
}

int main()												// Driver program to test above function
{
    node *head = NULL;									// Start with the empty list 
    char str[] = "MADAM";
    for (int i = 0; str[i] != '\0'; i++)
    {
       push(&head, str[i]);
       printString(head);								//Recursively traverse till the end of list. 
	   //When we return from last NULL, we will be at last node. The last node to be compared with first node of list.
       if (isPalindrome(head)) 
	   {
		   cout<<"Is Palindrome\n\n";
	   }
	   else
	   {
           cout<<"Not Palindrome\n\n";
	   }
    }
	system("pause");
    return 0;
}