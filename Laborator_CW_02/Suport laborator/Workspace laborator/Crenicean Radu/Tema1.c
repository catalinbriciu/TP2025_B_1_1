#include <stdio.h>


unsigned char BitArray[1001]={0};

void AddNumber(short x)
{ 
    BitArray[x/8]=BitArray[x/8]|(1<<(x%8));
}

unsigned char CheckNumber(short x)
{
    if(1&(BitArray[x/8]>>(x%8))) return 1;
    
    return 0;
}
int main()
{
    unsigned char n,i;
    short x;

    printf("Cate elemente secitesc: ");
    scanf("%u",&n);

    printf("Acum introducem numerele intre 0-1000\n");
    for(i=0;i<n;i++)
        {
            scanf("%s",&x);
            AddNumber(x);
        }
    
    printf("Acum verificam daca numerele sunt in multime\n");
    while(1)
    {
        scanf("%s",&x);
        if(CheckNumber(x))
        printf("Numarul este in multime\n");
        else printf("Numarul nu este in multime\n");
        
        if(x<0 || x>1000)
        {
            printf("Numarul nu este in limite, programul s-a incheiat");
            break;
        }
    }


    return 0;
}