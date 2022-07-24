//
// Created by admin on 7/8/2022.
//

#include <Hawk/Controllers/UsersController.hpp>
#include <Hawk/Net/WebSocketConnection.hpp>
#include <utility>

namespace Hawk
{
    UsersControllerPtr UsersController::Create(UsersManagerPtr pUsersManager,
                                               IUsersPubSubServicePtr pUsersPubSubService,
                                               IUsersControllerHandlersFactoryPtr pUsersControllersHandlersFactory)
    {
        return std::make_shared<UsersController>(
            std::move(pUsersManager), std::move(pUsersPubSubService), std::move(pUsersControllersHandlersFactory));
    }

    UsersController::UsersController(UsersManagerPtr pUsersManager,
                                     IUsersPubSubServicePtr pUsersPubSubService,
                                     IUsersControllerHandlersFactoryPtr pUsersControllersHandlersFactory)
        : m_pUsersManager(std::move(pUsersManager))
        , m_pUsersPubSubService(std::move(pUsersPubSubService))
        , m_pUsersControllersHandlersFactory(std::move(pUsersControllersHandlersFactory))
    {
        std::cout << "UsersController::UsersController" << std::endl;
    }

    UsersController::~UsersController()
    {
        std::cout << "UsersController::~UsersController" << std::endl;
    }

    void UsersController::handleNewConnection(const drogon::HttpRequestPtr& pHttpRequest, const drogon::WebSocketConnectionPtr& pConnection)
    {
        std::cout << "UsersController::handleNewConnection" << std::endl;
        auto pWebSocketConnection = Hawk::Net::WebSocketConnection::Create(pConnection);

        auto userName = pHttpRequest->getParameter("name");

        auto pUser = m_pUsersManager->GetUser(userName);
        if (!pUser)
        {
            pWebSocketConnection->Shutdown(Net::CloseCode::kAbnormally, "User not signed in");
            return;
        }

        if (auto result = pWebSocketConnection->SetContext(pUser); !result)
        {
            pWebSocketConnection->Shutdown(Net::CloseCode::kAbnormally, "Internal server error");
            return;
        }

        auto subscribeCallback = [&](const std::string& topic, const std::string& message) {
            (void)topic;
            std::cout << "Sending message to pConnection" << message << std::endl;
            pWebSocketConnection->Send(message);
        };

        if (auto result = m_pUsersPubSubService->Subscribe("friends", subscribeCallback); !result)
        {
            pWebSocketConnection->Shutdown(Net::CloseCode::kAbnormally, "Failed to subscribe");
            return;
        }
    }

    void UsersController::handleNewMessage(const drogon::WebSocketConnectionPtr& pConnection,
                                           std::string&& message,
                                           const drogon::WebSocketMessageType& messageType)
    {

        auto pMessageHandler = m_pUsersControllersHandlersFactory->GetOrCreateMessageHandler(messageType);
        if (!pMessageHandler)
        {
            std::cout << "Failed to create required handler" << std::endl;
        }

        IUsersControllerHandler::Context context{};
        context.message = message;
        pMessageHandler->HandleMessage(context);

        // auto& s = pConnection->getContextRef<User>();
        // m_usersPubSubService.publish("friends", message);
    }

    void UsersController::handleConnectionClosed(const drogon::WebSocketConnectionPtr& pConnection)
    {
        std::cout << "UsersController::handleConnectionClosed" << std::endl;
        if (!pConnection->hasContext())
        {
            return;
        }

        auto& s = pConnection->getContextRef<User>();
        // m_usersPubSubService.unsubscribe("friends", s.subscriberId);
    }
}
