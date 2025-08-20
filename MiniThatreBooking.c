#include <stdio.h>

//initialising the theatre multi dimensional array with 5 rows and 10 columns
int theatre[5][10];

//function to books seat using row and column
void seatbooking(int row,int col){
    //converting 1-based indexing row,col to 0-based indexing
    if(theatre[row-1][col-1]==1){       
        printf("\nSeat at row %d col %d is already booked, unable to book",row,col);  //Pre-Booked
        return;
    }
    theatre[row-1][col-1]=1;  //Booking                       
    printf("\nSuccessfully booked your seat at row %d col %d",row,col);
}

//function to cancel pre-booked seat
void seatcancel(int row,int col){
    if(theatre[row-1][col-1]==0){
        // to check whether the seat is already pre-booked first
        printf("\nSeat at row %d col %d is not pre-booked, unable to cancel",row,col);  
        return;
    }
    theatre[row-1][col-1]=0;  //Unbooking
    printf("\nSuccesfully un-booked your seat at row %d col %d",row,col);
}

//checking available seats
void seatavailability(){
    int count=0;
    printf("\nNote: X - booked , O - Not Booked");
    printf("\n\t\t\tTHEATRE");
    for(int i=0;i<5;i++){
        printf("\n\t\t  ");
        for(int j=0;j<10;j++){
            if(theatre[i][j]==0){
                printf("O");
                count++;
            }
            else{
                printf("X");
            }
        }
    }
    //outputting the count of unbooked seats too
    printf("\nThere are total of %d seats currently available",count);
}

void main() {
    
    int i,j,row,col,choice;

    //setting all seats as 0 denoting unbooked, note :- 0 = unbooked, 1 = booked
    for(i=0;i<5;i++){
        for(j=0;j<10;j++){
            theatre[i][j]=0;
        }
    }

    //Menu
    printf("THEATRE STRUCTURE:-\nROWS = 5\nCOLUMNS = 10");
    printf("\n\nChoices Available:-\n1.Book Seat\n2.Cancel Seat Booking\n3.Check Seat Availability\n4.Exit");
    while(1){
        printf("\n\nEnter your choice:");
        scanf("%d",&choice);
        if(choice==1){
            printf("\nEnter row column nos. of your seat: ");
            scanf("%d %d",&row,&col);
            seatbooking(row,col);
        }
        else if(choice==2){
            printf("\nEnter row column nos. of your seat: ");
            scanf("%d %d",&row,&col);
            seatcancel(row,col);
        }
        else if(choice==3){
            seatavailability();
        }
        else{
            break;   //exit
        }
    }
}
