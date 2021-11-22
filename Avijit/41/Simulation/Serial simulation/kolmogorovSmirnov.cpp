#include<stdio.h>
#include <time.h>
#include<algorithm>

int i, tCase;
float input[100], DPlus, DMinus, temp1, temp2;
bool flag1 = true, flag2 = true;

int main()
{
    printf("Number of test case : ");
    scanf("%d", &tCase);
    srand(time(NULL));
    for(i=0; i<tCase; i++)
        input[i] = (float)(rand()%100)/100;//scanf("%f", &input[i]);

    for(i=0; i<tCase; i++)
        printf("%.2f ", input[i]);
    printf("\n");

    std::sort(input, input + tCase);

    for(i=0; i<tCase; i++)
        printf("%.2f ", input[i]);

    for(i=0; i<tCase; i++)
    {
        temp1 = (float)(i+1) / (float)tCase - input[i];
        temp2 = input[i] - (float)i / (float)tCase;
        //printf("\n%.2f %.2f", temp1, temp2);
        if(flag1)
        {
            DPlus = temp1;
            flag1 = false;
        }
        else if(DPlus < temp1)
            DPlus = temp1;
        if(flag2)
        {
            DMinus = temp2;
            flag2 = false;
        }
        else if(DMinus < temp2)
            DMinus = temp2;
    }

    printf("\nD+ = : %.2f \nD- = %.2f", DPlus, DMinus);

    return 0;
}
