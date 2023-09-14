/*Create a movie ticket booking system using a queue.
It will ask to enter a number of members.
It will display vacant seats and occupied seats.*/


#include<stdio.h>
#include<string.h>
#define N 10
char queue[N][50]; //globally declaring queue of people
int f=-1;
int r=-1;
char seats[10][10]={{'A','1','2','3','4','5','6','7','8','9'}, // declaring ticket structure globally
{'B','1','2','3','4','5','6','7','8','9'},
{'C','1','2','3','4','5','6','7','8','9'},
{'D','1','2','3','4','5','6','7','8','9'},
{'E','1','2','3','4','5','6','7','8','9'},
{'F','1','2','3','4','5','6','7','8','9'},
{'G','1','2','3','4','5','6','7','8','9'},
{'H','1','2','3','4','5','6','7','8','9'},
{'I','1','2','3','4','5','6','7','8','9'},
{'J','1','2','3','4','5','6','7','8','9'},
                   };

void enqueue(char Name[]) //function for adding people in queue
{
    if(f==-1 && r==-1) //adding when queue is empty
    {
        f=r=0;
        strcpy(queue[r],Name);

    }
    else if((r+1)%N==f) //when queue is full
        printf("Sorry but the Queue is full... Enter the name when asked again\n\n");
    else
    {
        r=(r+1)%N;
        strcpy(queue[r],Name);
    }
}

void dequeue(int tickets) //removing people from queue when the tickets are bought
{
    int i=0;
    if(f==-1 && r==-1) // if no one is in the queue
        printf("There is no one present in the queue right now... \n");


    else if(f==r) // if it is the last person in the queue
    {
        printf("%s your bill amount is %d, enjoy the show\n\n",queue[f],tickets*200); // while removing the person, we are showing his bill amount
        f=r=-1;
    }
    else
    {
        printf("%s your bill amount is %d, enjoy the show\n\n",queue[f],tickets*200);
        f=(f+1)%N;
    }
}

void display() //function to show who are present in the queue
{
    int i=f;
    if(f==-1 && r==-1) // when there is no one in the queue
        printf("There is no one present in the queue right now... \n\n");

    else
    {
        printf("Queue is: \n");
        printf("\n");
        while(i!=r) // displaying the queue
        {
            puts(queue[i]);
            i=(i+1)%N;
        }
        puts(queue[r]); //displaying the last person in the queue
        printf("\n");
    }
}

void showSeats() // function to show which seats are occupied and which are vacant
{
    printf("\nO is printed for occupied seats\n");
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%c  ",seats[i][j]);
        }
        printf("\n");
    }

}

int checkIfEmpty() // if the queue is empty, 0 will be returned and if someone is present then 1 is returned
{
     if(f==-1 && r==-1)
     {
        printf("There is no one present in the queue right now... \n\n");
        return 0;
     }
     return 1;

}
int checkIfFull()// if the queue is full, 0 will be returned  and if there is still space 1 is returned
{
     if((r+1)%N==f)
     {
         printf("Sorry but the Queue is full... Enter the name when asked again\n\n");
         return 0;
     }
     return 1;

}

checkIfPossible(int x) // function to check if the number of seats inputed by the user are empty or not
{
    int c;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(seats[i][j]=='O') // c is count of occupied seats
                c++;
        }
    }
    if(x<=90-c && x>0) // if that many tickets can be bought then return 1
    {
        return 1;
    }
    else
    {
        printf("Not Possible\n\n");
        return 0;
    }
}

