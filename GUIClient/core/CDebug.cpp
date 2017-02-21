#include "CDebug.h"
#include <QDateTime>

CDebug::CDebug(QObject *parent) : QObject(parent)
{
	setFormatDateTime("yyyy-MM-dd hh:mm:ss.zzz");
}

void CDebug::print(QString data)
{
	qDebug("%s", QString("[%1] %2").arg(
					QDateTime::currentDateTime().toString(_dtFormat),
					data).toLatin1().constData());
}

void CDebug::printDebug(QString file, int line, QString func, QString data)
{
	if (data.isEmpty())
	{
		qDebug("%s", QString("[%1] %2 in line %3 function %4").arg(
				   QDateTime::currentDateTime().toString(_dtFormat),
				   file,
				   QString::number(line),
				   func).toLatin1().constData());
	}
	else
	{
		qDebug("%s", QString("[%1] %2 in line %3 function %4\nMessage: %5").arg(
				   QDateTime::currentDateTime().toString(_dtFormat),
				   file,
				   QString::number(line),
				   func,
				   data).toLatin1().constData());
	}
}

void CDebug::printError(QString file, int line, QString func, QString data)
{
	qDebug("%s", QString("[%1] %2 in line %3 function %4\ERROR: %5").arg(
			   QDateTime::currentDateTime().toString(_dtFormat),
			   file,
			   QString::number(line),
			   func,
			   data).toLatin1().constData());
}
