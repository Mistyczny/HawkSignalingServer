//
// Created by admin on 7/8/2022.
//
#pragma once
#include "Hawk/User.hpp"
#include <Hawk/Net/IWebSocketConnection.hpp>
#include <memory>

namespace Hawk
{
    class IUsersControllerHandler
    {
    public:
        class Context
        {
        public:
            std::string message{};
            std::string userName{};
        };
        virtual ~IUsersControllerHandler() = default;

        virtual void HandleMessage(const Context& context) = 0;
    };

    using IUsersControllerHandlerPtr = std::shared_ptr<IUsersControllerHandler>;
}