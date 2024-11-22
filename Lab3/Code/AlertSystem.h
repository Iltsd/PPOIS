#pragma once
#include <string>
#include <iostream>
#include <vector>
class AlertSystem
{
protected:
	std::vector<std::pair<std::string, int>> alertText;
public:
	AlertSystem();
	void addAlert(std::string alert);
	void deleteAlert(int number);
	void showInfo();
	std::string getAlertText(int number);
	bool isComplite(int number, int shouldBe);
	
	


};

