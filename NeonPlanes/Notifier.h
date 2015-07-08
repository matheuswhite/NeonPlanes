#pragma once

class NotifierInterface
{
public:
	NotifierInterface() {}
	virtual ~NotifierInterface() {}

	virtual void action(int parameter) = 0;
};

class Notifier
{
public:
	Notifier();
	virtual ~Notifier();

	static void addReciver(NotifierInterface* reciver);
	static void notify(int parameter);
private:
	static NotifierInterface* _reciver;
};
