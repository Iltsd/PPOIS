#include "AlertSystem.h"

AlertSystem::AlertSystem()
{
}

void AlertSystem::addAlert(std::string alert)
{
	this->alertText.push_back(std::make_pair(alert, 0));
	std::cout << "Уведомление успешно добавлено\n";
}

void AlertSystem::deleteAlert(int number)
{
	std::cout << "Уведомление: " << alertText[number].first << "Будет удалено\n";
	alertText.erase(alertText.begin() + number);

}

void AlertSystem::showInfo()
{
	for (int i = 0;i < alertText.size();++i)
	{
		std::cout << i+1 << "Уведомление" << std::endl;
		std::cout << alertText[i].first << "Успешных выполнений: " << alertText[i].second << std::endl;
	}
}

std::string AlertSystem::getAlertText(int number)
{
	return alertText[number].first;
}

bool AlertSystem::isComplite(int number, int shouldBe)
{
	return alertText[number].second >= shouldBe ? 1 : 0;
}
