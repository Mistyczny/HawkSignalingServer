//
// Created by admin on 7/8/2022.
//

#include "Hawk/Controllers/UsersControllerHandlers/UsersControllerBinaryHandler.hpp"
#include <iostream>

namespace Hawk
{
    UsersControllerBinaryHandlerPtr UsersControllerBinaryHandler::Create()
    {
        return std::make_shared<UsersControllerBinaryHandler>();
    }
    UsersControllerBinaryHandler::UsersControllerBinaryHandler()
    {
        std::cout << "UsersControllerBinaryHandler::UsersControllerBinaryHandler" << std::endl;
    }

    UsersControllerBinaryHandler::~UsersControllerBinaryHandler()
    {
        std::cout << "UsersControllerBinaryHandler::~UsersControllerBinaryHandler" << std::endl;
    }

    void UsersControllerBinaryHandler::HandleMessage(std::string&& message)
    {
        std::cout << "UsersControllerBinaryHandler::HandleMessage" << std::endl;
    }
}