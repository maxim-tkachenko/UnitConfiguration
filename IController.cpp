#include "IController.h"

IController::IController(uint8_t id) : _id(id)
{
    traceme;
}

IController::~IController()
{
    traceme;
}

uint8_t IController::getId()
{
    return _id;
}