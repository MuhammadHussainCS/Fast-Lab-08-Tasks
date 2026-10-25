#include<stdio.h>

int main(){
    int seats[5][6] = {
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
    };
    int row = 0, col;
    
    while(row != -1) {
        do {
            printf("\nEnter row number : (1 - 5) : ");
            scanf("%d", &row);

            if(row == -1) {
                printf("\nExiting the booking program");
                break;
            } else {
                if(row<1 || row>5) {
                printf("\nInvalid row Number Entered");
                }
            }
        } while(row<1 || row>5);

        if(row != -1) {
            do {
                printf("\nEnter col number : (1 - 6) : ");
                scanf("%d", &col);

                if(col<1 || col>6) {
                    printf("\nInvalid col Number Entered");
                }

            } while(col<1 || col>6);

            if(seats[row-1][col-1] == 1) {
                printf("\nError : Seat already booked!");
            } else {
                seats[row-1][col-1] = 1;
                printf("\nSeat Booked successfully");
            }
        }

    }

    int emp_seats = 0;
    int booked_seats = 0;
    int cur_booked = 0;
    int highest_row_occupancy = 0; 
    int index = -1;
    printf("\nSeating Chart\n");
    printf("\t\n");

    for(int i = 1; i < 7; i++) {
       printf("\t%d",i);
    }

    printf("\n");
    for(int i = 0; i < 5; i++) {
        printf("Row %d  ", i+1);
        for(int j = 0; j < 6; j++) {
            if(seats[i][j] == 0) {
                printf(" O      ");
                emp_seats++;
            } else {
                booked_seats++;
                cur_booked++;
                printf(" X      ");
            }
        }
        printf("\n");
        if(cur_booked > highest_row_occupancy) {
            highest_row_occupancy = cur_booked;
            index = i;
        }
        cur_booked=0;
    }

    printf("\nTotal Booked Seats : %d",booked_seats);
    printf("\nTotal Empty Seats : %d",emp_seats);
    if(index == -1) {
        printf("\nNo row contains any booking");
    } else {
        printf("\nRow with most Bookings : Row %d", index+1);
    }
    return 0;
}