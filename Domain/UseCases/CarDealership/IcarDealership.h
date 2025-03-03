#ifndef CARDEALERSHIP_INTERFACE_H
#define CARDEALERSHIP_INTERFACE_H

#include "../../../lib.h"
#include "../../Entities/Car/car.h"

class ICarDealerShip
{
public:
	virtual ~ICarDealerShip() = default;

	virtual size_t getNextId() const = 0;

	virtual void add(const Car& car) = 0;
	virtual void add(const string& name, const int& year, const double& engineVolume, const double& price) = 0;
	virtual bool remove(const size_t& id) = 0;

	virtual string displayById(const size_t& id) const = 0;
	virtual string displayAll() const = 0;

	virtual void sortByPrice() = 0;
	virtual void sortByEngineVolume() = 0;

	virtual vector<Car> searchByPrice(double min, double max = 1000000.0) const = 0;
	virtual vector<Car> searchByEngineVolume(double min, double max = 1000000.0) const = 0;
};

#endif