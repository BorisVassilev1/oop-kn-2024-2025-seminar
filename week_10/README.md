# Week 10: Бинарни файлове

## 1) Масив-файл
Създайте клас FileArray, който представя динамичен масив от цели числа. Конструктурът да приема име на файл. Масивът да се инициализира със данни от файла. При унищожаване на инстанция от тип FileArray, данните от масива да се записват във файла, указан в констуктора. Ако при инициализация е подаден невалиден, празен или несъществуващ файл, да се инициализира празен масив.
- създайте оператор "[]" за достъп до елементите на масива
- създайте подходящи конструктури и оператори за пълноценното използване на класа.

## 2) Читателски профил (MAL)

Напишете програма, която съхранява информация за читател и неговите прочетени книги (използвайте структурата данни от допълнителното упражнение). Следните подзадачи ще ви помогнат:
- създайте метод Book::serialize(), който записва данните за една книга във изходен поток.
- създайте конструктор за класа Book, който да приема поток за вход и инициализира книгата с данни от потока, записани във формата, определен от serialize(). Т.е. искаме да можем да възстановим обекта Book по информацията, която serialize() извежда.
- добавете метод Reader::serialize(), който записва всички данни на читателя (както и за книгите му) във поток.
- добавете конструктор на класа Reader, който да инициализира читателя (и неговите книги) с данни, прочетени от поток.
- Напишете програма, която тества гореописаните методи като създава инстанция на Reader traicho, записва я във файл, създава нова инстанция на Reader traicho_copy, използвайки информацията, записана във файла и накрая проверява дали traicho и traicho_copy са еднакви.
- Напишете програма, която работи върху конкретен файл, съдържащ данните на читател. 
    - При въвеждане на "new" на стандартния вход, програмата да зачиства всичката информация за текущия потребител и да въвежда името на нов читател.
    - При въвеждане на "list" на стандартния вход, програмата да изписва името на потребителя и информация на всичките книги, които е прочел.
    - При въвеждане на "add" на стандартния вход, програмата да въвежда информация за нова прочетена книга и да я добавя в списъка на читателя. 
    - всички промени да се отразяват във файла с данните на читателя след завършване на програмата.

