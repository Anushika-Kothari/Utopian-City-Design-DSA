/**
City Name-"Eutopia"

The city consists of 5 houses,a hospital,a school,a hotel,a Park and a dumping yard.

The corresponding vertices are as follows:
0:HOUSE 1
1:SCHOOL
2:BANK
3:HOTEL
4:HOUSE 4
5:PARK
6:HOUSE 3
7:HOSPITAL
8:HOUSE 5
9:HOUSE 2
10:CINEMA
11:DUMPING YARD

**/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<limits.h>
#include <sys/stat.h>
#include <ctype.h>
#include<stdbool.h>
#include "settings.h"
#include "locals.h"
#define VERTICES 12
#define EDGES 18
#define CITIZENS 20
#define HOUSE_MAX 5
#define HASH_TABLE_SIZE 30
#define S 15

int status,choice;
int hashtable[HASH_TABLE_SIZE];
int visited[12];

//Structure Name:C
//Description:Used to hold the information of the citizens.
struct C
{
char name[20];
char lname[20];
int pin;
int age;
int hno;
char mobileno[10];
int salary;
char profession[20];
}citizen[CITIZENS],temp;

//Structure Name:tree
//Description:Used for binary search implementation.

struct tree
{
    int data;
    struct tree *left,*right;
};


//Structure Name:hospital
//Description:Stores the detaisl of patients.

struct hospital
{
    char name[20];
    char lname[10];
    int age;
    int priority;
    int token;
};
struct hospital patient[10];

//Structure Name:hotel
//Description:Stores details of bill of each customer.
struct hotel
{
    char name[20];
    float check_in;
    float check_out;
    char order[30];
    int cost;
};
struct hotel a[12];

//Structure Name:TREE
//Description:Used in BST implementation
typedef struct tree TREE;
TREE *root;

//Structure Name:house
//Description:Used to hold the house number and total number of people residing in the house.
struct houses
{
int hno;
int total;
}house[HOUSE_MAX];

//Stucture Name:students
//Description:To store student details

struct student
{
    char name[20];
    int age;
    char div;
    int standard;
    int percentage;
};
struct student s[S];

//Structure Name:dump
//Description:Used to store the vertices and the weight of the edges connected by the vertices.
struct dump
{
    int u;
    int v;
    int w;
};
struct dump v[20];

struct node
{
char name[20];
char lname[20];
int pin;
int age;
int hno;
char mobileno[10];
int salary;
char profession[20];
struct node *next;
};

typedef struct node NODE;
NODE* head=NULL;
NODE* newnode=NULL;
NODE* cur=NULL;



//Function:     load
//Description:  loads citizens.txt,adj_matrix.txt,students.txt,warshall.txt,floyd.txt and hospital.txt
//              file from secondary memory to primary.
//Input param:  NULL
//Return Type:  integer
//              success status on successful operation
//              respective error status code otherwise

int load()
{

    // Start the log file
    open_log();

    // Use a file pointer to open various files to load the values
    FILE *fp;

    //Local variables
     int file_status = 0;
    //check whether citizens.txt file is empty or not.
    file_status = file_empty_check("citizens.txt");
    if (file_status == 1006)
        return FAILURE;

    //check whether adj_matrix.txt file is empty or not.
    file_status = file_empty_check("adj_matrix.txt");
    if (file_status == 1006)
        return FAILURE;

    //check whether hospital.txt file is empty or not.
    file_status = file_empty_check("hospital.txt");
    if (file_status == 1006)
        return FAILURE;

    //check whether student.txt file is empty or not
    file_status = file_empty_check("students.txt");
    if (file_status == 1006)
        return FAILURE;

    //check whether hotel.txt file is empty or not
    file_status = file_empty_check("hotel.txt");
    if (file_status == 1006)
        return FAILURE;


    //check whether warshall.txt file is empty or not.
    file_status = file_empty_check("warshall.txt");
    if (file_status == 1006)
        return FAILURE;

    //check whether flyod.txt file is empty or not.
    file_status = file_empty_check("floyd.txt");
    if (file_status == 1006)
        return FAILURE;


    // Open the hotel.txt file to read its contents.
    fp = fopen("hotel.txt","r");
    if(fp == NULL)
        {
        write_log("load", "FILE_OPEN_ERROR", "Unable to open the hotel file");
        return FAILURE;
        }

    write_log("load", "SUCCESS", "hotel.txt read successfully");
    fclose(fp);

    // Open the citizen.txt file to read its contents.
    fp = fopen("citizens.txt","r");
    if(fp == NULL)
        {
        write_log("load", "FILE_OPEN_ERROR", "Unable to open the citizens file");
        return FAILURE;
        }

    write_log("load", "SUCCESS", "Citizens.txt read successfully");
    fclose(fp);

    // Open the Adj.txt file to read its contents.
    fp = fopen("Adj_matrix.txt","r");
    if(fp == NULL)
        {
        write_log("load", "FILE_OPEN_ERROR", "Unable to open the Adj_matrix file");
        return FAILURE;
        }

     write_log("load", "SUCCESS", "Adj_matrix.txt read successfully");
    fclose(fp);

    // Open the warshall.txt file to read its contents.
    fp = fopen("warshall.txt","r");
    if(fp == NULL)
        {
        write_log("load", "FILE_OPEN_ERROR", "Unable to open the warshall file");
        return FAILURE;
        }

    write_log("load", "SUCCESS", "warshall.txt read successfully");
    fclose(fp);

    // Open the hospital.txt file to read its contents.
    fp = fopen("hospital.txt","r");
    if(fp == NULL)
        {
        write_log("load", "FILE_OPEN_ERROR", "Unable to open the hospital file");
        return FAILURE;
        }

    write_log("load", "SUCCESS", "hospital.txt read successfully");
    fclose(fp);

    // Open the floyds.txt file to read its contents.
    fp = fopen("flyods.txt","r");
    if(fp == NULL)
        {
        write_log("load", "FILE_OPEN_ERROR", "Unable to open the floyd file");
        return FAILURE;
        }

    write_log("load", "SUCCESS", "floyds.txt read successfully");
    fclose(fp);


    // Open the students.txt file to read its contents.
    fp = fopen("studenst.txt","r");
    if(fp == NULL)
        {
        write_log("load", "FILE_OPEN_ERROR", "Unable to open the Student.txt file");
        return FAILURE;
        }
}

//Function:     open_log
//Description:  opens the log file to write the success or failure status
//Input param:  NULL
//Return Type:  NULL

void open_log()
{
    FILE *flog;
    // Open the file
    flog = fopen("log.txt", "a+");


    // If unable to open the file, alert the user
    if(flog == NULL)
        printf("Unable to open log file. No log status will be captured.");
    else
        fprintf(flog, "%s", "_________________________START OF ITERATION________________________");

    fprintf(flog, "%s", "\n\n");
}


//Function:     close_log
//Description:  closes the log file if opened
//Input param:  NULL
//Return Type:  NULL

