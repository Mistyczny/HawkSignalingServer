//
// Created by admin on 7/8/2022.
//

#include "Hawk/Controllers/UsersControllerHandlers/UsersControllerPingHandler.hpp"
#include <iostream>

namespace Hawk
{
    UsersControllerPingHandlerPtr UsersControllerPingHandler::Create()
    {
        return std::make_shared<UsersControllerPingHandler>();
    }

    UsersControllerPingHandler::UsersControllerPingHandler()
    {
        std::cout << "UsersControllerPingHandler::UsersControllerPingHandler" << std::endl;
    }

    UsersControllerPingHandler::~UsersControllerPingHandler()
    {
        std::cout << "UsersControllerPingHandler::~UsersControllerPingHandler" << std::endl;
    }

    void UsersControllerPingHandler::HandleMessage(std::string&& message)
    {
        std::cout << "UsersControllerPingHandler::HandleMessage" << std::endl;
    }
}
