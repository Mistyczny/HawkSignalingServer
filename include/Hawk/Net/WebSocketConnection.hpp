//
// Created by admin on 7/13/2022.
//
#pragma once
#include <Hawk/Net/IWebSocketConnection.hpp>
#include <drogon/WebSocketConnection.h>
#include <memory>

namespace Hawk::Net
{
    class WebSocketConnection;
    using WebSocketConnectionPtr = std::shared_ptr<WebSocketConnection>;

    class WebSocketConnection : public IWebSocketConnection
    {
    public:
        static WebSocketConnectionPtr Create(drogon::WebSocketConnectionPtr pWebSocketConnection);
        explicit WebSocketConnection(drogon::WebSocketConnectionPtr pWebSocketConnection);
        ~WebSocketConnection() override;

        /**
         *
         * @param message
         * @return
         */
        [[nodiscard]] bool Send(std::string message) override;

        /**
         *
         * @param pContext
         * @return
         */
        [[nodiscard]] bool SetContext(std::shared_ptr<void> pContext) override;

        /**
         * @brief Check, if has context assigned
         * 
         * @return Success, if has context. False otherwise
         */
        [[nodiscard]] bool HasContext() override;

        /**
         * @brief Get the Context object
         * 
         * @return std::shared_ptr<void*>
         */
        [[nodiscard]] std::shared_ptr<void*> GetContext() override;

        /**
         * @brief 
         * 
         * @param closeCode 
         * @param message 
         */
        void Shutdown(CloseCode closeCode, std::string message) override;
    protected:
        drogon::WebSocketConnectionPtr m_pWebSocketConnection;
    };
}
