#include <WS_CORE/include/SERVER/TCPServer.h>

int main(int argc, char *argv[])
{
    GREG::TCPServer server{GREG::IPv::V4, 1337};

    server.Run();
    return 0;
}
