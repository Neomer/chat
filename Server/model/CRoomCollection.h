#ifndef CROOMCOLLECTION_H
#define CROOMCOLLECTION_H

#include <QObject>
#include <QHash>

#include <model/CRoom.h>

class CRoomCollection : public QObject
{
	Q_OBJECT
public:
	explicit CRoomCollection(QObject *parent = 0);
	
	void createRoom();
	
signals:
	
public slots:
	
private:
	QHash<qint64, CRoom *> _map;
};

#endif // CROOMCOLLECTION_H
