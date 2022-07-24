//
// Created by admin on 7/8/2022.
//
#pragma once
#include "Hawk/UsersManager.hpp"
#include "IUsersControllerHandlersFactory.hpp"
#include <Hawk/IUsersPubSubService.hpp>
#include <map>

namespace Hawk
{
    class UsersControllerHandlersFactory;
    using UsersControllerHandlersFactoryPtr = std::unique_ptr<UsersControllerHandlersFactory>;

    class UsersControllerHandlersFactory : public IUsersControllerHandlersFactory
    {
    public:
        static UsersControllerHandlersFactoryPtr Create(UsersManagerPtr pUsersManager, IUsersPubSubServicePtr pUsersPubSubService);

        UsersControllerHandlersFactory(UsersManagerPtr pUsersManager, IUsersPubSubServicePtr pUsersPubSubService);

        /**
         *
         * @param messageType
         * @return
         */
        IUsersControllerHandlerPtr GetOrCreateMessageHandler(drogon::WebSocketMessageType messageType) override;

    private:
        /**
         *
         * @param messageType
         * @return
         */
        IUsersControllerHandlerPtr CreateMessageHandler(drogon::WebSocketMessageType messageType);

        std::map<drogon::WebSocketMessageType, IUsersControllerHandlerPtr> m_handlersMap;
        UsersManagerPtr m_pUsersManager;
        IUsersPubSubServicePtr m_pUsersPubSubService;
    };
}