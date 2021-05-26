#include <stdio.h>
#include <sys/boardctl.h>

#include "HelloWorld.h"

extern "C"
{
int spresense_main(void)
{
    boardctl(BOARDIOC_INIT, 0);

    CHelloWorld *pHelloWorld = new CHelloWorld();
    pHelloWorld->HelloWorld();

    CHelloWorld helloWorld;
    helloWorld.HelloWorld();

    delete pHelloWorld;

    printf("Hello world\r\n");
    return 0;
}
}
