//
// Created by admin on 7/5/2022.
//
#pragma once
#include "UsersManager.hpp"
#include <drogon/HttpController.h>
#include <shared_mutex>

namespace Hawk
{
    class UserController : public drogon::HttpController<UserController, false>
    {
    public:
        static std::shared_ptr<UserController> Create(UsersManagerPtr pUsersManager);
        explicit UserController(UsersManagerPtr pUsersManager);

        METHOD_LIST_BEGIN
        ADD_METHOD_TO(UserController::SignIn, "/HawkSignalingServer/User/SignIn", drogon::Post);
        ADD_METHOD_TO(UserController::SignOut, "/HawkSignalingServer/User/SignOut", drogon::Post);
        METHOD_LIST_END

    private:
        void SignIn(const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& callback);
        void SignOut(const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& callback);

        void ReportError(std::function<void(const drogon::HttpResponsePtr&)>&& callback,
                         drogon::HttpStatusCode httpStatusCode,
                         JSONCPP_STRING error);

        UsersManagerPtr m_pUsersManager;
    };
}