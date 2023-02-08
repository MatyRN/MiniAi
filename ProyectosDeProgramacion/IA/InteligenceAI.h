#pragma once
#include <string>
#include "WINDOW.h"
class WINDOW;
using namespace std;
class IntelAI{
public:
IntelAI();
IntelAI(const IntelAI&) = delete;
IntelAI& operator =(const IntelAI&) = delete;
~IntelAI();
std::string MessageAI;
private:

};
