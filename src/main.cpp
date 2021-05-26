#include "HelloWorld.h"
#include <nuttx/config.h>
#include <stdio.h>

extern "C"
{
        int hellocpp_main(void)
        {

                // CHelloWorld *pHelloWorld = new CHelloWorld();
                // pHelloWorld->HelloWorld();

                // CHelloWorld helloWorld;
                // helloWorld.HelloWorld();

                // delete pHelloWorld;

                printf("Hello world\r\n");
                return 0;
        }
}