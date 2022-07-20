//
// Created by admin on 7/8/2022.
//

#include "Hawk/Controllers/UsersControllerHandlers/UsersControllerHandlersFactory.hpp"
#include "Hawk/Controllers/UsersControllerHandlers/UsersControllerBinaryHandler.hpp"
#include "Hawk/Controllers/UsersControllerHandlers/UsersControllerCloseHandler.hpp"
#include "Hawk/Controllers/UsersControllerHandlers/UsersControllerNewConnectionHandler.hpp"
#include "Hawk/Controllers/UsersControllerHandlers/UsersControllerPingHandler.hpp"
#include "Hawk/Controllers/UsersControllerHandlers/UsersControllerPongHandler.hpp"
#include "Hawk/Controllers/UsersControllerHandlers/UsersControllerTextHandler.hpp"

namespace Hawk
{
    UsersControllerHandlersFactoryPtr UsersControllerHandlersFactory::Create(UsersManagerPtr pUsersManager,
                                                                             UsersPubSubServicePtr pUsersPubSubService)
    {
        return std::make_unique<UsersControllerHandlersFactory>(std::move(pUsersManager), std::move(pUsersPubSubService));
    }

    UsersControllerHandlersFactory::UsersControllerHandlersFactory(UsersManagerPtr pUsersManager, UsersPubSubServicePtr pUsersPubSubService)
        : m_pUsersManager{std::move(pUsersManager)}
        , m_pUsersPubSubService{std::move(pUsersPubSubService)}
    {}

    IUsersControllerHandlerPtr UsersControllerHandlersFactory::GetOrCreateMessageHandler(drogon::WebSocketMessageType messageType)
    {
        auto it = m_handlersMap.find(messageType);
        if (it != std::end(m_handlersMap))
        {
            return it->second;
        }

        return CreateMessageHandler(messageType);
    }

    IUsersControllerHandlerPtr UsersControllerHandlersFactory::CreateMessageHandler(drogon::WebSocketMessageType messageType)
    {
        IUsersControllerHandlerPtr newHandler{};
        switch (messageType)
        {
            case drogon::WebSocketMessageType::Text:
                newHandler = UsersControllerTextHandler::Create();
                break;
            case drogon::WebSocketMessageType::Binary:
                newHandler = UsersControllerBinaryHandler::Create();
                break;
            case drogon::WebSocketMessageType::Ping:
                newHandler = UsersControllerPingHandler::Create();
                break;
            case drogon::WebSocketMessageType::Pong:
                newHandler = UsersControllerPongHandler::Create();
                break;
            case drogon::WebSocketMessageType::Close:
                newHandler = UsersControllerCloseHandler::Create();
                break;
            case drogon::WebSocketMessageType::Unknown:
            default:
                return nullptr;
        }

        return m_handlersMap.emplace(messageType, newHandler).first->second;
    }

    IUsersControllerHandlerPtr
    UsersControllerHandlersFactory::CreateNewConnectionHandler(Net::IWebSocketConnectionPtr pWebSocketConnection)
    {
        return UsersControllerNewConnectionHandler::Create(m_pUsersManager, m_pUsersPubSubService, pWebSocketConnection);
    }
}
