#include<stdio.h>
void calculat();

int tCase, i, j;
float paperCost[100], paperPrice[100], paperBundleSize[100], paperBuy[100], paperSale[100];
float salvage, profit, netProfit = 0;
char paperName[100][20];

int main()
{
    printf("Number of paper : ");
    scanf("%d", &tCase);
    for(i=0; i<tCase; i++)
    {
        printf("Paper Name : ");
        scanf("%s", &paperName[i]);
        printf("Paper Cost : ");
        scanf("%f", &paperCost[i]);
        printf("Paper Price : ");
        scanf("%f", &paperPrice[i]);
        printf("Bundle Size : ");
        scanf("%f", &paperBundleSize[i]);
        printf("Bundle Bought : ");
        scanf("%f", &paperBuy[i]);
        paperBuy[i] = paperBuy[i] * paperBundleSize[i];
        printf("Paper Sold : ");
        scanf("%f", &paperSale[i]);
        calculat();
    }

    netProfit = 0;
    for(i=0; i<tCase; i++)
    {
        calculat();
    }
    printf("----------------\n----------------\nNet profit: %.2f\n\n", netProfit);
    return 0;
}

void calculat()
{
    printf(" \t %s \n", paperName[i]);
    printf("Number of Paper Buy : %d\n", (int)paperBuy[i]);
    printf("Number of Paper Sale : %d\n", (int)paperSale[i]);
    salvage = paperBuy[i] - paperSale[i];
    salvage *= 0.05;
    profit = (paperSale[i] * paperPrice[i]) - (paperBuy[i] * paperCost[i]) + salvage;
    netProfit += profit;
    printf("paperSale : %.2f \npaperBuy  :-%.2f \nsalvage   : %.2f \n----------------\nprofit    : %.2f\n\n", (paperSale[i] * paperPrice[i]), (paperBuy[i] * paperCost[i]), salvage, profit);
}
