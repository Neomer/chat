#ifndef CDEBUG_H
#define CDEBUG_H

#include <QObject>
#include <core/CSingleton.h>

#define errorCall(data)		singDebug::getInstance().printError(__FILE__, __LINE__, Q_FUNC_INFO, data)

#ifndef CHAT_NOT_DEBUG
#define debugCall(data)		singDebug::getInstance().printDebug(__FILE__, __LINE__, Q_FUNC_INFO, data)
#define dc					singDebug::getInstance().printDebug(__FILE__, __LINE__, Q_FUNC_INFO)
#else
#define debugCall(data)
#define dc
#endif

class CDebug : public QObject
{
	Q_OBJECT

public:
	CDebug(QObject * parent = 0);

	void setFormatDateTime(QString value) { _dtFormat = value; } 
	QString formatDateTime() { return _dtFormat; }
	
signals:
	
public slots:
	void print(QString data);
	void printDebug(QString file, int line, QString func, QString data = "");
	void printError(QString file, int line, QString func, QString data = "");

	
private:
	QString _dtFormat;
	
};

typedef CSingleton<CDebug> singDebug;

#endif // CDEBUG_H
