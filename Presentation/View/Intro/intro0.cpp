#include "../view.h"
#include "../../../Domain/domain.h"

void testAddCar() {
    CarDealerShip dealership;
    dealership.add("Toyota", 2020, 2.5, 20000);
    if (dealership.displayAll().find("Toyota") != string::npos) {
        cout << "testAddCar passed" << endl;
    }
    else {
        cout << "testAddCar failed" << endl;
    }
}

void testRemoveCar() {
    CarDealerShip dealership;
    dealership.add("Toyota", 2020, 2.5, 20000);
    dealership.add("Honda", 2019, 2.0, 18000);
    if (dealership.remove(0) && dealership.displayAll().find("Toyota") == string::npos) {
        cout << "testRemoveCar passed" << endl;
    }
    else {
        cout << "testRemoveCar failed" << endl;
    }
}

void testDisplayById() {
    CarDealerShip dealership;
    dealership.add("Toyota", 2020, 2.5, 20000);
    string carInfo = dealership.displayById(0);
    if (carInfo.find("Toyota") != string::npos) {
        cout << "testDisplayById passed" << endl;
    }
    else {
        cout << "testDisplayById failed" << endl;
    }
}

void testSortByPrice() {
    CarDealerShip dealership;
    dealership.add("Toyota", 2020, 2.5, 20000);
    dealership.add("Honda", 2019, 2.0, 18000);
    dealership.sortByPrice();
    string sortedCars = dealership.displayAll();
    if (sortedCars.find("Honda") < sortedCars.find("Toyota")) {
        cout << "testSortByPrice passed" << endl;
    }
    else {
        cout << "testSortByPrice failed" << endl;
    }
}

void testSearchByPrice() {
    CarDealerShip dealership;
    dealership.add("Toyota", 2020, 2.5, 20000);
    dealership.add("Honda", 2019, 2.0, 18000);
    vector<Car> results = dealership.searchByPrice(19000, 21000);
    if (results.size() == 1 && results[0]._name == "Toyota") {
        cout << "testSearchByPrice passed" << endl;
    }
    else {
        cout << "testSearchByPrice failed" << endl;
    }
}

void View::Intro0() {
    testAddCar();
    testRemoveCar();
    testDisplayById();
    testSortByPrice();
    testSearchByPrice();
    cout << "All tests completed!" << endl;
}
