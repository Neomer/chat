#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	dc;
	ui->setupUi(this);
	
	connect(ui->cmdSend, SIGNAL(clicked(bool)), this, SLOT(sendMessage()));
	
	singDataBus::getInstance().subscribe(this, BUS_CLIENT_MESSAGE);
	singDataBus::getInstance().subscribe(this, BUS_SERVER_BROADCAST);
	
	_client = new CClient(new QTcpSocket(this));
	_client->setNickName("Nickname");
	_client->socket()->connectToHost("127.0.0.1", 15789, QIODevice::ReadWrite);
	connect(_client, SIGNAL(connectionLost(CClient*)), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
	dc;
	delete ui;
}

void MainWindow::sendMessage()
{
	_client->socket()->write(ui->txtMessage->text().toLatin1());
	ui->txtMessage->clear();
}

void MainWindow::appendMessage(QString text)
{
	ui->txtChat->appendPlainText(text);
	ui->txtChat->moveCursor(QTextCursor::Down);
}

void MainWindow::onBusEvent(CBusListener *sender, qint16 eventId, QVariant data)
{
	Q_UNUSED(sender)
	
	debugCall(QString("ClientID: %3 EventID: %1 Data: %2").arg(
				QString::number(eventId), 
				data.toString(),
				QString::number(_client->id())));
	
	
	switch (eventId)
	{
		case BUS_CLIENT_CONNECTED:
		{
		}
			
		case BUS_CLIENT_DISCONNECTED:
		{
		}
		
		case BUS_SERVER_BROADCAST:
		{
		}
			
		case BUS_CLIENT_MESSAGE:
		{
			appendMessage(data.toString());
			break;
		}
	}

}
