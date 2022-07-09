//
// Created by admin on 7/8/2022.
//

#include <Controllers/UsersControllerHandlers/UsersControllerBinaryHandler.hpp>
#include <Controllers/UsersControllerHandlers/UsersControllerCloseHandler.hpp>
#include <Controllers/UsersControllerHandlers/UsersControllerHandlersFactory.hpp>
#include <Controllers/UsersControllerHandlers/UsersControllerPingHandler.hpp>
#include <Controllers/UsersControllerHandlers/UsersControllerPongHandler.hpp>
#include <Controllers/UsersControllerHandlers/UsersControllerTextHandler.hpp>

namespace Hawk
{
    UsersControllerHandlersFactoryPtr UsersControllerHandlersFactory::Create()
    {
        return std::make_unique<UsersControllerHandlersFactory>();
    }

    IUsersControllerHandlerPtr UsersControllerHandlersFactory::GetOrCreateHandler(drogon::WebSocketMessageType messageType)
    {
        auto it = m_handlersMap.find(messageType);
        if (it != std::end(m_handlersMap))
        {
            return it->second;
        }

        return CreateHandler(messageType);
    }

    IUsersControllerHandlerPtr UsersControllerHandlersFactory::CreateHandler(drogon::WebSocketMessageType messageType)
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
}
