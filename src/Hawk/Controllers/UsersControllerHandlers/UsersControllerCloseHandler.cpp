//
// Created by admin on 7/8/2022.
//

#include "Hawk/Controllers/UsersControllerHandlers/UsersControllerCloseHandler.hpp"
#include <iostream>

namespace Hawk
{
    UsersControllerCloseHandlerPtr UsersControllerCloseHandler::Create()
    {
        return std::make_shared<UsersControllerCloseHandler>();
    }

    UsersControllerCloseHandler::UsersControllerCloseHandler()
    {
        std::cout << "UsersControllerCloseHandler::UsersControllerCloseHandler" << std::endl;
    }

    UsersControllerCloseHandler::~UsersControllerCloseHandler()
    {
        std::cout << "UsersControllerCloseHandler::~UsersControllerCloseHandler" << std::endl;
    }

    void UsersControllerCloseHandler::HandleMessage(const Context& context)
    {
        std::cout << "UsersControllerCloseHandler::HandleMessage" << std::endl;
    }
}
