#ifndef CCLIENT_H
#define CCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDateTime>

#include <core/CDebug.h>
#include <core/CBus.h>
#include <core/Messages.h>

class CClient : public QObject, public CBusListener
{
	Q_OBJECT
public:
	explicit CClient(QTcpSocket *socket, QObject *parent = 0);
	~CClient();

	QTcpSocket *socket() const { return _socket; }
	qint64 id() { return _id; }
	
	QString nickname() { return _nickname; }
	void setNickName(QString value) { _nickname = value; }
	
signals:
	void connectionLost(CClient *);
	
public slots:
	void sendMessage(QString message);	
	
private slots:
	void readData();
	void clientDisconnected();
	
private:
	QTcpSocket *_socket;
	qint64 _id;
	QString _nickname;
	
	// CBusListener interface
protected:
	void onBusEvent(CBusListener *sender, qint16 eventId, QVariant data);
};

#endif // CCLIENT_H
