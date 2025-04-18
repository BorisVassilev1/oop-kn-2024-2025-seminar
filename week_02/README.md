# 2) Enum, class, методи

## Enum (изброен тип)

```cpp
enum Color : int {
	RED,
	GREEN,
	BLUE,
	CYAN,
	MAGENTA,
	YELLOW,
	PINK,
	PURPLE
};
```

_!! Enum-ите винаги са целочислени_

## Class, Struct

```cpp
class IAmClass {
	int iAmHidden;
	public:
	int helloWorld;
	private:
	float johnCena;
};
```

```cpp
struct IAmStruct {
	int helloWorld;
	private:
	int iAmHidden;
	public:
	float donaldTrump;
}
```

В класовете, полетата и методите по подразбиране са частни (private), а в структурите, по подразбиране са публични (public).

## Методи

Можем да дефинираме и функции към типовете, които дефинираме. По изключение, в изброимите типове (енъмите) не можем да дефинираме такива, но в структури, класове и обединения можем.

```cpp
class Dog {
	int soundCount = 0;
	void onSoundMade() {
		++this->soundCount;
	}

	public:
	void bark() {
		std::cout << "Bow" << std::endl;
		onSoundMade();
	}
	void woof() {
		std::cout << "Woof" << std::endl;
		onSoundMade();
	}
};
```

_!!функция, дефинирана в клас, наричаме метод_

### Константни методи

```cpp
class Counter {
	int x = 0;
	public:
	int get() const {return this->x;}
	void increment() {++this->x;}
}
```

Константните методи могат да бъдат извиквани върху константни инстанции на класа. Тоест

```cpp
const Counter c;
c.increment() 	// error
c.get(); 		// ok
```

### Аксесори и Мутатори (get, set)

Методи, служещи за достъпване и подмяна на частни член-данни данни наричаме аксесори и мутатори. Такива са ни нужни когато е нужно член-данните да отговарят на условия (инварианти), които потребителя е възможно да наруши (например да промени възрастта на ученик на отрицателно число).

## Задачи

### 1)

Имплементирайте клас Ученик, определящ се от име (до 50 символа), възраст, и няколко (до 10) оценки. При инициализация ученикът няма оценки.

- Имплементирайте подходящи селектори и мутатори.
- Имплементирайте метод, който връща средната оценка на ученика (ако няма такива тя е -1).
- Имплементирайте метод, който добавя оценка. Методът да не позволява добавянето на повече от 10 оценки.

### 2)

Създайте клас Банкова Сметка, съдържаща указател към Ученик - собственик, както и баланс в лева.

- Имплементирайте подходящи селектори и мутатори (без мутатор за баланса тъй като искаме той да бъде модифициран само чрез преводи).
- Създайте метод, преврърлящ сума в лева от една банкова сметка в друга. Ако това е невъзможно, функцията да оставя двете банкови сметки непроменени.
```cpp
BankAccount::transfer(BankAccount &other, float amount)
```
- Създайте аналогичен метод, който прехвърля сума в евро.

### Домашно
Добавете към класа от задача (2) опцията да прехвърляме суми от една сметка в друга при произволна валута, тоест подобен код да е валиден.
```cpp
Student Gosho{"Gosho", 21};
BankAccount a{&Gosho, 100}, b{&Gosho, 100}
a.transfer(b, 100, Currency::BGN);
b.transfer(a, 50, Currency::EUR);
a.print(std::cout);	// Owner: Gosho, Balance: 97.80 BGN
b.print(std::out);	// Owner: Gosho, Balance: 102.20 BGN
```
