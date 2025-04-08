#include <cassert>
#include <cstring>
#include <cwchar>
#include <functional>
#include <iostream>

class Car {
	char		   brand[129];
	char		   model[129];
	unsigned short year;
	double		   price;
	int			   HP;
	char		   color[3];

	Car() : year(-1), price(0), HP(0) {
		brand[0] = 0;
		model[0] = 0;
		color[0] = 0;
		color[1] = 0;
		color[2] = 0;
	}

   public:
	Car(const char *brand, const char *model, unsigned short year, double price, int HP, char r, char g, char b);

	const char	  *getBrand() const { return brand; }
	void		   setBrand(const char *newBrand) { strncpy(this->brand, newBrand, 128); }
	const char	  *getModel() const { return model; }
	void		   setModel(const char *newModel) { strncpy(this->model, newModel, 128); }
	unsigned short getYear() const { return year; }
	double		   getPrice() const { return price; }
	void		   setPrice(double newPrice) { price = newPrice; }
	int			   getHP() const { return HP; }

	using Color = char[3];
	const Color &getColor() { return color; }
	void		 setColor(char r, char g, char b) {
		this->color[0] = r;
		this->color[1] = g;
		this->color[2] = b;
	}

	void print(std::ostream &os) {
		os << "Car : { brand: " << brand << ", model: " << model << "}";	 //...
	}

	friend class CarShop;
};

Car::Car(const char *brand, const char *model, unsigned short year, double price, int HP, char r, char g, char b)
	: year(year), price(price), HP(HP) {
	strncpy(this->brand, brand, 128);
	strncpy(this->model, model, 128);
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

class CarShop {
	Car	  *cars;
	size_t size;

	void printFiltered(const std::function<bool(const Car &)> &f, std::ostream &os = std::cout) {
		for (size_t i = 0; i < size; ++i) {
			if (f(cars[i])) { cars[i].print(os); }
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

   public:
	CarShop() : cars(nullptr), size(0) {}
	CarShop(const CarShop &other) : cars(new Car[other.size]), size(other.size) {
		for (size_t i = 0; i < size; ++i) {
			cars[i] = other.cars[i];
		}
	}

	~CarShop() { delete[] cars; }

	CarShop &operator=(const CarShop &other) {
		if (this == &other) return *this;

		delete[] cars;
		size = other.size;
		cars = new Car[size];
		for (size_t i = 0; i < size; ++i) {
			cars[i] = other.cars[i];
		}
		return *this;
	}


	void resize(size_t newSize) {
		assert(newSize > size);
		Car *new_cars = new Car[newSize]();
		for (size_t i = 0; i < size; ++i) {
			new_cars[i] = cars[i];
		}
		delete[] cars;
		cars = new_cars;
		size = newSize;
	}

	void addCar(const Car &car) {
		resize(size + 1);
		cars[size - 1] = car;
	}

	void printByYear(unsigned short year) {
		printFiltered([year](const Car &car) { return car.getYear() >= year; });
	}

	void printByPower(int HP) {
		printFiltered([HP](const Car &car) { return car.getHP() >= HP; });
	}

	void printByPrice(double price) {
		printFiltered([price](const Car &car) { return car.getPrice() <= price; });
	}
};

int main() {
	std::cout << "Hello, World!" << std::endl;

	std::cout << sizeof(Car) << std::endl;
	Car	 c("Traicho", "Krakomobil", 2002, 10.0, 160, (char)255, (char)255, 0);
	auto col = c.getColor();
	std::cout << (int)col[0];

	CarShop shop;
	shop.addCar(c);
	shop.addCar(Car("Bugatti", "Chiron", 2010, 10.0, 10, (char)0, (char)255, (char)255));

	shop.printByYear(2005);
	shop.printByPower(100);

	std::cout << std::endl;
	return 0;
}
