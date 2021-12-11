#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
struct order{          
    char name[50];
    int order;
    int food_code;
    int cost;
    } odr[1000];

int total_order = 0, order_served = 0; // Global variable

int main ()
{
    printf ("                Simple Food Ordering System             ");
    while (1){
        printf ("\n 1. Order \n 2. Serve \n 3. Display \n 4. Exit the program \n");

        int in;
        scanf ("%d", &in);
        getchar ();
        switch (in){
            case 1 : {
                printf("* * * * * * * * * * * * * *MENU* * * * * * * * * * * *  * *\n");
                printf("Item code   Food                   Size                      Price \n");
                printf("[01]        Burger                 special                   108 \n");
                printf("[02]        Pizza                  small/medium/large        240/320/400 \n");
                printf("[03]        Chicken wings          4pcs/8pcs                 150/250 \n");
                printf("[04]        Maggie                 half/full                 50/90 \n");
                printf("[05]        Coffee                 240ml                     50 \n");
                printf("[06]        Coke                   250ml/500ml               35/60 \n");
                order ();
                break;
            }
            case 2 : {
                receive();
                break;
            }
            case 3 : {
                display();
                break;
            }
            case 4 : {
                exit (0);
            }
        }
    }
}

int order ()   //This function will take your order - (name, how many item you require, ask for item code, size(if there is), quantity of perticular item) and print total
{
    int n, in, qu;
    printf ("please enter your name: ");
    gets (odr[total_order].name);
    odr[total_order].order = 100+total_order;
    odr[total_order].food_code = n;
    odr[total_order].cost = 0;
    odr[total_order].food_code = 0;
    
    Marker:
    printf ("How many items you want to order? ");
    scanf ("%d", &n);

    getchar ();
    while (n--){
        printf ("\nEnter chosen item code\n");
        scanf ("%d", &in);
        getchar();
        switch(in){
    case 01 : {
        printf ("Burger \n");
        printf ("Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        odr[total_order].food_code +=qu;
        odr[total_order].cost += (108*qu);
        break;
    }
    case 02 :{
        printf ("Pizza: 1. small  2. medium  3. large \n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        odr[total_order].food_code +=qu;
        if (i==1) odr[total_order].cost += (240*qu);
        else if (i==2) odr[total_order].cost += (320*qu);
        else  odr[total_order].cost += (400*qu);
        break;
    }
    case 03 :{
        printf ("Chicken wings: 1. 4pcs  2. 8pcs \n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        odr[total_order].food_code +=qu;
        if (i==1) odr[total_order].cost += (150*qu);
        else odr[total_order].cost += (250*qu);
        break;
    }
    case 04 :{
        printf ("Maggie: 1. half  3. full \n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        odr[total_order].food_code +=qu;
        if (i==1) odr[total_order].cost += (50*qu);
        else  odr[total_order].cost += (90*qu);
        break;
    }
    case 05 :{
        printf ("Coffee\n");
        printf ("Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        odr[total_order].food_code +=qu;
        odr[total_order].cost += (50*qu);
        break;
    }
    case 06 :{
        printf ("Coke: 1. 250ml  2. 500ml \n");
        int i;
        scanf ("%d", &i);
        getchar();
        printf ("Please enter the quantity: ");
        scanf ("%d", &qu);
        getchar();
        odr[total_order].food_code +=qu;
        if (i==1) odr[total_order].cost += (35*qu);
        else odr[total_order].cost += (60*qu);

        break;
    }
    default : {
        printf ("ERROR\n");
        n++;
    }
        }
    }
    char temp;
    printf ("Do you want to order anything else? (y/n)\n ");
    scanf("%c", &temp);
    if (temp == 'y' || temp == 'Y')
        goto Marker;
    printf ("\nNumber of food ordered %d\n", odr[total_order].food_code);
    printf ("\nThank you %s for your order. \nYour bill is %d Rupees.\nPlease wait while we prepare the food.\n\n", odr[total_order].name, odr[total_order].cost);
    total_order ++;
}
int receive ()   //give order to the customer and keep a record
{
    if (total_order==0){
        printf ("Please order first\n");
        return;
    }

    else if (order_served == total_order) {
        printf ("No pending order\n");
        return;
    }

    printf ("Order no. %d by %s is ready\n", odr[order_served].order, odr[order_served].name);
    printf ("Enjoy your meal\n\n");
    order_served++;
}
int display ()  //displaying total order taken, order served, pending orders, 
{
    printf ("Total order taken: %d\n", (total_order));
    printf ("Total number of order served %d\n", order_served);
}