void main()
{
    int n;
    printf("--------------------    Welcome to the Theater    --------------------\n\n\n");
    printf("How many people are present in the line?  "); // people present in line initially
    scanf("%d",&n);
    char name[n][50];
    char ticname[100][3];
    char row;
    int seat;

    for(int i=0;i<n;i++)
    {
        printf("Enter the name of the person %d:  ",i+1); // adding the people in queue
        fflush(stdin);
        gets(name[i]);
        enqueue(name[i]);
    }

    int d=1,ch;
    while(d==1)
    {
        printf("\n1.Add a person in the queue \n2.Display people present in queue \n3.Show Ticket Structure \n4.Buy Tickets \n5.exit \nEnter your choice:  ");
        scanf("%d",&ch);
        printf("\n");
        switch(ch)
        {
            case 1: printf("Hello ");
                    int flag=checkIfFull();
                    if(flag==1)// only if the queue is not full
                    {
                        printf("Enter the name of the person added in the queue:  ");
                        char add[50];
                        fflush(stdin);
                        gets(add);
                        enqueue(add);// adding the name to queue
                    }
                    break;

            case 2: display();//calling display function
                    break;

            case 3: showSeats();//calling the function to see the seat structure
                    break;

            case 4: printf("Hello ");
                    int t;
                    int flag1=checkIfEmpty();
                    if(flag1==1)//only if the queue is not empty
                    {
                        printf("Welcome ");
                        puts(queue[f]);

                        printf("Enter how many tickets you want to book.(Each will cost Rs.200):  ");
                        scanf("%d",&t);
                        int flag2=checkIfPossible(t);//only if the scanned number of seats are vacant
                        if(flag2==1)
                        {
                            showSeats();
                            for(int j=0;j<t;j++)// for that many number of seats
                            {
                                printf("Enter the row you want from A to J (in capital):  ");//in which row
                                fflush(stdin);
                                scanf("%c",&row);
                                if(row=='A')
                                {
                                    printf("Enter which seat you want:  ");
                                    scanf("%d",&seat);
                                    if(seat>9 || seat<=0)//for the seats which are available in theater
                                    {
                                        printf("Enter valid seat number\n");
                                        j--;
                                    }
                                    else
                                    {
                                        if(seats[0][seat]!='O')
                                        seats[0][seat]='O';//book the seat if not already booked
                                        else
                                        {
                                            printf("The seat is occupied, choose another one\n");
                                            j--;
                                        }
                                    }

                                }
                                else if(row=='B')
                                {
                                    printf("Enter which seat you want:  ");
                                    scanf("%d",&seat);
                                    if(seat>9 || seat<=0)
                                    {
                                        printf("Enter valid seat number\n");
                                        j--;
                                    }
                                    else
                                    {
                                        if(seats[1][seat]!='O')
                                        seats[1][seat]='O';
                                        else
                                        {
                                            printf("The seat is occupied, choose another one\n");
                                            j--;
                                        }
                                    }
                                }
                                else if(row=='C')
                                {
                                    printf("Enter which seat you want:  ");
                                    scanf("%d",&seat);
                                    if(seat>9 || seat<=0)
                                    {
                                        printf("Enter valid seat number\n");
                                        j--;
                                    }
                                    else
                                    {
                                        if(seats[2][seat]!='O')
                                        seats[2][seat]='O';
                                        else
                                        {
                                            printf("The seat is occupied, choose another one\n");
                                            j--;
                                        }
                                    }
                                }
                                else if(row=='D')
                                {
                                    printf("Enter which seat you want:  ");
                                    scanf("%d",&seat);
                                    if(seat>9 || seat<=0)
                                    {
                                        printf("Enter valid seat number\n");
                                        j--;
                                    }
                                    else
                                    {
                                        if(seats[3][seat]!='O')
                                        seats[3][seat]='O';
                                        else
                                        {
                                            printf("The seat is occupied, choose another one\n");
                                            j--;
                                        }
                                    }
                                }
                                else if(row=='E')
                                {
                                    printf("Enter which seat you want:  ");
                                    scanf("%d",&seat);
                                    if(seat>9 || seat<=0)
                                    {
                                        printf("Enter valid seat number\n");
                                        j--;
                                    }
                                    else
                                    {
                                        if(seats[4][seat]!='O')
                                        seats[4][seat]='O';
                                        else
                                        {
                                            printf("The seat is occupied, choose another one\n");
                                            j--;
                                        }
                                    }
                                }
                                else if(row=='F')
                                {
                                    printf("Enter which seat you want:  ");
                                    scanf("%d",&seat);
                                    if(seat>9 || seat<=0)
                                    {
                                        printf("Enter valid seat number\n");
                                        j--;
                                    }
                                    else
                                    {
                                        if(seats[5][seat]!='O')
                                        seats[5][seat]='O';
                                        else
                                        {
                                            printf("The seat is occupied, choose another one\n");
                                            j--;
                                        }
                                    }
                                }
                                else if(row=='G')
                                {
                                    printf("Enter which seat you want:  ");
                                    scanf("%d",&seat);
                                    if(seat>9 || seat<=0)
                                    {
                                        printf("Enter valid seat number\n");
                                        j--;
                                    }
                                    else
                                    {
                                        if(seats[6][seat]!='O')
                                        seats[6][seat]='O';
                                        else
                                        {
                                            printf("The seat is occupied, choose another one\n");
                                            j--;
                                        }
                                    }
                                }
                                else if(row=='H')
                                {
                                    printf("Enter which seat you want:  ");
                                    scanf("%d",&seat);
                                    if(seat>9 || seat<=0)
                                    {
                                        printf("Enter valid seat number\n");
                                        j--;
                                    }
                                    else
                                    {
                                        if(seats[7][seat]!='O')
                                        seats[7][seat]='O';
                                        else
                                        {
                                            printf("The seat is occupied, choose another one\n");
                                            j--;
                                        }
                                    }
                                }
                                else if(row=='I')
                                {
                                    printf("Enter which seat you want:  ");
                                    scanf("%d",&seat);
                                    if(seat>9 || seat<=0)
                                    {
                                        printf("Enter valid seat number\n");
                                        j--;
                                    }
                                    else
                                    {
                                        if(seats[8][seat]!='O')
                                        seats[8][seat]='O';
                                        else
                                        {
                                            printf("The seat is occupied, choose another one\n");
                                            j--;
                                        }
                                    }
                                }
                                else if(row=='J')
                                {
                                    printf("Enter which seat you want:  ");
                                    scanf("%d",&seat);
                                    if(seat>9 || seat<=0)
                                    {
                                        printf("Enter valid seat number\n");
                                        j--;
                                    }
                                    else
                                    {
                                        if(seats[9][seat]!='O')
                                        seats[9][seat]='O';
                                        else
                                        {
                                            printf("The seat is occupied, choose another one\n");
                                            j--;
                                        }
                                    }
                                }
                                else//if there is no row for the inputted value
                                {
                                     printf("Invalid row... enter again\n\n");
                                     j--;
                                }

                            }
                            dequeue(t);//removing the person from the queue after the transaction
                        }
                    }
                    break;

            case 5: printf("--------------------    THANKYOU!!!    --------------------\n------------------    End Of Program    -------------------");
                    printf("\nName: Sparsh Palkhiwala\nRoll Number: 19bec127\n\n");
                    d--;//for breaking while loop of the switch
                    break;

            default: printf("Invalid choice\n");
        }
    }
}