void close_log()
{
    FILE *flog;
    flog = fopen("log.txt", "a+");
    if(flog != NULL) {
        // Add a message to indicate end of a iteration
        fprintf(flog, "%s", "_________________________END OF ITERATION________________________");
        fprintf(flog, "%s", "\n\n");

        // Close the file pointer
        fclose(flog);
    }
}


//Function:     write_log
//Description:  logs the status with success or failure message
//Input param:  function name, status and message to display
//Return Type:  NULL

void write_log(char * function_name, char *status, char * message)
{
    FILE *flog;
    flog=fopen("log.txt","a+");

    // Write the appropriate log message with associated run time
   char mytime = time(NULL);
    fprintf(flog, "%s %s : %s --> %s\n\n", ctime(&mytime), function_name, status, message);

}


//Function:     file_empty_check
//Description:  Check whether file has content or not
//Input param:  name of the file
//Return Type:  integer
//              success state is returned if file has content
//              FILE_EMPTY_ERROR otherwise

int file_empty_check(char *filename)
{
    // Declaring "stat" a system call to know about content of file.
    struct stat filestat;
    stat (filename,&filestat);

    // Variables to hodl messages
    char message_failure[40];
    char message_success[40];

    strcpy(message_failure, filename);
    strcat(message_failure, " is empty");

    strcpy(message_success, filename);
    strcat(message_success, " has content");

    //check size of file and return appropriate status.
    if( filestat.st_size == 0 )
    {
        write_log("file_empty_check","FILE_EMPTY_ERROR",message_failure);
        return FILE_EMPTY_ERROR;
    }
    else
    {
        write_log("file_empty_check","SUCCESS",message_success);
        return SUCCESS;
    }
}


//Function:     get_map()
//Description:  Prints the map of the city
//Input param:  NULL
//Return Type:  NULL

void get_map()
{
    printf("\t\t\t\t\t\t\t\tCITY MAP\n\n\n");
    printf("\t\t\t\t\t\t\t\t Dumping Yard(11)\n");
    printf("     House 1(0)\t\t\t\t\t\t\t\t  \\\n");
    printf("      | \\\t\t\t\t\t\t\t\t   \\\n");
    printf("      |  \\ 2      - - -Hotel(3)\t\t\t\t\t\t    \\ 3\n");
    printf("      |   \\      / 3\t/      \\\t\t\t\t\t     \\\n");
    //printf("\t\t\t\t\t\t\t\t\t\t\t        \\\n");
    printf("      |    \\    /      /        \\ 1\t\t\t\t\t      \\\n");
    //printf("\t\t\t\t\t\t\t\t\t\t\t         \\\n");
    printf("      |     Bank (2)  /          \\\t\t\t\t\t       \\\n");
    printf("      |     |\\       / 3          \\\t\t\t\t\tCinema(10)\n");
    printf("      |     | \\ 2   /            House 3(6)\t\t\t\t /\t|\n");
    printf("      |     |  \\   /             /         \\                            /\t|\n");
    printf("      |     |   \\_|House 4(4)   /           \\                          /\t|\n");
    printf("      |\t    |    /|            /             \\                        / 2\t|\n");
    printf("      |\t    |   / |           /               \\           House 5(8) /\t\t| 9\n");
    printf("    7 |\t  4 |  /  |          /                 \\                    /\\\t\t|\n");
    printf("      |\t    | /   |         /                   \\                  /  \\\t        |\n");
    printf("      |\t    |/    |      2 /                     \\ 5              /    \\\t|\n");
    printf("      |\t    / 4   |       /                       \\              /      \\\t|\n");
    printf("      |\t   /      | 2    /                         \\            /        \\\t|\n");
    printf("      |\t  /       |     /                           \\          / 1        \\\t|\n");
    printf("      |\t /        |    /                             \\        /            \\\t|\n");
    printf("      |\t/         |   /                               \\      /              \\\t|\n");
    printf("      |/           |  /                                 \\    /                \\\t|\n");
    printf("      |            | /                                   \\  /                  \\\t|\n");
    //printf("      |\t\t  |/                                     \\/                    \\\|\n");
    printf(" School(1)- - - -Park(5)- - - - - - - - - - - - - - Hospital (7)              House 2(9)\n");
    printf("            4\t\t                    2 \n");

}


void menu()
{

        printf("\n--------------------------------------");
        printf("\nWHICH FUNCTION DO YOU WANT TO PERFORM?\n");
        printf("---------------------------------------\n");
        printf("Enter\n");
        printf("1.Get the details of all the citizens of the city.\n");
        printf("2.To get the Top 10 richest citizen.\n");
        printf("3.Add new citizen.\n");
        printf("4.Delete existing citizen.\n");
        printf("5.To get the number of people residing in each house in increasing order\n");
        printf("6.Fetch the order in which the patients should meet the doctor\n");
        printf("7.To fetch the family tree of the family residing in a given house\n");
        printf("8.To fetch student details.\n");
        printf("9.Print optimum Path to avoid traffic\n");
        printf("10.Print the T.V. cable connectivity around the city.\n");
        printf("11.Print the details of a citizen\n");
        printf("12.Print the details of the citizen for a given phone number\n");
        printf("13.Print the shortest path to travel through out the city for waste pickup\n");
        printf("14.Print the optimal path to reduce the cost of laying the pipeline\n");
        printf("15.Print the shortest path to reach the given destination from the the hospital\n");
        printf("16.Check if there is direct bus between two locations\n");
        printf("17.Print the family tree of a house.\n");
        printf("18.To give the shortest route from a point to all other points.\n");
        printf("19.To check if the mobile number is hashed to a unique key\n");
        printf("20.Exit\n\n");
        printf("\n-------------------------------------------------------------------------------------\n");


}

/**
Function:add_details()
Description:Stores the content of citizens.txt file in  secondary storage using an array.
Input Param:NULL
Return Type:NULL
**/

void add_details()
{
    FILE *FP;
    FP=fopen("citizens.txt","a+");
    if(FP==NULL)
    {
        printf("File not found\n");
        exit(-1);
    }
    for(int i=0;i<CITIZENS;i++)
    {
        fscanf(FP,"%s %s %d %d %d %s %d %s\n",citizen[i].name,citizen[i].lname,&citizen[i].pin,&citizen[i].age,&citizen[i].hno,citizen[i].mobileno,&citizen[i].salary,citizen[i].profession);
    }
    fclose(FP);
       printf("Citizen details successfully added\n");

}

/**
Function:print_citizen()
Algorithm/Data Structure Used:Linked List.
Description:Prints the details of all the citizens present in the city.
Input Param:NULL
Return Type:NULL
**/

void print_citizen()
{
    insert_data();

    NODE *temp=head;
    if(head==NULL)
    {
        printf("The citizen list is empty\n");
    }
    while(temp != NULL)
    {
        printf("%s\t%s\t%d\t%d\t%d\t%s\t%d\t%s\n",temp->name,temp->lname,temp->age,temp->hno,temp->pin,temp->mobileno,temp->salary,temp->profession);
        temp=temp->next;
    }
    printf("\n");
}

