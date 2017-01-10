#include <iostream>
#include <conio.h>
#include<stdio.h>
#include<stdlib.h>

/* Prototype */
int ShowMainMenu();
int ShowInsertionSubMenu();
int ShowInsertionSub1Menu();
int ShowDeletionSubMenu();
int ShowDeletionSub1Menu();


/*
 * Node Declaration
 */
struct node
{
    int info;
    struct node *next;
}*start;

/*
 * Class Declaration
 */
class Link_List
{
    public:
        node* create_node(int);
        void insert_begin();
        void insert_pos();
        void insert_last();
        void delete_pos();
        void sort();
        void reverse();
        void display();
        Link_List()
        {
            start = NULL;
        }
};


int main()
{
	int choice, nodes, element, position, i;
   int
      nChoice = 0;

   do
   {
      nChoice = ShowMainMenu ();
      switch (nChoice)
      {
         case 1:
         {
            ShowInsertionSubMenu ();
         }
         break;

         case 2:
         {
            ShowDeletionSubMenu ();
         }
         break;

         case 3:
         {
         	Link_List s1;
         	s1.display();
         }
         case 4:{
         	Link_List s1;
         	s1.sort();
         	
			break;
		 }
         case 5:{
         	Link_List s1;
         	s1.reverse();
			break;
		 }
         case 6:
         	printf("Bye Bye \n\n");
         break;
      }
   }
   while (nChoice != 4);
   system ("Pause");
   return 0;
   
}

/* ************************************************** ******************* */

int ShowMainMenu ()
{
   int
      nSelected = 0;

   do
   {
	  printf(" DEVELOPER|NAUMAN SABIR|www.naumansabir.com\n\n");
	  printf(" +=======================================+ \n");
	  printf(" |........LINK LIST IMPLEMENTATION.......|\n");
      printf(" +---------------------------------------+\n");
      printf (" | You Can Choose Following Function     |\n");
      printf(" +---------------------------------------+\n\n\n");

      printf (" | (1) FOR INSERTION INTO LINK LIST\n | (2) FOR DELETION FROM LINK LIST\n | (3) TO VIEW LINK LIST\n | (4) Sort Link List | (5) Reverse Link List \n | (6) Exit\n");

      printf ("Enter a number that corresponds to your choice >: ");
      scanf ("%d", &nSelected);
      printf("\n");

      if (( nSelected < 1 ) || ( nSelected > 4))
      {
         printf("You have entered an invalid choice. Please try again\n\n\n");
      }
   }
   while (( nSelected < 1) || ( nSelected > 4));

   return nSelected;
}

/* ************************************************** ************************** */
int ShowInsertionSubMenu ()
{
   int
      nChoice = 0;
   do
   {
      nChoice = ShowInsertionSub1Menu();
      switch (nChoice)
      {

         case 1:
         {
			printf("Inserting Node at Beginning: \n");
			Link_List s1;
            s1.insert_begin();
			printf("\n");
         }
         break;

         case 2:
         {
            printf("Inserting Node at Last: \n");
            Link_List s1;
            s1.insert_last();
            printf("\n");
         }
         break;

         case 3:
         {
            printf("Inserting Node at a given position: \n");
            Link_List s1;
            s1.insert_pos();
            printf("\n");
         }
         break;

         case 4:
         {
            printf ("Going Back....\n\n");
         }
         break;
      }
   }
   while (nChoice != 4);

   return nChoice;
}

/* ************************************************** ******************* */
int ShowInsertionSub1Menu()
{
   int
      nSelected = 0;

   do
   {

      printf ("| (1) For insert Node at start\n| (2) For insert Node at End\n| (3) For insert node at Particular Position\n| (4) GO Back\n\n");

      printf ("Enter a number that corresponds to your choice > ");
      scanf ("%d", &nSelected);
      printf("\n");

      if (( nSelected < 1 ) || ( nSelected > 4))
      {
         printf("You have entered an invalid choice. Please try again\n\n\n");
      }
   }
   while (( nSelected < 1) || ( nSelected > 4));

   return nSelected;
}

/* ************************************************** ************************** */
int ShowDeletionSubMenu ()
{
   int
      nChoice = 0;

   do
   {
      nChoice = ShowDeletionSub1Menu ();
      switch (nChoice)
      {
         case 1:
         {
         	printf("This function is having issue why don't you try to Delete from Particular Position\n");
         	Link_List s1;
            s1.delete_pos();
         }
         break;

         case 2:
         {
         	printf("This function is having issue why don't you try to Delete from Particular Position\n");
         	Link_List s1;
            s1.delete_pos();
         }
         break;

         case 3:
         {
         	Link_List s1;
			s1.delete_pos();
         }
         break;

         case 4:
         {
            printf ("Bye Bye\n\n");
         }
         break;
      }
   }
   while (nChoice != 4);

   return nChoice;
}

