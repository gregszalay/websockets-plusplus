

#include "TCPConnection.h"
#include <iostream>

namespace GREG
{

    TCPConnection::TCPConnection(boost::asio::io_context &ioContext) : _socket(ioContext) {}

    void TCPConnection::Start()
    {
        auto strongThis = shared_from_this();
        boost::asio::async_write(_socket, boost::asio::buffer(_message),
                                 [strongThis](const boost::system::error_code &error, uint64_t bytes_transferred)
                                 {
                                     if (error)
                                     {
                                         std::cout << "Failed to send message\n";
                                     }
                                     else
                                         std::cout << "Sent " << bytes_transferred << " bytes of data\n";
                                 });

        boost::asio::streambuf buf;
        _socket.async_receive(buf.prepare(512),
                              [this](const boost::system::error_code &error, size_t bytes_transferred)
                              {
                                  if (error == boost::asio::error::eof)
                                  {
                                      std::cout << "Client disconnected properly! \n";
                                  }
                                  else if (error)
                                  {
                                      std::cout << "Client disconnected in a bad way! \n";
                                      throw boost::system::system_error(error);
                                  }
                              });
    }
};