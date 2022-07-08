//
// Created by admin on 7/6/2022.
//

#include "UsersManager.hpp"

namespace Hawk
{
    UsersManagerPtr UsersManager::Create()
    {
        return std::make_shared<UsersManager>();
    }

    bool UsersManager::RegisterUser(Json::Value jsonReq)
    {
        User user{};
        user.name = std::string(jsonReq["name"].asString());

        auto result = Register(user);
        if(!result) {
            return false;
        }

        return true;
    }

    bool UsersManager::Register(const User& user)
    {
        auto it = m_users.find(user.name);
        if(it != std::end(m_users))
        {
            return false;
        }

        return m_users.emplace(user.name, user).second;
    }

}