//
// Created by admin on 7/8/2022.
//
#pragma once
#include <Controllers/UsersControllerHandlers/IUsersControllerHandler.hpp>
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
        virtual IUsersControllerHandlerPtr GetOrCreateHandler(drogon::WebSocketMessageType messageType) = 0;
    };

    using IUsersControllerHandlersFactoryPtr = std::unique_ptr<IUsersControllerHandlersFactory>;
}