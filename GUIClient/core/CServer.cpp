#include "CServer.h"

CServer::CServer(QObject *parent) : 
	QObject(parent),
	_srv(new QTcpServer(parent))
{
	dc;
	
	connect(_srv, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

CServer::~CServer()
{
	dc;
	
	singDataBus::getInstance().unsubscribe(this);
}

void CServer::start()
{
	dc;
	
	if (!_srv->listen(QHostAddress::Any, 15789))
	{
		debugCall("Port is busy!");
		return;
	}
}

void CServer::acceptConnection()
{
	dc;
	
	CClient * client = new CClient(_srv->nextPendingConnection(), this);
	connect(client, SIGNAL(connectionLost(CClient*)), this, SLOT(removeClient(CClient*)));
	debugCall(QString("Client connected... ip: %1").arg(client->socket()->peerAddress().toString()));
	
	singDataBus::getInstance().send(this, BUS_SERVER_BROADCAST, QString("New connection ID %1").arg(client->id()));
}

void CServer::removeClient(CClient *client)
{
	dc;
	
	debugCall(QString("Client disconnected...id: %1 ip: %2").arg(
				  QString::number(client->id()),
				  client->socket()->peerAddress().toString()));
	
	singDataBus::getInstance().send(this, BUS_SERVER_BROADCAST, QString("User disconnected ID %1").arg(client->id()));
}

void CServer::onBusEvent(CBusListener *sender, qint16 eventId, QString data)
{
	Q_UNUSED(sender)

	debugCall(QString("EventID: %1 Data: %2").arg(
				QString::number(eventId), 
				data));

}

