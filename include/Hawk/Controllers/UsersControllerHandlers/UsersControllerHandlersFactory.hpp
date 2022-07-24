//
// Created by admin on 7/8/2022.
//
#pragma once
#include "Hawk/UsersManager.hpp"
#include "IUsersControllerHandlersFactory.hpp"
#include <Hawk/UsersPubSubService.hpp>

#include <map>

namespace Hawk
{
    class UsersControllerHandlersFactory;
    using UsersControllerHandlersFactoryPtr = std::unique_ptr<UsersControllerHandlersFactory>;

    class UsersControllerHandlersFactory : public IUsersControllerHandlersFactory
    {
    public:
        static UsersControllerHandlersFactoryPtr Create(UsersManagerPtr pUsersManager, UsersPubSubServicePtr pUsersPubSubService);

        UsersControllerHandlersFactory(UsersManagerPtr pUsersManager, UsersPubSubServicePtr pUsersPubSubService);

        /**
         * @brief Get or Create Message Handler object
         * 
         * @param messageType 
         * @return IUsersControllerHandlerPtr 
         */
        IUsersControllerHandlerPtr GetOrCreateMessageHandler(drogon::WebSocketMessageType messageType) override;

        /**
         * @brief Create a New Connection Handler object
         * 
         * @param pWebSocketConnection 
         * @return IUsersControllerHandlerPtr 
         */
        IUsersConnectionEventHandlerPtr CreateNewConnectionHandler(Net::IWebSocketConnectionPtr pWebSocketConnection) override;

        /**
         * @brief Create a Connection Closed Handler object
         * 
         * @param pWebSocketConnection 
         * @return IUsersControllerHandlerPtr 
         */
        IUsersConnectionEventHandlerPtr CreateConnectionClosedHandler(Net::IWebSocketConnectionPtr pWebSocketConnection) override;
    private:
        /**
         *
         * @param messageType
         * @return
         */
        IUsersControllerHandlerPtr CreateMessageHandler(drogon::WebSocketMessageType messageType);

        std::map<drogon::WebSocketMessageType, IUsersControllerHandlerPtr> m_handlersMap;
        UsersManagerPtr m_pUsersManager;
        UsersPubSubServicePtr m_pUsersPubSubService;
    };
}