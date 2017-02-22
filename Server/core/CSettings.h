#ifndef CSETTINGS_H
#define CSETTINGS_H

#include <QObject>
#include <QSettings>

class CSettings : public QObject
{
	Q_OBJECT
public:
	explicit CSettings(QObject *parent = 0);
	
	void 
	
signals:
	
public slots:
	
private:
	QSettings *_settings;
};

#endif // CSETTINGS_H
