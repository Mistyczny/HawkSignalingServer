//
// Created by admin on 7/13/2022.
//

#include <Hawk/Net/WebSocketConnection.hpp>
#include <Hawk/Net/WebSocketUtils.hpp>
#include <iostream>

namespace Hawk::Net
{
    WebSocketConnectionPtr WebSocketConnection::Create(drogon::WebSocketConnectionPtr pWebSocketConnection)
    {
        return std::make_shared<WebSocketConnection>(std::move(pWebSocketConnection));
    }

    WebSocketConnection::WebSocketConnection(drogon::WebSocketConnectionPtr pWebSocketConnection)
        : m_pWebSocketConnection{std::move(pWebSocketConnection)}
    {
        std::cout << "WebSocketConnection::WebSocketConnection" << std::endl;
    }

    WebSocketConnection::~WebSocketConnection()
    {
        std::cout << "WebSocketConnection::~WebSocketConnection" << std::endl;
    }

    bool WebSocketConnection::Send(std::string message)
    {
        std::cout << "HELLO" << std::endl;
        if (message.empty())
        {
            std::cout << "Provided message is empty" << std::endl;
            return false;
        }

        if (!m_pWebSocketConnection)
        {
            std::cout << "WebSocketConnection is not initialized" << std::endl;
            return false;
        }

        m_pWebSocketConnection->send(message);

        return true;
    }

    bool WebSocketConnection::SetContext(std::shared_ptr<void> pContext)
    {
        if (!pContext)
        {
            std::cout << "Provided context is nullptr" << std::endl;
            return false;
        }

        if (!m_pWebSocketConnection)
        {
            std::cout << "WebSocketConnection is not initialized" << std::endl;
            return false;
        }

        m_pWebSocketConnection->setContext(pContext);

        return true;
    }

    bool WebSocketConnection::HasContext()
    {
        return m_pWebSocketConnection->hasContext();
    }

    std::shared_ptr<void*> WebSocketConnection::GetContext()
    {
        return m_pWebSocketConnection->getContext<void*>();
    }

    void WebSocketConnection::Shutdown(CloseCode closeCode, std::string message)
    {
        if (!m_pWebSocketConnection)
        {
            std::cout << "WebSocketConnection is not initialized" << std::endl;
            return;
        }

        m_pWebSocketConnection->shutdown(TranslateCloseCode(closeCode), message);
    }
}