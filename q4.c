#include<stdio.h>
int main() {
    int beds[2][3][2] = {
        {
            {0,0},
            {0,0},
            {0,0}
        } ,
        {
            {0,0},
            {0,0},
            {0,0}
        }
    };

    int choice = 0;

    while(choice != 4) {
        printf("\n1. ADMIT");
        printf("\n2. DISCHARGE");
        printf("\n3. Report");
        printf("\n4. Exit");
        printf("\nChoice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int floor;
            printf("\nEnter Floor : ");
            scanf("%d", &floor);

            int patientID;
            printf("\nEnter Patient ID : ");
            scanf("%d", &patientID);

            if (floor < 1 || floor > 2 || patientID == 0) {
                printf("Invalid floor or patient ID.\n");
                break;
            }
            int isAdmitted = 0; 

            for(int i = 0; i < 3 && isAdmitted == 0; i++) {
                for(int j = 0; j < 2; j++) {
                    if(beds[floor-1][i][j] == 0) {
                        beds[floor-1][i][j] = patientID;
                        isAdmitted = 1;
                        printf("Patient %d admitted successfully: Ward: %d, Bed: %d\n",patientID, i + 1, j + 1);
                        break;
                    }
                }
            }

            if(isAdmitted == 0) {
                printf("Floor %d is full.\n", floor);
            }

        break;

        case 2:
            int patiendID;
            printf("\nEnter patien ID : ");
            scanf("%d", &patiendID);

            int found = 0;
            for(int i = 0; i < 2 && found == 0; i++) {
                for(int j = 0; j < 3 && found == 0; j++) {
                    for(int k = 0; k < 2; k++) {
                        if(beds[i][j][k] == patiendID) {
                            beds[i][j][k] = 0;
                            printf("Patient %d discharged from floor %d, Watd %d, Bed %d", patiendID, i+1,j+1,k+1);
                            found = 1;
                            break;
                        }
                    }
                }
            } 

            if(found == 0) {
                printf("\nPatient ID %d Not found", patiendID);
            }
        break;
        
        case 3:

            int vacant = 0;
            int occupied = 0;
            int count = 0;
            float floorOccupancy;
            int highest_floor = -1;
            int ward = -1;
            int highestOccupancy = 0;
            int isValid = 0;


            for(int i = 0; i < 2; i++) {
                printf("\nFloor %d", i+1);
                for(int j = 0; j < 3; j++) {
                    printf("\n\tWard %d: ", j + 1);
                    for(int k = 0; k < 2; k++) {
                        if(beds[i][j][k] == 0) {   
                            vacant++;
                        } else {
                            occupied++;
                            count++;
                        }

                    } 
                    if(occupied>highestOccupancy) {
                            isValid = 1;
                            highestOccupancy = occupied;
                            ward = j;
                            highest_floor = i;
                    }
                    printf("Occupied %d, Vacant %d", occupied,vacant);
                    occupied = 0;
                    vacant = 0;
                }
                floorOccupancy = (count/6.0) * 100;
                printf("\n\tFloor Occupancy : %.1f", floorOccupancy);

                if(floorOccupancy > 80) {
                    printf("\nWARNING: Floor %d is more than 80%%  full\n", i + 1);
                }
                count = 0;
                
            }
            if(isValid ==1) {
                printf("\nHighest Occupancy : Floor %d, Ward %d (%d occupied)", highest_floor + 1,ward+1,highestOccupancy);
            } else {
                printf("\nNo patients are there");
            }
        break;

        case 4:
            printf("\nExiting the program");
            break;
        default:
            printf("\nInvalid Choice");
            break;
        }
    }
    return 0;
}