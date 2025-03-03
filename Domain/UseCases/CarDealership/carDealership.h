#ifndef CARDEALERSHIP_H
#define CARDEALERSHIP_H

#include "ICarDealership.h"

class CarDealerShip
	: public ICarDealerShip
{
private:
	vector<Car> _arr;
public:
	CarDealerShip();
	~CarDealerShip() override;
	
	size_t getNextId() const override;
	
	void add(const Car& car) override;
	void add(const string& name, const int& year, const double& engineVolume, const double& price) override;
	bool remove(const size_t& id) override;

	string displayById(const size_t& id) const override;
	string displayAll() const override;

	void sortByPrice() override;
	void sortByEngineVolume() override;

	vector<Car> searchByPrice(double min, double max = 1000000.0) const override;
	vector<Car> searchByEngineVolume(double min, double max = 1000000.0) const override;
};

#endif