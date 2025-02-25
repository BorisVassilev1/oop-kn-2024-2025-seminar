

class IAmClass {
	int iAmHidden;
	public:
	int helloWorld;
	private:
	float johnCena;
};

struct IAmStruct {
	int helloWorld;
	private:
	int iAmHidden;
	public:
	float donaldTrump;
};

class Counter {
	int x = 0;
	public:
	int get() const {return this->x;}
	void increment() {++this->x;}
	void set(int x) {
		this->x = x;
	}
};

int main() {

	IAmClass a;
	// a.iAmHidden = 10; // error
	a.helloWorld = 20;


	Counter c;
	c.increment();
}
