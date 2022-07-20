//
// Created by admin on 7/5/2022.
//
#pragma once
#include "Hawk/UsersManager.hpp"
#include <drogon/HttpController.h>

namespace Hawk
{
    class SignalingController : public drogon::HttpController<SignalingController, false>
    {
    public:
        static std::shared_ptr<SignalingController> Create(UsersManagerPtr pUsersManager);
        explicit SignalingController(UsersManagerPtr pUsersManager);

        METHOD_LIST_BEGIN
        ADD_METHOD_TO(SignalingController::PeerMessage, "/HawkSignalingServer/SignalingController/PeerMessage", drogon::Post);
        METHOD_LIST_END

    private:
        void PeerMessage(const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& callback);

        UsersManagerPtr m_pUsersManager;
    };
}