/**
Function:Createnode()
Algorithm/Data Structure Used:Linked List.
Description:Creates a newnode and stores the details of citizen i in it.
Input Param:index i
Return Type:NODE* newnode
**/

NODE* Createnode(int i)
{
    NODE *newnode;
    newnode=(NODE*)malloc(sizeof(NODE));
    if(newnode==NULL)
    {
        printf("\nNode not created\n");
        exit(0);
    }

    strcpy(newnode->name,citizen[i].name);
    strcpy(newnode->lname,citizen[i].lname);
    newnode->pin=citizen[i].pin;
    newnode->age=citizen[i].age;
    newnode->hno=citizen[i].hno;
    strcpy(newnode->mobileno,citizen[i].mobileno);
    newnode->salary=citizen[i].salary;
    strcpy(newnode->profession,citizen[i].profession);
    newnode->next=0;
    return newnode;
}

/**
Function:insert_data()
Algorithm/Data Structure Used:Linked List insertion.
Description:Stores the details of the citizen in a linked list.
Input Param:NULL
Return Type:NULL
**/

void insert_data()
{
    for(int i=0;i<CITIZENS;i++)
    {
        NODE *Temp;
        newnode=Createnode(i);
     if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        Temp=head;
        while(Temp->next != NULL)
        {
            Temp=Temp->next;
        }
        Temp->next=newnode;
    }
    }

}

/**
Function:add_citizen()
Algorithm/Data Structure Used:Linked List insertion.
Description:Adds the details of new citizen the list.
Input Param:NULL
Return Type:NULL
**/

void add_citizen()
{

     InsertAtEnd();
     printf("Citizen details successfully added\n");
}

/**
Function:InsertAtEnd()
Algorithm/Data Structure Used:Linked List insertion.
Description:Inserts the the details of the new citizen.
Input Param:NULL
Return Type:NULL
**/

void InsertAtEnd()
{

     NODE *temp;
     addnode();
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }

}

/**
Function:addnode()
Algorithm/Data Structure Used:Linked List insertion.
Description:Stores the details of the citizen in a linked list.
Input Param:NULL
Return Type:NULL
**/

void addnode()
{
    NODE *newnode;
    newnode=(NODE*)malloc(sizeof(NODE));
    if(newnode==NULL)
    {
        printf("\nNode not created\n");
        exit(0);
    }
    printf("Enter the data to be inserted:\n");
    printf("Enter the name of the citizen:\n");
    scanf("%s",newnode->name);
    printf("Enter the lname of the citizen:\n");
    scanf("%s",newnode->lname);
    printf("Enter the pincode of the citizen:\n");
    scanf("%d",&newnode->pin);
    printf("Enter the age of the citizen:\n");
    scanf("%d",&newnode->age);
    printf("Enter the house number of the citizen:\n");
    scanf("%d",&newnode->hno);
    printf("Enter the mobile number of the citizen:\n");
    scanf("%s",newnode->mobileno);
    printf("Enter the salary of the citizen:\n");
    scanf("%d",&newnode->salary);
    printf("Enter the profession of the citizen:\n");
    scanf("%s",newnode->profession);
    newnode->next=0;

}

/**
Function:remove_citizen()
Algorithm/Data Structure Used:Linked list deletion.
Description:Deletes the details of a citizen from the record.
Input Param:NULL
Return Type:NULL
**/

void remove_citizen()
{
    printf("Enter the Sl.no of the citizen to be removed\n");
    int x;
    scanf("%d",&x);
    DeletePos(x);
    printf("Citizen successfully deleted\n");
}


/**
Function:DeletePos()
Algorithm/Data Structure Used:Linked list deletion.
Description:Deletes the details of a citizen of given sl.no from the record.
Input Param:Index x
Return Type:NULL
**/

void DeletePos(int pos)
{
    int count=0;
NODE    *temp=head;
    while(temp != 0)
    //traversing till last to count the number of nodes
    {
        count++;
       temp=temp->next;
    }
    if(head ==0)
    {
        printf("list is empty");
    }
    else if(head->next ==0)
    {
        printf("Item deleted is %s\n",temp->name);
        free(temp);
        head=0;
    }
    else if(pos==1)
    //delete from beg
    {
        head=DeleteFromBeginning(head);
    }
    else if(pos > count)
    //invalid pos
    {
        printf("Enter a valid position\n");
    }
    else if(pos == count)
    {
        head=DeleteFromEnd(head);
    }
    else
    {
        NODE *prev=0;
        temp=head;
        int i=1;
        while(i<pos)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        printf("Item deleted is %s\n",temp->name);
        free(temp);
    }
}

/**

Function:DeletePos()
Algorithm/Data Structure Used:Linked list deletion.
Description:Deletes the details of a citizen from the record if sl.no is 1.
Input Param:NULL
Return Type:NULL

**/

void DeleteFromEnd()
{
    NODE *prev=0;
    NODE  *temp=head;
    if(head==NULL)
    {
        printf("\nList is empty\n");
    }
    else if(head->next==NULL)
    {
        printf("The deleted citizen is %s\n",head->name);
        free(temp);
        head=NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        printf("\nDeleted citizen is %s\n",temp->name);
        free(temp);
        prev->next=0;
    }

}

/**
Function:DeleteFromBeginning()
Algorithm/Data Structure Used:Linked list deletion.
Description:Deletes the details of a citizen of given  from the record if sl.no = total number of citizens.
Input Param:Index x
Return Type:NULL
**/


void DeleteFromBeginning()
{
NODE  *temp=head;
    if(head==NULL)
    {
        printf("\nList is empty\n");
    }
    else if(head->next==NULL)
    //when there is only one node in the list
    {
        printf("The deleted citizen is %s\n",head->name);
        free(temp);
        head=NULL;
    }
    else
    {
        printf("\nDeleted name is %s\n",head->name);
        head=head->next;
        free(temp);
    }
}

/**
Function:print()
Description:Prints the contents of citizens.txt file.
Input Param:
Return Type:
**/

void print()
{
    printf("FIRST_NAME\tSURNAME\tAGE\tHOUSE_NO\tPIN\tPH_NO\tSALARY\tPROFESSION\n");
    for(int i=0;i<CITIZENS;i++)
    {
        printf("%s\t%s\t%d\t%d\t%d\t%s\t%d\t%s\n",citizen[i].name,citizen[i].lname,citizen[i].age,citizen[i].hno,citizen[i].pin,citizen[i].mobileno,citizen[i].salary,citizen[i].profession);
    }
}

/**
Function:get_income()
Algorithm Used:Bubble Sort
Description:To sort the income of all the citizens in the city.
Input Param:NULL
Return Type:NULL
**/

void get_income()
{
    add_details();
    for(int i=0;i<CITIZENS-2;i++)
    {
        for(int j=0;j<=CITIZENS-i-2;j++)
        {
            if(citizen[j+1].salary<citizen[j].salary)
            {
                temp=citizen[j];
                citizen[j]=citizen[j+1];
                citizen[j+1]=temp;
            }
        }
    }
    printf("The details of the citizens in increasing order of their is as follows:\n");
    print_10();
}

