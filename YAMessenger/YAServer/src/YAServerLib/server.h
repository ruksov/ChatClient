#pragma once

#include "databasemanager.h"
#include "clientinfo.h"
#include "serverdialog.h"
#include "clientconnection.h"
#include <QTcpServer>
#include <QSslConfiguration>

namespace Connection {


    class Server : public QTcpServer
    {
        Q_OBJECT
    public:
        explicit Server(std::shared_ptr<QFile> t_pLogFile, QObject *parent = 0);

        bool StartServer(const int& t_Port);
        QString GetIP();

    protected:
        void incomingConnection(qintptr handle) override;

    private:
        QMap<QString, ClientInfo::ClientInfo> m_mapClients;
        DatabaseManager::DatabaseManager m_dbManager;
        ServerDialog m_dialog;
        QSslConfiguration m_sslConfig;
        std::shared_ptr<QFile> m_pLogFile;
        int m_port;

        void WriteToLogFile(const QString& t_errorMsg);
    };

}
