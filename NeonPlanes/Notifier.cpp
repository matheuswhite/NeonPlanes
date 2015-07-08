#include "Notifier.h"

NotifierInterface* Notifier::_reciver = nullptr;

Notifier::Notifier()
{
}

Notifier::~Notifier()
{
}

void Notifier::addReciver(NotifierInterface* reciver) {
	_reciver = reciver;
}

void Notifier::notify(int parameter) {
	_reciver->action(parameter);
}
