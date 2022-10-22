#pragma once

#include <boost/asio.hpp>

namespace GREG
{
    using boost::asio::ip::tcp;
    class TCPConnection : public std::enable_shared_from_this<TCPConnection>
    {
    public:
        using pointer = std::shared_ptr<TCPConnection>;
        static pointer Create(boost::asio::io_context &ioContext)
        {
            return pointer(new TCPConnection(ioContext));
        }
        tcp::socket &Socket()
        {
            return _socket;
        }
        void Start();

    private:
        TCPConnection(boost::asio::io_context &ioContext);
        tcp::socket _socket;
        std::string _message{"Hello, beautiful client\n"};
    };
};