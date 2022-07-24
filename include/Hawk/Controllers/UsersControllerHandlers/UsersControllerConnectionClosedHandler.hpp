//
// Created by admin on 7/8/2022.
//
#pragma once
#include <Hawk/Controllers/UsersControllerHandlers/IUsersConnectionEventHandler.hpp>

namespace Hawk
{
    class UsersControllerConnectionClosedHandler;
    using UsersControllerConnectionClosedHandlerPtr = std::shared_ptr<UsersControllerConnectionClosedHandler>;

    class UsersControllerConnectionClosedHandler : public IUsersConnectionEventHandler
    {
    public:
        static UsersControllerConnectionClosedHandlerPtr Create(Net::IWebSocketConnectionPtr pWebSocketConnection);
        UsersControllerConnectionClosedHandler(Net::IWebSocketConnectionPtr pWebSocketConnection);
        ~UsersControllerConnectionClosedHandler() override;

        void Handle() override;
    
    private:
        Net::IWebSocketConnectionPtr m_pWebSocketConnection;
    };
}
