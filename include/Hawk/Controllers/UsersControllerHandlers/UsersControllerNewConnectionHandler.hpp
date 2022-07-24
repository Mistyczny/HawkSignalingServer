//
// Created by admin on 7/8/2022.
//
#pragma once
#include "Hawk/UsersManager.hpp"
#include "IUsersConnectionEventHandler.hpp"
#include <Hawk/Net/IWebSocketConnection.hpp>
#include <Hawk/UsersPubSubService.hpp>

namespace Hawk
{
    class UsersControllerNewConnectionHandler;
    using UsersControllerNewConnectionHandlerPtr = std::shared_ptr<UsersControllerNewConnectionHandler>;

    /**
     * @brief
     *
     */
    class UsersControllerNewConnectionHandler : public IUsersConnectionEventHandler
    {
    public:
        /**
         * @brief Create a new Users Controller New Connection Handler object
         *
         * @param pUsersManager
         * @param pUsersPubSubService
         * @param pWebSocketConnection
         * @return UsersControllerNewConnectionHandlerPtr
         */
        static UsersControllerNewConnectionHandlerPtr
        Create(UsersManagerPtr pUsersManager, UsersPubSubServicePtr pUsersPubSubService, Net::IWebSocketConnectionPtr pWebSocketConnection);

        /**
         * @brief Construct a new Users Controller New Connection Handler object
         *
         * @param pUsersManager
         * @param pUsersPubSubService
         * @param pWebSocketConnection
         */
        UsersControllerNewConnectionHandler(UsersManagerPtr pUsersManager,
                                            UsersPubSubServicePtr pUsersPubSubService,
                                            Net::IWebSocketConnectionPtr pWebSocketConnection);

        /**
         * @brief Destroy the Users Controller New Connection Handler object
         *
         */
        ~UsersControllerNewConnectionHandler() override;

        /**
         * @brief
         *
         * @param context
         */
        void Handle() override;

    private:
        UsersManagerPtr m_pUsersManager;
        UsersPubSubServicePtr m_pUsersPubSubService;
        Net::IWebSocketConnectionPtr m_pWebSocketConnection;
    };
}
