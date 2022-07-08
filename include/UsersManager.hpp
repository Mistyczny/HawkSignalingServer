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

    private:
        bool Register(const User& user);

        std::map<std::string, User> m_users;
    };
}