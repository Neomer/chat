#include "CSettings.h"

CSettings::CSettings(QObject *parent) : QObject(parent)
{
	_settings = new QSettings("Chat.ini", QSettings::IniFormat);
}

