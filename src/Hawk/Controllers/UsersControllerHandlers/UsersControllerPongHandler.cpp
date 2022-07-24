//
// Created by admin on 7/8/2022.
//

#include "Hawk/Controllers/UsersControllerHandlers/UsersControllerPongHandler.hpp"
#include <iostream>

namespace Hawk
{
    UsersControllerPongHandlerPtr UsersControllerPongHandler::Create()
    {
        return std::make_shared<UsersControllerPongHandler>();
    }

    UsersControllerPongHandler::UsersControllerPongHandler()
    {
        std::cout << "UsersControllerPongHandler::UsersControllerPongHandler" << std::endl;
    }

    UsersControllerPongHandler::~UsersControllerPongHandler()
    {
        std::cout << "UsersControllerPongHandler::~UsersControllerPongHandler" << std::endl;
    }

    void UsersControllerPongHandler::HandleMessage(std::string&& message)
    {
        std::cout << "UsersControllerPongHandler::HandleMessage" << std::endl;
    }

}