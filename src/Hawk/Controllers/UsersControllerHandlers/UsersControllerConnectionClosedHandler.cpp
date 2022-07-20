//
// Created by admin on 7/10/2022.
//

#include "Hawk/Controllers/UsersControllerHandlers/UsersControllerConnectionClosedHandler.hpp"
#include <iostream>

namespace Hawk
{
    UsersControllerConnectionClosedHandlerPtr Hawk::UsersControllerConnectionClosedHandler::Create()
    {
        return std::make_shared<UsersControllerConnectionClosedHandler>();
    }

    UsersControllerConnectionClosedHandler::UsersControllerConnectionClosedHandler()
    {
        std::cout << "UsersControllerConnectionClosedHandler::UsersControllerConnectionClosedHandler" << std::endl;
    }

    UsersControllerConnectionClosedHandler::~UsersControllerConnectionClosedHandler()
    {
        std::cout << "UsersControllerConnectionClosedHandler::~UsersControllerConnectionClosedHandler" << std::endl;
    }

    void UsersControllerConnectionClosedHandler::HandleMessage(const IUsersControllerHandler::Context& context)
    {
        std::cout << "UsersControllerConnectionClosedHandler::HandleMessage" << std::endl;
    }
}
