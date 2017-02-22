#ifndef CROOM_H
#define CROOM_H

#include <QObject>
#include <core/CBus.h>

class CRoom : public QObject, public CBusListener
{
	Q_OBJECT
public:
	explicit CRoom(QObject *parent = 0);
	
signals:
	
public slots:
	
private:
	CBus _bus;
	
	// CBusListener interface
protected:
	void onBusEvent(CBusListener *sender, qint16 eventId, QVariant data);
};

#endif // CROOM_H