/**
Function:print_10()
Description:Prints the name and salary of the top 10 richest citizens in the city.
Input Param:NULL
Return Type:NULL
**/

void print_10()
{
    printf("\nTOP 10 RICHEST CITIZENS OF EUTOPIA\n");
    printf("FIRST_NAME\tSURNAME\tSALARY\n");
    int count=0;
    int i=CITIZENS-1;
    while(count<=10)
 {
     printf("%s\t%s\t%d\n",citizen[i].name,citizen[i].lname,citizen[i].salary);
     count++;
     i--;
 }

}

/**
Function:get_population()
Algorithm Used:insertion Sort
Description:To sort the houses in increasing order of the members
Input Param:NULL
Return Type:NULL
**/

void get_population()
{
    for(int i=0;i<HOUSE_MAX;i++)
    {
        house[i].hno=i+1;
        house[i].total=0;
        printf("%d %d\n",house[i].hno,house[i].total);
    }

    for(int i=0;i<CITIZENS;i++)
    {
        int x=citizen[i].hno;
        printf("house no is %d\n",x);
        switch(x)
        {
            case 1:house[0].total++;
            break;
            case 2:house[1].total++;
            break;
            case 3:house[2].total++;
            break;
            case 4:house[3].total++;
            break;
            case 5:house[4].total++;
            break;
        }
    }

    int j;
    struct houses v;
   for(int i=1;i<=HOUSE_MAX-1;i++)
   {

       v=house[i];
       j=i-1;
       while(j>=0 && house[j].total>v.total)
       {
           house[j+1]=house[j];
           j=j-1;
       }
       house[j+1]=v;

   }
   printf("HOUSENO\tTOTAL\n");
   for(int i=0;i<HOUSE_MAX;i++)
   {
       printf("%d\t\t%d\n",house[i].hno,house[i].total);
   }
}


void get_patient()
{
    FILE *FP;
    FP=fopen("hospital.txt","a+");
    if(FP==NULL)
    {
        printf("File not found\n");
        exit(-1);
    }
    for(int i=0;i<10;i++)
    {
        fscanf(FP,"%s %s %d %d %d %d\n",patient[i].name,patient[i].lname,&patient[i].age,&patient[i].priority,&patient[i].token);
    }
    fclose(FP);
    int n=10;
    int l,r;
    l=0;
    r=n-1;
    quick_sort(patient,l,r);

   for(int i=0;i<10;i++)
   {
       printf("%d %d\n",patient[i].priority,patient[i].token);
   }

}

void quick_sort(struct hospital a[],int l,int r)
{
    int s;
    if(l<r)
    {
        s=partition(a,l,r);
        quick_sort(a,l,s-1);
        quick_sort(a,s+1,r);
    }
}

int partition(struct hospital a[],int l,int r)
{
   struct hospital temp;
   int p,i,j;
   p=a[l].priority;
   i=l+1;
   j=r;
   while(i<=j)
   {
       while(i<=j && a[i].priority<=p)
       {
           i++;
       }
        while(i<=j && a[j].priority>=p )
       {
           j--;
       }
       if(i<=j)
        {

          temp.priority=a[i].priority;
          a[i].priority=a[j].priority;
          a[j].priority=temp.priority;
          temp.token=a[i].token;
          a[i].token=a[j].token;
          a[j].token=temp.token;
       }
   }
          temp.priority=a[l].priority;
          a[l].priority=a[j].priority;
          a[j].priority=temp.priority;
          temp.token=a[l].token;
          a[l].token=a[j].token;
          a[j].token=temp.token;

   return j;
}

/**
Function:get_family_tree()
Algorithm Used:Heap sort
Description:A mobile number given by the user can be used only if it is hashed to the key that is not yet occupied the existing numbers
Input Param:NULL
Return Type:NULL
**/


void get_family_tree()
{
    FILE *fp;
    int i=0,n,count=0,houseno;
    fp=fopen("citizens.txt","r");
        if(fp == NULL)
    {
        write_log("citizens.txt", "FILE_OPEN_ERROR", "Unable to open the supplied file");
        printf("Invalid file specified. Please check.\n\n");
        return FAILURE;
    }

    struct C citifinal[25];

    int j=0;
    for(int i=0;i<CITIZENS;i++)
    {
        fscanf(fp,"%s %s %d %d %d %s %d %s\n",citizen[i].name,citizen[i].lname,&citizen[i].pin,&citizen[i].age,&citizen[i].hno,citizen[i].mobileno,&citizen[i].salary,citizen[i].profession);
    }

    printf("Enter the house number for which the family tree should be crested based on their age\n");
    scanf("%d",&houseno);
    for(i=0;i<CITIZENS;i++)
    {
        if(citizen[i].hno == houseno)
        {
            count++;
            strcpy(citifinal[j].name,citizen[i].name);
            strcpy(citifinal[j].lname,citizen[i].name);
            citifinal[j].pin=citizen[i].pin;
            citifinal[j].age=citizen[i].age;
            citifinal[j].hno=citizen[i].hno;
            strcpy(citifinal[j].mobileno,citizen[i].mobileno);
            citifinal[j].salary=citizen[i].salary;
            strcpy(citifinal[j].profession,citizen[i].profession);
            j++;
        }

    }
    for(i=0;i<count;i++)
    {
         printf("%s %s %d %d %d %s %d %s\n",citifinal[i].name,citifinal[i].lname,citifinal[i].pin,citifinal[i].age,citifinal[i].hno,citifinal[i].mobileno,citifinal[i].salary,citifinal[i].profession);
    }

    printf("\n****\n");
    heapify(citifinal,count);
    heap_sort(citifinal,count);
    printf("sorted array:\n");
    for(int i=1;i<count;i++)
    {
        printf("%d\n",citifinal[i].age);
    }
}

/**
Function:heapify()
Algorithm Used:Heap sort
Description:Sorts citizens based on their age.
Input Param:Citizen array and total number of citizens
Return Type:NULL
**/

void heapify(struct C *citifinal,int n)
{
     int i,j,v,k,heap,m;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=citifinal[k].age;
        heap=0;

        while(heap!=1 && (2*k)<=n)
        {
            j=2*k;
            if(j<n-1)
            {
               if(citifinal[j].age<citifinal[j+1].age)
               {
                   j++;
               }
            }
            if(v>=citifinal[j].age)
            {
                heap=1;
            }
            else
            {
                citifinal[k].age=citifinal[j].age;
                k=j;
            }
        }
        citifinal[k].age=v;
}
}

/**
Function:heap_sort()
Algorithm Used:Heap sort
Input Param:NULL
Return Type:NULL
**/

void heap_sort(struct C*citifinal)
{
    int i,v;
    for(i=CITIZENS-1;i>=1;i--)
    {
        v=citifinal[1].age;
        citifinal[1].age=citifinal[i].age;
        citifinal[i].age=v;
        heapify(citifinal,i-1);
    }
}

