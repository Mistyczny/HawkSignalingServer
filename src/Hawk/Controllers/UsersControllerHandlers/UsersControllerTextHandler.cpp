//
// Created by admin on 7/8/2022.
//

#include "Hawk/Controllers/UsersControllerHandlers/UsersControllerTextHandler.hpp"
#include <iostream>

namespace Hawk
{
    UsersControllerTextHandlerPtr UsersControllerTextHandler::Create(IUsersPubSubServicePtr pUsersPubSubService)
    {
        return std::make_shared<UsersControllerTextHandler>(std::move(pUsersPubSubService));
    }

    UsersControllerTextHandler::UsersControllerTextHandler(IUsersPubSubServicePtr pUsersPubSubService)
        : m_pUsersPubSubService{std::move(pUsersPubSubService)}
    {
        std::cout << "UsersControllerTextHandler::UsersControllerTextHandler" << std::endl;
    }

    UsersControllerTextHandler::~UsersControllerTextHandler()
    {
        std::cout << "UsersControllerTextHandler::~UsersControllerTextHandler" << std::endl;
    }

    void UsersControllerTextHandler::HandleMessage(const Context& context)
    {
        std::cout << "UsersControllerTextHandler::HandleMessage" << std::endl;
    }
}
