#ifndef CSERVER_H
#define CSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QList>
#include <QTcpSocket>


#include <core/CClient.h>
#include <core/CBus.h>

class CServer : public QObject, public CBusListener
{
	Q_OBJECT
	
public:
	explicit CServer(QObject *parent = 0);
	~CServer();
	
	void start();
	
signals:
	
public slots:
	
private slots:
	void acceptConnection();
	void removeClient(CClient * client);
	
private:
	QTcpServer * _srv;
	
	// CBusListener interface
protected:
	void onBusEvent(CBusListener *sender, qint16 eventId, QString data);
};

#endif // CSERVER_H
