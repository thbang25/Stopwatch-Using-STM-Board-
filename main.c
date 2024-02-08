//thabang sambo
//EEE2050/46F
//PRACTICAL 3

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

// GLOBAL VARIABLES
//====================================================================
char binaryNum[20]="";

//====================================================================
// MAIN FUNCTION
//====================================================================
char* Dec2Radix(int decValue, int radValue){
    char decVal[17]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','\0'};
    char str[17]="";
    int decHold = decValue;
    int radHold = radValue;
    int cntr = 0;
    int cntRes = 1;
    int RemVal = 0;

    while(cntRes>0){
        cntRes = (decHold/radHold);
        RemVal =round(((decHold/(float)radHold)-cntRes)*radHold);
        sprintf(str,"%c",decVal[RemVal]);
        strcat(binaryNum,str);
        decHold = cntRes;
        cntr++;
    }
    strrev(binaryNum);
    return binaryNum;

}
int main (void){

    int div;
    int num=1;
    int radix=1;
    int rem =1;

    printf("***************************** \n");
    printf(" DECIMAL TO RADIX-i converter \n");
    printf(" Written by: Thabang Sambo \n");
    printf(" Date: April 2023 \n");
    printf("***************************** \n");
    while(num>0&&radix>0){
    printf("Enter a decimal number: ");
    scanf("%d", &num);

    if(num<0){
            break;
    }

    printf("The number you have entered is");
    printf(" %d",num);
    printf("\nEnter a radix for the converter between 2 and 16: ");
    scanf("%d", &radix);

    if(radix<0){
        break;
    }

    printf("The radix you have entered is ");
    printf(" %d",radix);
    unsigned int n = num;
    printf("\nThe log2 of the number is ");
    //printf("%d ",(int)log2(n));
    printf("%4.2f",log2(n));

    div = num/radix;
    printf("\nThe integer result of the number divided by %d is ",radix);
    printf("%d",div);

    rem = num%radix;
    printf("\nThe remainder is ");
    printf("%d\n",rem);

    Dec2Radix(num,radix);

    printf("The radix-%d value is %s\n",radix,binaryNum);
    strcpy(binaryNum,"");
    }
    printf("EXIT");
	return 0;
}							// End of main

//********************************************************************
// END OF PROGRAM
//********************************************************************
