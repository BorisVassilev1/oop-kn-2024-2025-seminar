#include <cstring>
#include <iostream>

class Student {
	char  name[51] = {0};
	int	  age;
	float grades[10] = {0};

   public:
	Student(const char* name, int age) {
		setName(name);
		this->age = age;
	}

	const char* getName() const { return name; }
	void		setName(const char* name) { strncpy(this->name, name, 50); }

	int	 getAge() const { return age; }
	void setAge(int age) {
		if (age >= 0) this->age = age;
	}

	float getAvarage() {
		float S		= 0;
		int	  count = 0;
		for (int i = 0; i < 10; ++i) {
			if (grades[i] >= 2 && grades[i] <= 6) {
				S += grades[i];
				++count;
			}
		}
		return S / count;
	}

	void addGrade(float grade) {
		for (int i = 0; i < 10; ++i) {
			if (grades[i] == 0) {
				grades[i] = grade;
				break;
			}
		}
	}
};

int main() {
	Student gosho = Student("Goshko", 15);

	std::cout << gosho.getName() << std::endl;

	gosho.addGrade(5);
	gosho.addGrade(4);
	std::cout << gosho.getAvarage() << std::endl;
}
