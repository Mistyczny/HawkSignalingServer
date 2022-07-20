//
// Created by admin on 7/8/2022.
//

#include <Hawk/Controllers/UsersController.hpp>
#include <Hawk/Net/WebSocketConnection.hpp>
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

        IUsersControllerHandler::Context context{};
        context.userName = pHttpRequest->getParameter("name");

        auto pWebSocketConnection = Net::WebSocketConnection::Create(pConnection);
        if (!pWebSocketConnection)
        {
            pWebSocketConnection->Shutdown(Net::CloseCode::kAbnormally, "Server Internal Error");
            return;
        }

        auto pNewConnectionHandler = m_pUsersControllersHandlersFactory->CreateNewConnectionHandler(pWebSocketConnection);
        pNewConnectionHandler->HandleMessage(context);
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
