#include "TCPServer.h"
#include <iostream>

namespace GREG
{
    using boost::asio::ip::tcp;
    TCPServer::TCPServer(IPv ipv, int port) : _ipVersion(ipv), _port(port),
                                              _acceptor(tcp::acceptor(_ioContext, tcp::endpoint(_ipVersion == IPv::V4 ? tcp::v4() : tcp::v6(), port)))
    {
    }

    int TCPServer::Run()
    {
        try
        {
            startAccept();
            _ioContext.run();
        }
        catch (const std::exception &e)
        {
            return -1;
            std::cerr << e.what() << '\n';
        }
        return 0;
    }

    void TCPServer::startAccept()
    {
        // Create a connection
        auto connection = TCPConnection::Create(_ioContext);
        _connections.push_back(connection);

        // asynchronously accept a connection
        _acceptor.async_accept(connection->Socket(),
                               [connection, this](const boost::system::error_code &error)
                               {
                                   std::cout << "Client connected! Starting new tcp connection \n";
                                   if (error.value() == boost::system::errc::success)
                                   {
                                       connection->Start();
                                   }
                                   startAccept();
                               });
        
    }

} // namespace GREG
