#include "carDealership.h"

#include "../../../Core/core.h"

CarDealerShip::CarDealerShip() { INFO("CarDealerShip <- default constructor: called;"); }
CarDealerShip::~CarDealerShip() { INFO("CarDealerShip <- destructor: called;"); }

size_t CarDealerShip::getNextId() const { INFO("CarDealerShip -> method getNextId: called;"); if (_arr.size() > 1) { return _arr[_arr.size() - 2]._id + 1; } else { return 0; } }

void CarDealerShip::add(const Car& car) { INFO("CarDealerShip -> method add (obj): called;"); _arr.emplace_back(car); _arr.back()._id = getNextId(); }
void CarDealerShip::add(const string& name, const int& year, const double& engineVolume, const double& price) { INFO("CarDealerShip -> method add (values): called;"); _arr.emplace_back(Car{ getNextId(), name, year, engineVolume, price }); }
bool CarDealerShip::remove(const size_t& id) { INFO("CarDealerShip -> method remove: called;"); if (id > _arr.size() - 1) { return false; } _arr.erase(_arr.begin() + id); }

string CarDealerShip::displayById(const size_t& id) const
{
	INFO("CarDealerShip -> method displayById ( " + to_string(id) + " ): called;");

	if (id > _arr.size() - 1) { return "Unknown"; }

	Car obj = _arr.at(id);

	stringstream stream;
	stream
		<< "Car num. " << id + 1 << endl
		<< "  Name: " << obj._name << endl
		<< "  Year of production: " << obj._year << endl
		<< "  Engine volume: " << obj._engineVolume << endl
		<< "  Price: " << obj._price << "$" << endl;

	return stream.str();
}
string CarDealerShip::displayAll() const { INFO("CarDealerShip -> method displayAll: called;"); stringstream stream; for (size_t i = 0; i < _arr.size(); i++) { stream << displayById(i) << endl; } return stream.str(); }

void CarDealerShip::sortByPrice()
{
	INFO("CarDealerShip -> method sortByPrice: called;");

	for (size_t i = 0; i < _arr.size() - 1; i++)
	{
		for (size_t j = i + 1; j < _arr.size(); j++) { if (_arr[i]._price > _arr[j]._price) { swap(_arr[i], _arr[j]); } }
	}
}
void CarDealerShip::sortByEngineVolume()
{
	INFO("CarDealerShip -> method sortByEngineVolume: called;");

	for (size_t i = 0; i < _arr.size() - 1; i++)
	{
		for (size_t j = i + 1; j < _arr.size(); j++) { if (_arr[i]._engineVolume > _arr[j]._engineVolume) { swap(_arr[i], _arr[j]); } }
	}
}

vector<Car> CarDealerShip::searchByPrice(double min, double max) const { INFO("CarDealerShip -> method searchByPrice: called;"); vector<Car> result; for (const Car& obj : _arr) { if (obj._price > min && obj._price < max) { result.push_back(obj); } } return result; }
vector<Car> CarDealerShip::searchByEngineVolume(double min, double max) const { INFO("CarDealerShip -> method searchByEngineVolume: called;"); vector<Car> result; for (const Car& obj : _arr) { if (obj._engineVolume > min && obj._engineVolume < max) { result.push_back(obj); } } return result; }