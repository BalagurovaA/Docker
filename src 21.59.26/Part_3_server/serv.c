#include "fcgi_stdio.h"
#include <stdlib.h>

int main(void)
{
    while(FCGI_Accept() >= 0)
    {
        printf("Content-type: text/html\r\nStatus: 200 oK\r\n\r\n");
        printf("Hello, World!\n");
        printf("<pre>\n");
        printf("-----------------------------\n");
        printf("| *     *     *     *     * |\n");
        printf("|    +     +     +     +    |\n");
        printf("|                           |\n");
        printf("| +    K R I S T O F S    + |\n");
        printf("|                           |\n");
        printf("|    +     +     +     +    |\n");
        printf("| *     *     *     *     * |\n");
        printf("-----------------------------\n");
        printf("<pre>\n");
    }

    return 0;
}


