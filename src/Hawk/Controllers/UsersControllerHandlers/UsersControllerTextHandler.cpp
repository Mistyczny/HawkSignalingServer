//
// Created by admin on 7/8/2022.
//

#include "Hawk/Controllers/UsersControllerHandlers/UsersControllerTextHandler.hpp"
#include <iostream>

namespace Hawk
{
    UsersControllerTextHandlerPtr UsersControllerTextHandler::Create()
    {
        return std::make_shared<UsersControllerTextHandler>();
    }

    UsersControllerTextHandler::UsersControllerTextHandler()
    {
        std::cout << "UsersControllerTextHandler::UsersControllerTextHandler" << std::endl;
    }

    UsersControllerTextHandler::~UsersControllerTextHandler()
    {
        std::cout << "UsersControllerTextHandler::~UsersControllerTextHandler" << std::endl;
    }

    void UsersControllerTextHandler::HandleMessage(std::string&& message)
    {
        std::cout << "UsersControllerTextHandler::HandleMessage" << std::endl;
        Json::Value jsonDocument;
        Json::Reader jsonReader;

        if (bool parseResult = jsonReader.parse(message, jsonDocument); !parseResult)
        {
            return;
        }
    }
}