/**
Function:cable_connection()
Algorithm Used:Depth first search
Description:Prints the T.V. cable connectivity around the citifinal.
Input Param:NULL
Return Type:NULL
**/

void cable_connection()
{
    int i,j;

    int m[12][12];
    int src;
    FILE *fp;
    for (i= 0; i < v; i ++)
    {
         visited[i] = 0;
    }

    fp=fopen("adj_matrix.txt","r+");
        if(fp == NULL)
    {
        printf("Invalid file specified. Please check.\n\n");

    }

       for(i=0;i<12;i++)
        {
            for(j=0;j<12;j++)
            {
                fscanf(fp,"%d ",&m[i][j]);
            }
            fscanf(fp,"\n");
        }

    printf("Enter the source:\n");
    scanf("%d",&src);
    printf("The DFS Traversal is \n");

    dfs(m, v, src);
}

/**
Function:dfs()
Algorithm Used:Depth first search
Description:Prints the T.V. cable connectivity around the city.
Input Param:adjacency matrix,source and total number of vertices v
Return Type:NULL
**/

void dfs(int m[10][10],int v,int src)
{
    int i;
    visited[src] = 1;
    printf("%d\t",src);
    for(i=0; i<v; i++)
    {
        if(m[src][i] != 0 && visited[i] == 0)
        {
            dfs(m, v, i);
        }
    }
}

/**
Function:compute_failure_function()
Algorithm Used:KMP
Description:Matches the phone number given as input to the existing numbers present.
Input Param:pattern string and failure;
Return Type:NULL
**/

void compute_failure_function(char* pattern[10], int failure_function[])
 {
    int i = 1, j = 0;
   failure_function[0] = 0;
    while (i < strlen(pattern))
        {
        if (pattern[i] == pattern[j])
        {

           failure_function[i] = j + 1;
            i++;
            j++;
        }
        else if (j > 0)
        {
           j = failure_function[j - 1];
        }
        else
        {
            failure_function[i] = 0;
            i++;
        }
    }
}

/**
Function:kmp_search()
Algorithm Used:KMP
Description:Matches the phone number given as input to the existing numbers present.
Input Param:pattern string and text string;
Return Type:NULL
**/

int  kmp_search(char* text, char* pattern)
{
    int n = strlen(text);

    int m = strlen(pattern);

    int failure_function[m];

    compute_failure_function(pattern, failure_function);

    int i = 0, j = 0;
    while (i < n)
        {

        if (text[i] == pattern[j])
        {

            if (j == m - 1)

            {

                return 1;

            }
        }
}
return 0;

}

/**
Function:true_caller()
Algorithm Used:KMP
Description:Matches the phone number given as input to the existing numbers present.
Input Param:NULL
Return Type:NULL
**/

void  true_caller()
 {
     char text[10];
     int flag=0;
     char pattern[10];
     printf("Enter the mobile number\n");
     scanf("%s",pattern);
    for(int i=0;i<CITIZENS;i++)
    {
        strcpy(text,citizen[i].mobileno);
        flag=kmp_search(text, pattern);
        if(flag)
        {
            printf("The details of the citizen with the number\n");
            printf("%s\n",pattern);
            printf("%s\t%s\n",citizen[i].name,citizen[i].lname);
            return;
        }
    }

    printf("Citizen with the number %s not found\n",pattern);
 }


/**
Function:get_customers()
Algorithm Used:merge sort
Description:sorts the customers based on their check in time.
Input Param:NULL
Return Type:NULL
**/

void get_customers()
{
   int n=12;
     FILE *fp;
    int i,j,k;
    fp=fopen("hotel.txt","r");
    for(i=0;i<12;i++)
    {
        fscanf(fp,"%s %f %f %s %d",&a[i].name,&a[i].check_in,&a[i].check_out,&a[i].order,&a[i].cost);
        fscanf(fp,"\n");
    }
    fclose(fp);
  merge(a,n);
  printf("The first 5 customers who checked in today are\n");
  for(int i=0;i<5;i++)
  {

      printf("%s   %.2f   %.2f   %s   %d\n",a[i].name,a[i].check_in,a[i].check_out,a[i].order,a[i].cost);
  }
}

void merge(struct hotel a[],int n)
{
 struct hotel b[12],c[12];
    int i,p,q;
    p=ceil(n/2);
    q=n-p;
    if(n>1)
    {
    for(int i=0;i<p;i++)
        {
            b[i]=a[i];
        }
        int k=0;
    for(int i=p;i<n;i++)
    {
        c[k]=a[i];
        k++;

    }
     merge(b,p);
    merge(c,q);
    MergeSort(b,p,c,q,a,n);
    }
}

void MergeSort(struct hotel b[],int p,struct hotel c[],int q,struct hotel a[],int n)
{
    int i=0;
    int j=0;
    int k=0;
    while(i<p && j<q)
    {
        int b1,c1;
        b1 = (int)b[i].check_in * 60 + (b[i].check_in - (int)b[i].check_in) * 100;
        c1= (int)c[j].check_in * 60 + (c[j].check_in - (int)c[i].check_in) * 100;
        if(b1<=c1)
        {
            a[k]=b[i];
            i++;
        }
        else{
            a[k]=c[j];
            j++;
        }
        k++;

    }
    if(i==p)
    {
        for(i=j;i<q;i++)
        {
            a[k]=c[i];
            k++;
        }
    }
    else
    {
        for(j=i;j<p;j++)
        {
        a[k]=b[j];
        k++;
        }
    }
}




/**
Function:ambulance_service()
Algorithm Used:dijekstra
Description:Prints the shortest route to reach the destination from the hospital
Input Param:NULL
Return Type:NULL
**/

void ambulance_service()
{
    int graph[VERTICES][VERTICES];

    FILE* file = fopen("adj_matrix.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file ");
        exit(1);
    }

    for (int i = 0; i < VERTICES; i++)
    {
         for (int j = 0; j < VERTICES; j++)
         {
             fscanf(file, "%d", &graph[i][j]);
         }
    }

    fclose(file);
    int dest;
    printf("Enter the destination node: ");
    scanf("%d",&dest);
    dijkstra(graph, dest);

}

//Function name:minDistance
//Description:Used to update the values in  dist and visited array in every iteration
//Input Param:dist array and visited array
//Output param:Returns minimum index

