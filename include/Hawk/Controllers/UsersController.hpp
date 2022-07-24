//
// Created by admin on 7/5/2022.
//
#pragma once
#include <Hawk/Controllers/UsersControllerHandlers/IUsersControllerHandlersFactory.hpp>
#include <Hawk/UsersManager.hpp>
#include <drogon/HttpController.h>
#include <drogon/PubSubService.h>
#include <drogon/WebSocketController.h>
#include <shared_mutex>

namespace Hawk
{
    class UsersController;
    using UsersControllerPtr = std::shared_ptr<UsersController>;

    class UsersController : public drogon::WebSocketController<UsersController, false>
    {
    public:
        /**
         *
         * @param pUsersManager
         * @param pUsersControllersHandlersFactory
         * @return
         */
        static UsersControllerPtr Create(UsersManagerPtr pUsersManager,
                                         IUsersPubSubServicePtr pUsersPubSubService,
                                         IUsersControllerHandlersFactoryPtr pUsersControllersHandlersFactory);

        /**
         * @brief Construct a new Users Controller object
         *
         * @param pUserManager
         */
        explicit UsersController(UsersManagerPtr pUsersManager,
                                 IUsersPubSubServicePtr pUsersPubSubService,
                                 IUsersControllerHandlersFactoryPtr pUsersControllersHandlersFactory);

        /**
         * @brief Destroy the Users Controller object
         *
         */
        ~UsersController() override;

        /**
         * @brief
         *
         * @param pHttpRequest
         * @param pConnection
         */
        void handleNewConnection(const drogon::HttpRequestPtr& pHttpRequest, const drogon::WebSocketConnectionPtr& pConnection) override;

        /**
         * @brief
         *
         * @param pConnection
         * @param message
         * @param messageType
         */
        void handleNewMessage(const drogon::WebSocketConnectionPtr& pConnection,
                              std::string&& message,
                              const drogon::WebSocketMessageType& messageType) override;

        /**
         * @brief
         *
         * @param pConnection
         */
        void handleConnectionClosed(const drogon::WebSocketConnectionPtr& pConnection) override;

        WS_PATH_LIST_BEGIN
        WS_PATH_ADD("/HawkSignalingServer/Users", drogon::Get);
        WS_PATH_LIST_END

    protected:
        void ReportError();

    private:
        UsersManagerPtr m_pUsersManager;
        IUsersPubSubServicePtr m_pUsersPubSubService;
        IUsersControllerHandlersFactoryPtr m_pUsersControllersHandlersFactory;
    };
}