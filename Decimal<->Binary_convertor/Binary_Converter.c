#include <stdio.h>
#include<math.h>
void separateDigits(int number,int *A,int digits);

int main() {
    int input;
    char exit;
    A:
    printf("Choose what conversion you want to perform : \n");
    printf("1) Binary to decimal\n2) Decimal to binary : ");
    scanf("%d",&input);
    if(input==1){
        goto B;
    }
    else if(input==2){
        goto C;
    }
    else{
        printf("Wrong input please enter 1 or 2\n");
        goto A;
    }
    
    B:{
    int binary,fix_binary,weight,number=0; 
    printf("Enter the binary number : ");
    scanf("%d",&binary);
    int temp = binary;
    fix_binary = binary;

    // Calculates the number of digits in the number
    int digits = 0;
    while (temp != 0) {
        temp /= 10;
        digits++;
    }

    int A[digits];                          // Array to hold the digits.
    separateDigits(binary,A,digits);
    //Loop to check if user entered a perfect binary number or not
    for(int i=0; i<digits; i++){
        if(A[i]>1 || A[i] < 0){
            printf("------------------------------------------\n");
            printf("The given input is not a binary number\n");
            printf("__________________________________________\n");
            goto A;
        }
    }
    for (int i = (digits-1); i>=0; i--)
    {
        weight = pow(2,(digits-i-1));
        number += weight*A[i];
    }
    printf("Decimal of %d is : ",fix_binary);
    printf("%d",number);
    printf("\nEnter 'C' to continue or 'e' to exit : ");
    scanf("%s",&exit);
    if(exit == 'c' || exit == 'C'){
        goto A;
    }
    else{
    return 0;
    }
    }

    C:{
    int B[32];
    int num,fix_num;
    printf("Enter the number : ");
    scanf("%d",&num);
    int tempr = num;
    fix_num = num;
    int i = 0;
    while(num>0){
        tempr = num%2;
        B[i] = tempr;
        num /= 2;
        i++;
    }
    int count = i;
    printf("Binary of %d is : ",fix_num);
    for(int i = (count-1); i>=0; i--){
        printf("%d\t",B[i]);
    }
    printf("\nEnter 'C' to continue or 'e' to exit : ");
    scanf("%s",&exit);
    if(exit == 'c' || exit == 'C'){
        goto A;
    }
    else{
    return 0;
    }
    }

}
void separateDigits(int number,int *A,int digits){
    // Handle zero case
    if (number == 0) {
        printf("0\n");
        return;
    }
    for(int i=(digits-1); i>=0; i--){
        A[i] = number%10;
        number /= 10;
    }

}

