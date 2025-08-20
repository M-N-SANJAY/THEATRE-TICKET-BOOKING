#include <stdio.h>

int theatre[5][10];

void seatbooking(int row,int col){
    if(theatre[row][col]==1){
        printf("\nSeat at row %d col %d is already booked, unable to book",row,col);
        return;
    }
    theatre[row][col]=1;
    printf("\nSuccessfully booked your seat at row %d col %d",row,col);
}

void seatcancel(int row,int col){
    if(theatre[row][col]==0){
        printf("\nSeat at row %d col %d is not pre-booked, unable to cancel",row,col);
        return;
    }
    theatre[row][col]=0;
    printf("\nSuccesfully un-booked your seat at row %d col %d",row,col);
}

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
    printf("\nThere are total of %d seats currently available",count);
}

void main() {
    int i,j,row,col,choice;
    for(i=0;i<5;i++){
        for(j=0;j<10;j++){
            theatre[i][j]=0;
        }
    }
    printf("THEATRE STRUCTURE:-\nROWS = 5\nCOLUMNS = 10");
    printf("\n\nChoices Available:-\n1.Book Seat\n2.Cancel Seat Booking\n3.Check Seat Availability\n4.Exit");
    while(1){
        printf("\nEnter your choice:");
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
            break;
        }
    }
}