int minDistance(int dist[], int visited[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < VERTICES; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}


//Function name:dijkstra
//Description:Yields the shortest path from source to other nodes.
//Input Param:cost matrix,destination vertex
//Output param:NULL

void dijkstra(int graph[VERTICES][VERTICES], int dest)
{
    int dist[VERTICES], prev[VERTICES], visited[VERTICES];

    for (int i = 0; i < VERTICES; i++)
    {
        dist[i] = INT_MAX;
        prev[i] = -1;
        visited[i] = 0;
    }

    // Distance of destination node from itself is always 0
    dist[dest] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < VERTICES-1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, visited);

        // Mark the picked vertex as processed
        visited[u] = 1;

        // Update dist value and prev[] of the adjacent vertices of the picked vertex
        for (int v = 0; v < VERTICES; v++)
        {
            // Update dist[v] and prev[v] only if it is not in visited, there is an edge from u to v,
            // and total weight of path from source to v through u is smaller than current value of dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }

    // Print the shortest distances and routes to destination from every node
    printf("Shortest distances and routes to node %d:\n", dest);
    printf("From node %d to %d: %d", 7, dest, dist[7]);

    // Print out the route from i to dest
    if (dist[7] != INT_MAX)
    {
        printf(" (Route: %d", 7);
        int j = prev[7];
        while (j != -1)
           {
            printf(" -> %d", j);
            j = prev[j];
           }
        printf(")");
    }

    printf("\n");
}

/**
Function:water_pipeline()
Algorithm Used:kruskals algorithm
Description:This function gives an efficient path to lay the water pipeline which yields minimum cost.
Input Param:
Return Type:
**/

void water_pipeline()
{
    int i,j,k_krus=0,a[VERTICES][VERTICES];
    FILE *fp;
    fp=fopen("adj_matrix.txt","r");
    for(i=0;i<VERTICES;i++)
    {
        for(j=0;j<VERTICES;j++)
        {
            fscanf(fp,"%d",&a[i][j]);
        }
        fscanf(fp,"\n");
    }
    fclose(fp);
    int count=0;
    for(i=0;i<VERTICES;i++)
    {
        for(j=0;j<VERTICES;j++)
        {
            if(i<j)
            {
            if(a[i][j]!=0)
            {

                v[k_krus].u=i;
                v[k_krus].v=j;
                v[k_krus].w=a[i][j];
                k_krus++;
                count++;

            }

            }
        }
    }

    selection_sort(v,EDGES);
    int b[VERTICES];
    for(int i=0;i<VERTICES;i++)
    {
        b[i]=i;
    }
    int sum;
    int cost;
    printf("An effective way of laying a pipeline for water supply is as follows:\n");
    sum=kruskal(v,b,EDGES,VERTICES);

    printf("The total length of the pipeline would be: %d km\n",sum);

    printf("Enter the cost/m of pipe\n");
    scanf("%d",&cost);
    cost=cost*sum*1000;
    printf("The total cost would be Rs.%d\n",cost);
}


//Function:selection_sort
//Algorithm Used:selection sort
//Description:Sorts the edges based on their weights
//Input Param:NULL
//Return Type:NULL

void selection_sort(struct dump v[20],int E)
{

    int min,i,j;
    struct dump temp;
    for(i=0;i<E-1;i++)
    {
        min=i;
        for(j=i+1;j<E;j++)
        {
            if(v[j].w<v[min].w)
            {
                min=j;
            }
        }
        temp=v[i];
        v[i]=v[min];
        v[min]=temp;

    }
}

/**
Function:check()
Algorithm Used:Basic comparision
Description:Checks if all the elements of the array are distinct.
Input Param:vertex and b array;
Return Type:returns 1 if any one element of the array is distinct.
            returns 0 if all the elements of the array is same.
**/

int check(int b[12],int V)
{
    for(int i=0;i<V-1;i++)
    {
        if(b[i]!=b[i+1])
        {
            return 1;
        }
    }
    return 0;
}

/**
Function:find()
Algorithm Used:find
Input Param:index u ,v and array b.
Return Type:Returs 1 if the elements present at index at u and v are distinct.
            Returs 0 if the elements present at index at u and v are same.
**/

int find(int u,int v,int b[12])
{
    if(b[u]==b[v])
    {
        return 0;
    }
    return 1;
}

/**
Function:kruskal()
Algorithm Used:kruskal
DEscription:Gives the minimum spanning tree.
Input Param:structure dump v,array b,total number of vertices V.
Return Type:returns the total cost.
**/

int kruskal(struct dump v[20],int b[12],int E,int V)
{
    int i=0,sum=0;
    while(check(b,V))
    {
        if(find(v[i].u,v[i].v,b))
        {
            printf("Lay a pipeline from %d to %d\n",v[i].u,v[i].v);
            sum=sum+v[i].w;
            union_k(v[i].u,v[i].v,b,V);
        }
        i++;
    }
    return sum;
}

/**
Function:union_k()
Algorithm Used:union
Input Param:index u ,v and array b,total number of vertices v.
Return Type:NULL
**/

void union_k(int u,int v,int b[12],int V)
{
    int temp;

    temp=b[u];
    for(int i=0;i<V;i++)
    {
         if(b[i]==temp)
         {
             b[i]=b[v];
         }
    }
}


/**
Function:bst_students()
Algorithm Used:Binary Search tree
Description:Creates bst of students of particular standard based on their percentage.
Input Param:NULL
Return Type:NULL
**/

void bst_students()
{
    FILE *fp;
    TREE *root=NULL;
    int ch,std,i;
    struct student s[S];
    struct student s1[S];
    int j=0,count=0;
    fp=fopen("students.txt","r");
        if(fp == NULL)
    {
        write_log("students.txt", "FILE_OPEN_ERROR", "Unable to open the supplied file");
        printf("Invalid file specified. Please check.\n\n");
        return;
        //return FAILURE;
    }
    for(int i=0;i<S;i++)
    {
        fscanf(fp,"%s %c %d %d %d\n",s[i].name,&s[i].div,&s[i].age,&s[i].standard,&s[i].percentage);
    }

    for(int i=0;i<S;i++)
    {
        printf("%s %c %d %d %d\n",s[i].name,s[i].div,s[i].age,s[i].standard,s[i].percentage);
    }
while(ch!=5)
{

    printf("Enter the choice\n");
    printf("1.Construct a new binary search tree of students of a particular standard\n");
    printf("2.Display the preorder traversal on the BST\n");
    printf("3.Display the inorder traversal on the BST\n");
    printf("4.Display the postorder traversal on the BST\n");
    printf("5.Exit\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: printf("Enter the student's standard on which The BST to be created\n");
                scanf("%d",&std);
                for(i=0;i<S;i++)
                {

                    if(s[i].standard==std)
                    {

                        count++;
                        strcpy(s1[j].name,s[i].name);
                        s1[j].div=s[i].div;
                        s1[j].age=s[i].age;
                        s1[j].standard=s[i].standard;
                        s1[j].percentage=s[i].percentage;
                        j++;
                    }
                }


                for(i=0;i<count;i++)
                {
                     printf("%s %c %d %d %d\n",s1[i].name,s1[i].div,s[i].age,s1[i].standard,s1[i].percentage);
                }
                for(i=0;i<count;i++)
                {
                    insert_into_bst(root,s1[i].percentage);
                }
                break;

      case 3:
          if(root==NULL)
      {
          printf("Tree is empty\n");
      }

        else
              {
                  inorder(root);
              }

        break;
      case 2: if(root==NULL)
                {
                   printf("Tree is empty\n");
                }
             else
             {
                 preorder(root);
             }

             break;
      case 4: if(root==NULL)
               {
                    printf("Tree is empty\n");
               }
            else
            {
                postorder(root);
            }
           break;

      case 5: break;

      default : printf("Invalid choice\n");
               break;

    }
}

    fclose(fp);
}

/**
Function:insert_into_bst()
Algorithm Used:Binary Search tree
Description:Creates bst of students of particular standard based on their percentage.
Input Param:root and data to be inserted.
Return Type:NULL
**/


void insert_into_bst(TREE *root,int data)
{

    TREE *newnode;
    newnode=(TREE*)malloc(sizeof(TREE));

    if(newnode==NULL)
    {
        printf("Memory not available in Heap\n");
        return  ;
    }

    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    if(root==NULL)
    {
        root=newnode;

    }
    TREE *curr,*parent;
    curr= root;
    parent= NULL;

    while(curr !=NULL)
    {
        parent=curr;
        if(newnode->data <curr->data)
        {
            curr=curr->left;
        }

        else
        {
            curr=curr->right;
        }

    }
    if(newnode->data < parent->data)
    {
         parent->left=newnode;
    }

    else
    {
        parent->right=newnode;
    }

}

/**
Function:inorder()
Algorithm Used:Binary Search tree
Description:Prints inorder of the bst formed.
Input Param:NULL
Return Type:NULL
**/

void inorder(TREE *root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    printf("%d-->\t" ,root->data);
    inorder(root->right);
    }
}

