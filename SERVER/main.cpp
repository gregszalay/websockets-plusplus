#include "include/HELLO/Hello.h"
#include <WS_CORE/include/SERVERSTUFF/ServerStuff.h>

int main(int argc, char *argv[])
{
    Hello hi;
    hi.print();
    ServerStuff stuff;
    stuff.print();
    return 0;
}
