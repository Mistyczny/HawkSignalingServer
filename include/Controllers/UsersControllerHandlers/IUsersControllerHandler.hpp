//
// Created by admin on 7/8/2022.
//
#pragma once
#include <memory>

namespace Hawk
{
    class IUsersControllerHandler
    {
    public:
        virtual ~IUsersControllerHandler() = default;

        virtual void HandleMessage(std::string message) = 0;
    };

    using IUsersControllerHandlerPtr = std::shared_ptr<IUsersControllerHandler>;
}