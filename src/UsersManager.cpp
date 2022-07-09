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
        auto pUser = std::make_shared<User>();
        pUser->name = std::string(jsonReq["name"].asString());

        auto result = Register(pUser);
        if(!result) {
            return false;
        }

        return true;
    }

    bool UsersManager::Register(std::shared_ptr<User> pUser)
    {
        auto it = m_users.find(pUser->name);
        if(it != std::end(m_users))
        {
            return false;
        }

        return m_users.emplace(pUser->name, pUser).second;
    }

    std::shared_ptr<User> UsersManager::GetUser(const std::string& name)
    {
        auto it = m_users.find(name);
        if(it != std::end(m_users))
        {
            return it->second;
        }
        return nullptr;
    }

}