//
// Created by admin on 7/10/2022.
//

#include "Hawk/Controllers/UsersControllerHandlers/UsersControllerConnectionClosedHandler.hpp"
#include <iostream>

namespace Hawk
{
    UsersControllerConnectionClosedHandlerPtr
    Hawk::UsersControllerConnectionClosedHandler::Create(Net::IWebSocketConnectionPtr pWebSocketConnection)
    {
        return std::make_shared<UsersControllerConnectionClosedHandler>(std::move(pWebSocketConnection));
    }

    UsersControllerConnectionClosedHandler::UsersControllerConnectionClosedHandler(Net::IWebSocketConnectionPtr pWebSocketConnection)
        : m_pWebSocketConnection(std::move(pWebSocketConnection))
    {
        std::cout << "UsersControllerConnectionClosedHandler::UsersControllerConnectionClosedHandler" << std::endl;
    }

    UsersControllerConnectionClosedHandler::~UsersControllerConnectionClosedHandler()
    {
        std::cout << "UsersControllerConnectionClosedHandler::~UsersControllerConnectionClosedHandler" << std::endl;
    }

    void UsersControllerConnectionClosedHandler::Handle() {}

    // void UsersControllerConnectionClosedHandler::HandleMessage(const IUsersControllerHandler::Context& context)
    //{
    // std::cout << "UsersControllerConnectionClosedHandler::HandleMessage" << std::endl;

    // std::shared_ptr<User> pUser = std::static_pointer_cast<User>(m_pWebSocketConnection->GetContext());
    //}
}
