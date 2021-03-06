#include "CClient.h"

CClient::CClient(QTcpSocket *socket, QObject *parent) : 
	QObject(parent)
{
	dc;
	
	_socket = socket;
	connect(_socket, SIGNAL(readyRead()), this, SLOT(readData()));
	connect(_socket, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
	
	_id = (qint64) this;
	
	singDataBus::getInstance().subscribe(this, BUS_SERVER_BROADCAST);
	singDataBus::getInstance().subscribe(this, BUS_CLIENT_MESSAGE);
}

CClient::~CClient()
{
	dc;
	
	singDataBus::getInstance().unsubscribe(this);
}

void CClient::sendMessage(QString message)
{
	debugCall(QString("Send message: ").append(message));
	
	_socket->write(message.toLatin1());
}

void CClient::readData()
{
	dc;
	
	QByteArray ba = _socket->readAll();
	singDataBus::getInstance().send(this, BUS_CLIENT_MESSAGE, ba);
}

void CClient::clientDisconnected()
{
	dc;
	
	emit connectionLost(this);
}

void CClient::onBusEvent(CBusListener *sender, qint16 eventId, QVariant data)
{
	Q_UNUSED(sender)
	Q_UNUSED(eventId)
	Q_UNUSED(data)
	
//	debugCall(QString("ClientID: %3 EventID: %1 Data: %2").arg(
//				QString::number(eventId), 
//				data,
//				QString::number(id())));
	
	
//	switch (eventId)
//	{
//		case BUS_SERVER_BROADCAST:
//			break;
			
//		case BUS_CLIENT_MESSAGE:
//		{
//			this->sendMessage(QString("[%1] %2: %3").arg(
//						 QDateTime::currentDateTime().toString("hh:mm:ss"),
//						 ((CClient *)sender)->nickname(),
//						 data
//						 ));
//			break;
//		}
//	}
	
}
