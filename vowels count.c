#include <stdio.h>

int countVowels(char str[], int n) 
{
    int i, count = 0;
    for (i = 0; i < n; i++) 
    {
        if (str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ||
            str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U') {
            count++;
        }
    }
    return count;
}

void printVowelCount(char str[], int count) 
{
    printf("The name %s has %d vowels.\n", str, count);
}

int main() 
{
    char name[100];
    int n, vowels;

    printf("Enter the size of your name: ");
    scanf("%d", &n);

    printf("Enter your name: ");
    scanf("%s", name);  

    vowels = countVowels(name, n);      
    printVowelCount(name, vowels);      

    return 0;
}