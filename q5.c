#include<stdio.h>
int main(){
    int image[4][4];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            do {
                printf("Enter [%d, %d] element pixel : ", i+1,j+1);
                scanf("%d", &image[i][j]);

                if(image[i][j] < 0 || image[i][j] > 255) {
                    printf("\nInvalid Value entered.");
                }
            } while(image[i][j] < 0 || image[i][j] > 255);
        }
    }
    int brightness;
    int threshold;


    printf("\nEnter Brightness value : ");
    scanf("%d", &brightness);


    do {
        printf("Enter threshold (0-255): ");
        scanf("%d", &threshold);

        if(threshold < 0 || threshold > 255) {
            printf("Invalid threshold!\n");
        }
    } while(threshold < 0 || threshold > 255);

    printf("\nOriginal Image\n\t");

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d  ",image[i][j]);
        }
        printf("\n\t");
    }

    
    printf("\nBrightness (+%d) : \n\t", brightness);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int pixel = image[i][j] + brightness;
            if(pixel>255) {
                pixel = 255;
            } else if(pixel < 0) {
                pixel = 0;
            } 
            printf("%d  ", pixel);
        }
        printf("\n\t");
    }

    printf("\nBlack And white (threshold %d) : \n\t", threshold);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(image[i][j] >= threshold) {
                printf("%3d ", 255);
            } else {
                printf("%3d ", 0);
            }
        }
        printf("\n");
    }
    int flipped[4][4];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            flipped[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            int temp = flipped[i][j];
            flipped[i][j] = flipped[i][3-j];  
            flipped[i][3-j] = temp;

        }
    }
    printf("\nFlip Horizontally\n\t");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d  ", flipped[i][j]);
        }
        printf("\n\t");
    }

    int result[4][4];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            result[i][j] = image[i][j];
        }
    }

    for(int i = 1; i <3; i++) {
        for(int j = 1; j < 3; j++) {
            int sum = 0;
            for(int x = i-1; x <= i+1; x++) {
                for(int y = j-1; y <= j+1; y++) {
                    sum += image[x][y];
                }
            }
            result[i][j] = sum/9;
        }
    }

    printf("\nSmooth Image\n\t");
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%d  ",result[i][j]);
        }
        printf("\n\t");
    }

    printf("\nIf we do not make copy of image and does everything in image then the image does not get smoothed becase in each time we will modifying the certain pixels which causes affect on different pixels making the calculation un standardize and different");
    return 0;
}