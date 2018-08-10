#include <stdio.h>

int main()
{
    int stt;
    printf("Hello...!");
    printf("How're you today?\r\n [1] I'm OK\r\n [2] I'm not OK\r\n");

    scanf("\t\t%d", &stt);
    
    if (stt == 1) {
        printf("Have a good day...!\r\n");
    }
    else
    {
        printf("Fuck you...!\r\n");
    }
    return 0;
}