/* ************************************************** ******************* */
int ShowDeletionSub1Menu ()
{
   int
      nSelected = 0;

   do
   {

      printf ("| (1) For Deletion From Start \n| (2) For Deletion From End \n| (3) For Deletion From Particular Position\n| (4) GO Back\n\n");

      printf ("Enter a number that corresponds to your choice > ");
      scanf ("%d", &nSelected);
      printf("\n");

      if (( nSelected < 1 ) || ( nSelected > 4))
      {
         printf("You have entered an invalid choice. Please try again\n\n\n");
      }
   }
   while (( nSelected < 1) || ( nSelected > 4));

   return nSelected;
}

/*
 * Creating Node
 */
node *Link_List::create_node(int value)
{
    struct node *temp, *s;
    temp = new(struct node);
    if (temp == NULL)
    {
        printf("Memory not allocated ..");
        return 0;
    }
    else
    {
        temp->info = value;
        temp->next = NULL;
        return temp;
    }
}

/*
 * Inserting Node at Start
 */
void Link_List::insert_begin()
{
    int value;
    printf("Enter the value to be inserted >: ");
    scanf("%d",value);
    struct node *temp, *p;
    temp = create_node(value);
    if (start == NULL)
    {
        start = temp;
        start->next = NULL;
    }
    else
    {
        p = start;
        start = temp;
        start->next = p;
    }
    printf("Element Inserted at beginning");
}

/*
 * Inserting Node at last
 */
void Link_List::insert_last()
{
    int value;
    printf("Enter the value to be inserted: ");
    scanf("%d",value);
    struct node *temp, *s;
    temp = create_node(value);
    s = start;
    while (s->next != NULL)
    {
        s = s->next;
    }
    temp->next = NULL;
    s->next = temp;
    printf("Element Inserted at last");
}

/*
 * Inserting Node at a given position
 */
void Link_List::insert_pos()
{
    int value, pos, counter = 0;
    printf("Enter the value to be inserted: ");
    scanf("%d",value);
    struct node *temp, *s, *ptr;
    temp = create_node(value);
    printf("Enter the postion at which node to be inserted: ");
    scanf("%d",pos);
    int i;
    s = start;
    while (s != NULL)
    {
        s = s->next;
        counter++;
    }
    if (pos == 1)
    {
        if (start == NULL)
        {
            start = temp;
            start->next = NULL;
        }
        else
        {
            ptr = start;
            start = temp;
            start->next = ptr;
        }
    }
    else if (pos > 1  && pos <= counter)
    {
        s = start;
        for (i = 1; i < pos; i++)
        {
            ptr = s;
            s = s->next;
        }
        ptr->next = temp;
        temp->next = s;
    }
    else
    {
        printf("Positon out of range");
    }
}

/*
 * Sorting Link List
 */
void Link_List::sort()
{
    struct node *ptr, *s;
    int value;
    if (start == NULL)
    {
        printf("The List is empty\n");
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        for (s = ptr->next;s !=NULL;s = s->next)
        {
            if (ptr->info > s->info)
            {
                value = ptr->info;
                ptr->info = s->info;
                s->info = value;
            }
        }
        ptr = ptr->next;
    }
}

/*
 * Delete element at a given position
 */
void Link_List::delete_pos()
{
    int pos, i, counter = 0;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Enter the position of value to be deleted: ");
    scanf("%d",pos);
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start = s->next;
    }
    else
    {
        while (s != NULL)
        {
            s = s->next;
            counter++;
        }
        if (pos > 0 && pos <= counter)
        {
            s = start;
            for (i = 1;i < pos;i++)
            {
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;
        }
        else
        {
            printf("Position out of range");
        }
        free(s);
        printf("Element Deleted");
    }
}




/*
 * Reverse Link List
 */
void Link_List::reverse()
{
    struct node *ptr1, *ptr2, *ptr3;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (start->next == NULL)
    {
        return;
    }
    ptr1 = start;
    ptr2 = ptr1->next;
    ptr3 = ptr2->next;
    ptr1->next = NULL;
    ptr2->next = ptr1;
    while (ptr3 != NULL)
    {
        ptr1 = ptr2;
        ptr2 = ptr3;
        ptr3 = ptr3->next;
        ptr2->next = ptr1;
    }
    start = ptr2;
}

/*
 * Display Elements of a link list
 */
void Link_List::display()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("The List is Empty\n");
        return;
    }
    temp = start;
    printf("Elements of list are: ");
    while (temp != NULL)
    {
        printf("_->",temp->info);
        temp = temp->next;
    }
    printf("NULL");
}