/**
Function:preorder()
Algorithm Used:Binary Search tree
Description:Prints the preorder traversal
Input Param:NULL
Return Type:NULL
**/

void preorder(TREE *root)
{
    if(root!=NULL)
    {
    printf("%d-->\t ",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

/**
Function:postorder()
Algorithm Used:Binary Search tree
Description:Prints the postorder traversal of the tree.
Input Param:NULL
Return Type:NULL
**/

void postorder(TREE *root)
{
    if(root!=NULL)
    {
    postorder(root->left);
    postorder(root->right);
     printf("%d-->\t" ,root->data);
    }
}

/**
Function:get_details()
Algorithm Used:brute force string search
Description:To fetch the details of mentioned citizens
Input Param:
Return Type:returns 1 if match
**/

void get_details()
{

    char key[20],text[20];

    printf("Enter the first name of the citizen to be fetched\n");
    scanf("%s",key);
    int m=strlen(key);
    for(int i;i<CITIZENS;i++)
    {
        strcpy(text,citizen[i].name);
        int n=strlen(text);
        for(int i=0;i<n-m;i++)
        {
            int j=0;
            while(j<m && key[j]==text[i+j])
            {
                j++;
            }
            if(j==m)
            {
                printf("Citizen with first name %s found\n",key);

                printf("Citizen Details\n");

                printf("%s\t%s\t%d\t%d\t%d\t%s\t%d\t%s\n",citizen[i].name,citizen[i].lname,citizen[i].age,citizen[i].hno,citizen[i].pin,citizen[i].mobileno,citizen[i].salary,citizen[i].profession);
            return;
            }
       }

    }
    printf("Citizen with name %s doesn't exist\n",key);
}

/**
Function:get_path()
Algorithm Used:Floyd
Description:Gives the shortest path from a point to every other point.
Input Param:NULL
Return Type:NULL
**/

void get_path()
{
    int src;
    int m[VERTICES][VERTICES];

    printf("Enter the source from which you want to find the shortest distance\n");
    scanf("%d",&src);
     FILE *fp;
    int i,j;
    fp=fopen("floyd.txt","r");
    for(i=0;i<VERTICES;i++)
    {
        for(j=0;j<VERTICES;j++)
        {
            fscanf(fp,"%d",&m[i][j]);
        }
        fscanf(fp,"\n");
    }
    fclose(fp);

    floyd(m, src);
}

/**
Function:floyd()
Algorithm Used:Floyd
Description:Gives the shortest path from a point to every other point.
Input Param:cost matrix and source vertex.
Return Type:NULL
**/

void floyd(int m[VERTICES][VERTICES], int src)
{
    int dist[VERTICES][VERTICES];
    int i, j, k;

    for (i = 0; i < VERTICES; i++)
        for (j = 0; j < VERTICES; j++)
            dist[i][j] = m[i][j];

    for (k = 0; k < VERTICES; k++)
    {
        for (i = 0; i < VERTICES; i++)
        {
            for (j = 0; j < VERTICES; j++)
            {
                if (dist[i][k] != INT_MAX &&
                    dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", src);
    for (i = 0; i < VERTICES; i++)
    {
        if (i != src)
        {
            printf("%d -> %d: %d\n", src, i, dist[src][i]);
        }
    }
}

/**
Function:find_bus()
Algorithm Used:warshall
Description:Finds if there is a direct bus connectivity between two points.
Input Param:NULL
Return Type:NULL
**/

void find_bus()
{

    int a[VERTICES][VERTICES];
    int d,i,s,j;
     FILE *fp;

    fp=fopen("warshall.txt","r");
    for(i=0;i<VERTICES;i++)
    {
        for(j=0;j<VERTICES;j++)
        {
            fscanf(fp,"%d",&a[i][j]);
        }
        fscanf(fp,"\n");
    }
    fclose(fp);

    printf("Enter source and destination vertices: ");
    scanf("%d %d",&s,&d);

    warshall(a);

    if(a[s][d]==1)
    {
        printf("%d and %d are connected.\n",s,d);
    } else
    {
        printf("%d and %d are not connected.\n",s,d);
    }
}

/**
Function:warshall()
Algorithm Used:Floyd
Description:Gives the shortest path from a point to every other point.
Input Param:adjacency matrix
Return Type:NULL
**/
void warshall(int a[VERTICES][VERTICES])
{
    int i,j,k;

    for(k=0;k<VERTICES;k++)
        {
        for(i=0;i<VERTICES;i++)
        {
            for(j=0;j<VERTICES;j++)
            {
                if(a[i][j]==0 && a[i][k]==1 && a[k][j]==1)
                {
                    a[i][j]=1;
                }
            }
        }
    }

}

void bfs()
{
      FILE  *fp;
    int i,j;
    int start;
    int m[12][12];
    fp=fopen("adj_matrix.txt","r");
        if(fp == NULL) {
        //write_log("add_key", "FILE_OPEN_ERROR", "Unable to open the supplied file");
        printf("Invalid file specified. Please check.\n\n");
        //return FAILURE;
    }


        for(i=0;i<12;i++)
        {
            for(j=0;j<12;j++)
            {
                fscanf(fp,"%d ", &m[i][j]);
            }
            fscanf(fp,"\n");
        }


    for(int i=0;i<12;i++)
        {
            for(j=0;j<12;j++)
            {
                printf("%d", m[i][j]);
            }
            printf("\n");
        }


    printf("Enter the source\n");
    scanf("%d",&start);
    BFS(m,start);
    fclose(fp);
}


void BFS(int graph[VERTICES][VERTICES], int start)
{
    int queue[VERTICES];
    bool visited[VERTICES] = { false };
    int distances[VERTICES] = { 0 };
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    printf("BFS traversal starting from vertex %d: ", start);

    while (front < rear)
    {
        int vertex = queue[front++];

        printf("%d ", vertex);

        for (int i = 0; i < VERTICES; i++)
        {
            if (graph[vertex][i] != 0 && !visited[i])
            {
                visited[i] = true;
                distances[i] = distances[vertex] + 1;
                queue[rear++] = i;
            }
        }
    }
        printf("\nDistances from vertex %d: \n", start);
    for (int i = 0; i < VERTICES; i++)
    {
        printf("%d -> %d: %d\n", start, i, distances[i]);
    }
}



/**
Function:waste_pickup()
Algorithm Used:prims
Description: Gives the shortest path to travel through the city for wate pickup.
Input Param:key array and mstSet array
Return Type:NULL
**/


void waste_pickup()
{
    int graph[VERTICES][VERTICES];

    //open the file containing adjacency matrix with weights
    FILE* file = fopen("adj_matrix.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file ");
        exit(1);
    }

    for (int i = 0; i < VERTICES; i++)
    {
         for (int j = 0; j < VERTICES; j++)
         {
             fscanf(file, "%d", &graph[i][j]);
         }
    }

     fclose(file);
    //printing the total weight of MST
    int totalWeight = PrimMST(graph);
    printf("\nTotal minimum distance the garbage pick up vehicle travels is %d kms.\n", totalWeight);
}

/**
Function:minKey()
Algorithm Used:prims
Description: Function to find the vertex with minimum distance value, from the
             set of vertices not yet included in the MST
Input Param:key array and mstSet array
Return Type:NULL
**/

int minKey(int key[], int mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < VERTICES; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

/**
Function:dfsMST()
Algorithm Used:prims
Description:Function to print MST for a graph represented using adjacency
Input Param:visited matrix,parent matrix,adjacency matrix,u
Return Type:NULL
**/

void dfsMST(int u, int visited[], int parent[], int graph[VERTICES][VERTICES])
{
    visited[u] = 1;
    if(u!=11)
    printf("%d ->", u);
    else printf("%d", u);

    for (int v = 0; v < VERTICES; v++)
     {
        if (graph[u][v] && !visited[v] && parent[v] == u)
        {
            dfsMST(v, visited, parent, graph);
        }
    }
}
    // Function to construct MST for a graph represented using adjacency
    // matrix representation
    int PrimMST(int graph[VERTICES][VERTICES])
    {
	    // Array to store constructed MST
        int parent[VERTICES];

	    // Key values used to pick minimum weight edge in cut
        int key[VERTICES];

	    // To represent set of vertices not yet included in MST
        int mstSet[VERTICES];

        int visited[VERTICES];
        int totalWeight = 0;

        for (int i = 0; i < VERTICES; i++)
        {
		// Initialize all keys as INFINITE
		key[i] = INT_MAX;

		mstSet[i] = 0;
            visited[i] = 0;
        }
	    // Always include the first vertex in MST.
        // Make key 0 so that this vertex is picked as the first vertex
        key[0] = 0;

	    // First node is always the root of MST
        parent[0] = -1;

        for (int count = 0; count < VERTICES - 1; count++)
            {
	        // Pick the minimum key vertex from the set of vertices
	        // not yet included in MST
          	int u = minKey(key, mstSet);

        	// Add the picked vertex to the MST Set
            mstSet[u] = 1;

		    // Update key value and parent index of the adjacent vertices of
          	// the picked vertex. Consider only those vertices which are not yet
        	// included in MST
            for (int v = 0; v < VERTICES; v++)
                {

		        // graph[u][v] is non-zero only for adjacent vertices of m
                // mstSet[v] is false for vertices not yet included in MST
                // Update the key only if graph[u][v] is smaller than key[v]
                if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }
	    // print the constructed MST
        printf("Efficient way to travel across the city for waste pickup from 0th location is:\n");
        dfsMST(0, visited, parent, graph);
        printf("\n");

        for (int i = 1; i < VERTICES; i++)
        {
            totalWeight += graph[parent[i]][i];
        }

        return totalWeight;
    }

/**
Function:unique_number()
Algorithm Used:hashing
Description:A mobile number given by the user can be used only if it is hashed to the key that is not yet occupied the existing numbers
Input Param:
Return Type:
**/

void unique_number()
{
    int count=0;
    for(int i=0;i<CITIZENS;i++)
    {
            count=calculate(citizen[i].mobileno);
            count=count/997;
            hashtable[count%(HASH_TABLE_SIZE)]==1;
    }

    int key,number;

    printf("Enter the new number to be added\n");
    scanf("%d",&number);
    key=calculate(number);
    key=key/997;
    if(hashtable[key%(HASH_TABLE_SIZE)]==1)
    {
        printf("The given number is hashed to the the key occupied by existing phone number\n");
    }
}

//Function   :  calculate
//Description:  calculates the sum of all the characters in a given string.
//Input param:  NULL
//Return Type:  NULL
int calculate(char n[10])
{
    int count=0;
    for(int i=0;n[i];n++)
    {
        count=count+n[i];
    }
    return count;
}


//This is the main function.

int main()
{

    printf("\t\t\t\t\tDSA COURSE PROJECT\t\t\t\t\t\t\n");

    printf("W   W  EEEEE  L      CCCC   OOOO   M     M  EEEEE\n");
    printf("W   W  E      L     C      O    O  MM   MM  E    \n");
    printf("W   W  E      L     C      O    O  M M M M  E    \n");
    printf("W W W  EEEE   L     C      O    O  M  M  M  EEEE \n");
    printf("W W W  E      L     C      O    O  M     M  E    \n");
    printf(" W W   E      L     C      O    O  M     M  E    \n");
    printf("  W    EEEEE  LLLLL  CCCC   OOOO   M     M  EEEEE\n");

    printf("\t\t\t\t\t\tWELCOME TO EUTOPIA\t\t\t\t\t\t\n");

       status=load();
       if(!status)
     {
       printf("LOAD FAILED\n");
       return 0;
     }

     add_details();

     get_map();

      while(1)
    {
        menu();

        printf("Enter your choice\n");

        scanf("%d",&choice);

        switch (choice)
        {

          case 1:
              printf("The details of the citizen are as follows:\n\n");
              print_citizen();
              break;

          case 2:get_income();
          break;

          case 3:add_citizen();
          break;

          case 4:remove_citizen();
          break;

          case 5:get_population();
          break;

          case 6:get_patient();
          break;

          case 7:get_family_tree();
          break;

          case 8:get_customers();
          break;

          case 9:bfs();
          break;

          case 10:cable_connection();
          break;

          case 11:get_details();
          break;

          case 12:true_caller();
          break;

          case 13:waste_pickup();
          break;

          case 14:water_pipeline();
          break;

          case 15:ambulance_service();
          break;

          case 16:find_bus();
          break;

          case 17:bst_students();
          break;

          case 18:get_path();
          break;

          case 19:unique_number();
          break;

          case 20:return 0;
          break;

          default:printf("Invalid Choice\n");
          break;
}
    }

    return 0;
}


