//
// Created by admin on 7/9/2022.
//

#include <Hawk/Controllers/UsersControllerHandlers/UsersControllerNewConnectionHandler.hpp>
#include <iostream>

namespace Hawk
{
//    UsersControllerNewConnectionHandlerPtr UsersControllerNewConnectionHandler::Create(UsersManagerPtr pUsersManager,
//                                                                                       UsersPubSubServicePtr pUsersPubSubService,
//                                                                                       Net::IWebSocketConnectionPtr pWebSocketConnection)
//    {
//        return std::make_shared<UsersControllerNewConnectionHandler>(
//            std::move(pUsersManager), std::move(pUsersPubSubService), std::move(pWebSocketConnection));
//    }
//
//    UsersControllerNewConnectionHandler::UsersControllerNewConnectionHandler(UsersManagerPtr pUsersManager,
//                                                                             UsersPubSubServicePtr pUsersPubSubService,
//                                                                             Net::IWebSocketConnectionPtr pWebSocketConnection)
//        : m_pUsersManager{std::move(pUsersManager)}
//        , m_pUsersPubSubService{std::move(pUsersPubSubService)}
//        , m_pWebSocketConnection{std::move(pWebSocketConnection)}
//    {
//        std::cout << "UsersControllerNewConnectionHandler::UsersControllerNewConnectionHandler" << std::endl;
//    }
//
//    UsersControllerNewConnectionHandler::~UsersControllerNewConnectionHandler()
//    {
//        std::cout << "UsersControllerNewConnectionHandler::~UsersControllerNewConnectionHandler" << std::endl;
//    }
//
//    void UsersControllerNewConnectionHandler::Handle()
//    {
//
//    }

//    void UsersControllerNewConnectionHandler::HandleMessage(const IUsersControllerHandler::Context& context)
//    {
//        std::cout << "UsersControllerNewConnectionHandler::HandleMessage" << std::endl;
//        auto pUser = m_pUsersManager->GetUser(context.userName);
//
//        if (!pUser)
//        {
//            m_pWebSocketConnection->Shutdown(Net::CloseCode::kAbnormally, "User not signed in");
//            return;
//        }
//
//        if (auto result = m_pWebSocketConnection->SetContext(pUser); !result)
//        {
//            m_pWebSocketConnection->Shutdown(Net::CloseCode::kAbnormally, "Internal server error");
//            return;
//        }
//
//        auto subscribeCallback = [&](const std::string& topic, const std::string& message) {
//            (void)topic;
//            std::cout << "Sending message to pConnection" << message << std::endl;
//            m_pWebSocketConnection->Send(message);
//        };
//
//        if (auto result = m_pUsersPubSubService->Subscribe("friends", subscribeCallback); !result)
//        {
//            m_pWebSocketConnection->Shutdown(Net::CloseCode::kAbnormally, "Failed to subscribe");
//            return;
//        }
//    }
}
