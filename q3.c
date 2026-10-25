#include<stdio.h>
int main() {
    int stock[3][4];

    for(int i = 0; i < 3; i++) {
        printf("\nAisle %d: ",i+1);
        for(int j = 0; j < 4; j++) {
            printf("Shelf Position %d : ", j+1);
            scanf("%d", &stock[i][j]);
        }
    }

    printf("\nOriginal Stock");
    int highest_unit = 0;
    int running_unit = 0;
    int index = 0;

    for(int i = 0; i < 3; i++) {
        printf("\nAisle %d: ",i+1);
        running_unit = 0;
        for(int j = 0; j < 4; j++) {
            printf("\t%d",stock[i][j]);
            running_unit += stock[i][j];
        }

        if(running_unit>highest_unit) {
            highest_unit = running_unit;
            index = i;
        }
    }

    printf("\nAisle With Most Stock: Aisle %d (%d units)", index+1,highest_unit);

    int emp_shelf = 0;
    printf("\nLow Stock Alerts");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            if(stock[i][j] == 0) {
                emp_shelf++;
            }
            if(stock[i][j] < 5) {
                printf("\nAisle %d, postion %d -> %d units",i+1,j+1,stock[i][j]);
                stock[i][j] += 10;
            }
            
        }
    }

    printf("\nEmpty Shelves : %d", emp_shelf);

    int grand_total_units = 0;
    printf("\nStock After restocking\n");
    for(int i = 0; i < 3; i++) {
        printf("\nAisle %d : ", i+1);
        for(int j = 0; j < 4; j++) {
            printf("\t%d", stock[i][j]);
            grand_total_units += stock[i][j];
        }
    }

    printf("\nNew Grand Total : %d", grand_total_units);

    return 0;
}