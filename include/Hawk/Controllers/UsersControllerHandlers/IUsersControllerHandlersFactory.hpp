//
// Created by admin on 7/8/2022.
//
#pragma once
#include "Hawk/PubSubServices/IUsersPubSubService.hpp"
#include <Hawk/Controllers/UsersControllerHandlers/IUsersControllerHandler.hpp>
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
    };

    using IUsersControllerHandlersFactoryPtr = std::unique_ptr<IUsersControllerHandlersFactory>;
}