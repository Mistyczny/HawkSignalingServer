//
// Created by admin on 7/8/2022.
//

#include <Controllers/UsersController.hpp>
#include <utility>

namespace Hawk
{
    UsersControllerPtr UsersController::Create(UsersManagerPtr pUsersManager,
                                               IUsersControllerHandlersFactoryPtr pUsersControllersHandlersFactory)
    {
        return std::make_shared<UsersController>(std::move(pUsersManager), std::move(pUsersControllersHandlersFactory));
    }

    UsersController::UsersController(UsersManagerPtr pUsersManager, IUsersControllerHandlersFactoryPtr pUsersControllersHandlersFactory)
        : m_pUsersManager(std::move(pUsersManager))
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
        auto userName = pHttpRequest->getParameter("name");
        std::cout << "UsersController::handleNewConnection name: " << userName << std::endl;
        auto pUser = m_pUsersManager->GetUser(userName);
        if (!pUser)
        {
            std::cout << "UsersController::handleNewConnection user: " << userName << " - is not signed in" << std::endl;
            pConnection->shutdown(drogon::CloseCode::kAbnormally, "User not signed in");
            return;
        }

        std::cout << "UsersController::handleNewConnection subscribe: " << userName << std::endl;
        pUser->subscriberId = m_usersPubSubService.subscribe("friends",
                                                             [pConnection](const std::string& topic, const std::string& message) {
                                                                 (void)topic;
                                                                 std::cout << "Sending message to pConnection" << message << std::endl;
                                                                 pConnection->send(message);
                                                             }

        );
        std::cout << "UsersController::handleNewConnection setContext: " << userName << std::endl;
        pConnection->setContext(pUser);
    }

    void UsersController::handleNewMessage(const drogon::WebSocketConnectionPtr& pConnection,
                                           std::string&& message,
                                           const drogon::WebSocketMessageType& messageType)
    {

        auto pMessageHandler = m_pUsersControllersHandlersFactory->GetOrCreateHandler(messageType);
        if (!pMessageHandler)
        {
            std::cout << "Failed to create required handler" << std::endl;
        }

        pMessageHandler->HandleMessage(message);

        if (messageType == drogon::WebSocketMessageType::Ping)
        {
            std::cout << "Its ping" << std::endl;
        }

        std::cout << "Its message" << message << std::endl;

        auto& s = pConnection->getContextRef<User>();
        m_usersPubSubService.publish("friends", message);
    }

    void UsersController::handleConnectionClosed(const drogon::WebSocketConnectionPtr& pConnection)
    {
        std::cout << "UsersController::handleConnectionClosed" << std::endl;
        if (!pConnection->hasContext())
        {
            return;
        }

        auto& s = pConnection->getContextRef<User>();
        m_usersPubSubService.unsubscribe("friends", s.subscriberId);
    }
}
