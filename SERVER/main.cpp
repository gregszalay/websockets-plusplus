#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::tcp;

int main(int argc, char *argv[])
{
    try
    {
        boost::asio::io_context io_ctx;

        tcp::acceptor acceptor(io_ctx, tcp::endpoint(tcp::v4(), 1337));

        while (1)
        {
            std::cout << "Accepting connections on port 1337!\n";

            tcp::socket socket(io_ctx);
            acceptor.accept(socket);

            std::cout << "Client connected, sending message...\n";

            std::string hello_message = "Hello beautiful client!\n";
            boost::system::error_code error;

            boost::asio::write(socket, boost::asio::buffer(hello_message), error);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
