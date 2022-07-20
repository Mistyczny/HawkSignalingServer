//
// Created by admin on 7/8/2022.
//
#pragma once
#include "IUsersControllerHandler.hpp"
#include <Hawk/IUsersPubSubService.hpp>
#include <Hawk/Net/IWebSocketConnection.hpp>
#include <drogon/HttpTypes.h>

namespace Hawk
{
    class IUsersControllerHandlersFactory
    {
    public:
        virtual ~IUsersControllerHandlersFactory() = default;

        /**
         *
         * @param messageType
         * @return
         */
        virtual IUsersControllerHandlerPtr GetOrCreateMessageHandler(drogon::WebSocketMessageType messageType) = 0;

        /**
         *
         * @param pWebSocketConnection
         * @return
         */
        virtual IUsersControllerHandlerPtr CreateNewConnectionHandler(Net::IWebSocketConnectionPtr pWebSocketConnection) = 0;
    };

    using IUsersControllerHandlersFactoryPtr = std::unique_ptr<IUsersControllerHandlersFactory>;
}