#include<stdio.h>
#include<string.h>

#define SUBJECT_COUNT 3
#define NO_OF_STDS 4

int main() {
    float marks[NO_OF_STDS][SUBJECT_COUNT];
    float all_std_avg[NO_OF_STDS];
    float all_std_total[NO_OF_STDS];
    char all_std_grade[NO_OF_STDS][1];
    float std_total;
    float std_avg;

    float prog_highest = 0;
    float calc_highest = 0;
    float phy_highest = 0;

    float prog_lowest = 100;
    float cal_lowest = 100;
    float phy_lowest = 100;

   
    float calc_total = 0; 
    float calc_avg;

    float prog_total = 0;
    float prog_avg;

    float phy_avg;
    float phy_total = 0;

    for(int i = 0; i < 4; i++) {
        std_total = 0;
        std_avg = 0;
        for(int j = 0; j < 3; j++) {
            do {
                printf("\nEnter student %d in subject %d : ", i+1,j+1);
                scanf("%f", &marks[i][j]);

                if(marks[i][j] < 0 || marks[i][j] > 100) {
                    printf("\nInvalid Marks[!]");
                } else {
                    std_total += marks[i][j];

                    if(j == 0) {
                        if(marks[i][j] > prog_highest) {
                            prog_highest = marks[i][j];
                        }

                        if(marks[i][j] < prog_lowest) {
                            prog_lowest= marks[i][j];
                        }
                        prog_total += marks[i][j];
                    }

                    if(j == 1) {
                        if(marks[i][j] > calc_highest) {
                            calc_highest = marks[i][j];
                        }

                        if(marks[i][j] < cal_lowest) {
                            cal_lowest= marks[i][j];
                        }
                        calc_total += marks[i][j];
                    }

                    if(j == 2) {
                        if(marks[i][j] > phy_highest) {
                            phy_highest = marks[i][j];
                        }

                        if(marks[i][j] < phy_lowest) {
                            phy_lowest = marks[i][j];
                        }

                        phy_total += marks[i][j];
                    }
                }
            } while(marks[i][j] < 0 || marks[i][j] > 100);

        }

        

        
        std_avg = std_total/SUBJECT_COUNT;
        all_std_avg[i] = std_avg;
        all_std_total[i] = std_total;
        switch ((int)std_avg)
        {
        case 80 ... 100:
            all_std_grade[i][1] = 'A';
            break;
        case 65 ... 79:
            all_std_grade[i][1] = 'B';
            break;
        case 50 ... 64:
            all_std_grade[i][1] = 'C';
            break;
        default:
            all_std_grade[i][1] = 'F';
            break;
        }
    }
        
    calc_avg = calc_total/NO_OF_STDS;
    prog_avg = prog_total/NO_OF_STDS;
    phy_avg = phy_total/NO_OF_STDS;
    float sub_avg[3] = {prog_avg,calc_avg,phy_avg};

    printf("\nStudent \tProg \tCalc\tPhys \tTotal \tAverage  \tGrade");
    for(int i = 0; i < 4; i++) {
        printf("\nStudent %d\t", i+1);
        for(int j = 0; j < 3; j++) {
            printf("%.2f\t", marks[i][j]);
        }
        printf("%.2f\t%.2f",all_std_total[i], all_std_avg[i]);
        printf("\t\t%c",all_std_grade[i][1]);
    }

    printf("\n\nSubject Statistics:");
    char sub_names[SUBJECT_COUNT][20] = {
        "Programming",
        "Calculus",
        "Physics"
    };

    printf("\nSubject\t\tHighest\tLowest\t Average\n");
    for(int i = 0; i < 3; i++) {
        if(i == 0) {     
            printf("%s\t %.2f\t %.2f\t %.2f\n",sub_names[i],prog_highest,prog_lowest,prog_avg);
        }
        if(i == 1) {     
            printf("%s\t %.2f\t %.2f\t %.2f\n",sub_names[i],calc_highest,cal_lowest,calc_avg);
        }if(i == 2) {     
            printf("%s\t \t%.2f\t %.2f\t %.2f\n",sub_names[i],phy_highest,phy_lowest,phy_avg);
        }
    }


    int worst_avg_index = 0;
    float worst_avg = sub_avg[0];

    int top_std_index = 0;
    float top_std_avg = all_std_avg[0];

    for(int i = 1; i < 4; i++) {
        
        if(all_std_avg[i] > top_std_avg) {
            top_std_avg = all_std_avg[i];
            top_std_index = i;
        }        
    }

    for(int i = 1; i < 3; i++) {
        if(sub_avg[i] < worst_avg) {
            worst_avg = sub_avg[i];
            worst_avg_index = i;
        }
    }


    printf("\nWorst Subject : %s (Average %.2f)",sub_names[worst_avg_index], worst_avg);
    printf("\nTop Student %d : (Average %.2f)", top_std_index+1, top_std_avg);
    
    return 0;
}