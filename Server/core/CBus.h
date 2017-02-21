#ifndef IBUS_H
#define IBUS_H

#include <QHash>
#include <QVariant>

#include <core/CDebug.h>
#include <core/CSingleton.h>


class CBusListener
{
	friend class CBus;
	
protected:
	virtual void onBusEvent(CBusListener *sender, qint16 eventId, QVariant data) = 0;
};

class CBus
{
public:
	explicit CBus() { }
	
	bool subscribe(CBusListener *object, qint16 eventId) 
	{ 
		dc;
		
		try
		{
			_map[eventId].append(object);
		}
		catch (...)
		{
			errorCall("Subscription failed!");
			return false;
		}
		return true;
	}
	
	bool unsubscribe(CBusListener *object, qint16 eventId)
	{
		dc;
		
		if (!_map.contains(eventId))
			return false;
		
		int idx = _map[eventId].indexOf(object);
		if (idx == -1)
			return false;
				
		_map[eventId].removeAt(idx);
		return true;
	}
	
	bool unsubscribe(CBusListener *object)
	{
		dc;
		
		foreach (qint64 eventId, _map.keys())
		{
			int idx = _map[eventId].indexOf(object);
			if (idx >= 0)
				_map[eventId].removeAt(idx);
		}
		return true;
	}
	
	void send(CBusListener *object, qint16 eventId, QVariant data)
	{
		dc; 
		
		if (!_map.contains(eventId))
			return;
			
		foreach (CBusListener *list, _map[eventId]) 
		{
			list->onBusEvent(object, eventId, data);
		}
	}
	
	
private:
	QHash<qint64, QList<CBusListener *>> _map;
};

typedef CSingleton<CBus> singDataBus;

#endif // IBUS_H
