#ifndef QFRONTDESK_H
#define QFRONTDESK_H

#include <grantlee_core.h>
#include <grantlee/engine.h>
#include <grantlee/template.h>
#include <grantlee/context.h>

#include <QNetworkInterface>
#include <QTcpServer>
#include <QTcpSocket>

#include <QDir>
#include <QFile>
#include <QByteArray>

#include <QDebug>

#include "requestmanager.h"
#include "request.h"

using namespace Grantlee;

class QFrontDesk : public QTcpServer {

    Q_OBJECT
public:
    QFrontDesk(int port, int slots_max, QString static_serve_path = "", QObject *parent = 0);
    ~QFrontDesk();

    void incomingConnection(int socket);

    virtual QString routing(QString route, Arguments *arg) = 0;
    void setTemplateDirs(QStringList dirs);
    Template loadTemplate(QString tpl);
    QString getUrl();

    QString ip_address;
    QString static_serve_path;
    int port;

private:
    RequestManager *rm;
    Request *r;
    QTcpSocket *s;

    FileSystemTemplateLoader::Ptr g_loader;
    Engine *g_engine;
    Template g_template;

signals:

public slots:
    void setActive(bool active);

private slots:
    void resolveRoute(QString route, Arguments *arg, QTcpSocket *s);

};

#endif // QFRONTDESK_H
