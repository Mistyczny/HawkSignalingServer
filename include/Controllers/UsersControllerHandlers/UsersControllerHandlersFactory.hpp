//
// Created by admin on 7/8/2022.
//
#pragma once
#include <Controllers/UsersControllerHandlers/IUsersControllerHandlersFactory.hpp>
#include <map>

namespace Hawk
{
    class UsersControllerHandlersFactory;
    using UsersControllerHandlersFactoryPtr = std::unique_ptr<UsersControllerHandlersFactory>;

    class UsersControllerHandlersFactory : public IUsersControllerHandlersFactory
    {
    public:
        static UsersControllerHandlersFactoryPtr Create();

        /**
         *
         * @param messageType
         * @return
         */
        IUsersControllerHandlerPtr GetOrCreateHandler(drogon::WebSocketMessageType messageType) override;

    private:
        /**
         *
         * @param messageType
         * @return
         */
        IUsersControllerHandlerPtr CreateHandler(drogon::WebSocketMessageType messageType);

        std::map<drogon::WebSocketMessageType, IUsersControllerHandlerPtr> m_handlersMap;
    };
}