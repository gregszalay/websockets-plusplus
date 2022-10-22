#pragma once

#include <boost/asio.hpp>
#include <functional>
#include "TCPConnection.h"

namespace GREG
{

    enum class IPv
    {
        V4,
        V6,
    };

    class TCPServer
    {
    public:
        TCPServer(IPv ipv, int port);
        int Run();

        template <typename T>
        void WriteToConnection(int connectionIndex, const T &message);

        template <typename T>
        using ListenCallback = std::function<void(const T &)>;

        template <typename T>
        void RegisterListenCallback(ListenCallback<T> callback);

    private:
        void startAccept();

    private:
        IPv _ipVersion;
        int _port;

        boost::asio::io_context _ioContext;
        boost::asio::ip::tcp::acceptor _acceptor;

        std::vector<TCPConnection::pointer> _connections{};
    };
};