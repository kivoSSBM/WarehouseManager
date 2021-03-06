#include "System.h"

System::System(int databaseCapacity, int warehouseCapacity)
{
	this->databaseHandler = new DatabaseHandler(databaseCapacity);
	this->warehouseHandler = new WarehouseHandler(warehouseCapacity);
	this->selectedWarehouse = nullptr;
	this->selectedTruck = nullptr;
	this->selectedGoods = nullptr;
	this->currentSelectionIsATruck = false;
}

System::~System()
{
	delete this->databaseHandler;
	delete this->warehouseHandler;
}

void System::selectWarehouse(std::string name)
{
	this->selectedWarehouse = this->warehouseHandler->getWarehouse(name);
}

void System::addWarehouse(Warehouse * warehouse)
{
	this->warehouseHandler->addWarehouse(warehouse);
}

void System::removeWarehouse(std::string name)
{
	this->selectedWarehouse = this->warehouseHandler->removeWarehouse(name);
	delete this->selectedWarehouse;
	this->selectedWarehouse = nullptr;
}

Warehouse * System::getSelectedWarehouse() const
{
    return this->selectedWarehouse;
}

Truck * System::getSelectedTruck() const
{
	return this->selectedTruck;
}

Goods * System::getSelectedGoods() const
{
	return this->selectedGoods;
}

bool System::warehouseExists(std::string name) const
{
	return this->warehouseHandler->getWarehouse(name) != nullptr;
}

void System::selectTruck(std::string name)
{
	this->selectedTruck = this->selectedWarehouse->getTruck(name);
}

void System::selectGoods(std::string name)
{
	if (this->currentSelectionIsATruck)
	{
		this->selectedGoods = this->selectedTruck->getGoods(name);
	}
	else
	{
		this->selectedGoods = this->selectedWarehouse->getGoods(name);
	}
}

bool System::isDatabaseHandlerFull() const
{
	return this->databaseHandler->isFull();
}

bool System::isWarehouseHandlerFull() const
{
	return this->warehouseHandler->isFull();
}