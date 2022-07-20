//
// Created by admin on 7/6/2022.
//
#pragma once
#include "User.hpp"
#include <json/value.h>
#include <map>
#include <memory>
#include <drogon/PubSubService.h>

namespace Hawk
{
    class UsersManager;
    typedef std::shared_ptr<UsersManager> UsersManagerPtr;

    class UsersManager
    {
    public:

        static UsersManagerPtr Create();

        bool RegisterUser(Json::Value jsonReq);

        std::shared_ptr<User> GetUser(const std::string& name);
    private:
        bool Register(std::shared_ptr<User> pUser);

        std::map<std::string, std::shared_ptr<User>> m_users;
    };
}