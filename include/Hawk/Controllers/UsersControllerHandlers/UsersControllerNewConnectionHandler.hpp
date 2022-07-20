//
// Created by admin on 7/8/2022.
//
#pragma once
#include "Hawk/UsersManager.hpp"
#include "IUsersControllerHandler.hpp"
#include <Hawk/UsersPubSubService.hpp>
#include <Hawk/Net/IWebSocketConnection.hpp>

namespace Hawk
{
    class UsersControllerNewConnectionHandler;
    using UsersControllerNewConnectionHandlerPtr = std::shared_ptr<UsersControllerNewConnectionHandler>;

    class UsersControllerNewConnectionHandler : public IUsersControllerHandler
    {
    public:
        static UsersControllerNewConnectionHandlerPtr Create(UsersManagerPtr pUsersManager, UsersPubSubServicePtr pUsersPubSubService, Net::IWebSocketConnectionPtr pWebSocketConnection);
        UsersControllerNewConnectionHandler(UsersManagerPtr pUsersManager, UsersPubSubServicePtr pUsersPubSubService, Net::IWebSocketConnectionPtr pWebSocketConnection);
        ~UsersControllerNewConnectionHandler() override;

        void HandleMessage(const Context& context) override;

    private:
        UsersManagerPtr m_pUsersManager;
        UsersPubSubServicePtr m_pUsersPubSubService;
        Net::IWebSocketConnectionPtr m_pWebSocketConnection;
    };
}
