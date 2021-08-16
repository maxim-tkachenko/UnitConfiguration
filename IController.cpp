#include "IController.h"
#include "AVRPlatform.h"

IController::IController()
    : platform(new AVRPlatform())
{
    traceme;
}

IController::~IController()
{
    traceme;
}