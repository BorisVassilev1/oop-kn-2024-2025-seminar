## 1) Задача
Напишете на клас Vector, който представя масив от цели числа, чиито размер по начало е `0`. Да се реализира
- да има метод, която достъпва `i`-тия елемент на масива
- да има метод, която връща размера на масива
- да има метод, която добавя елемент в края на масива
- да има метод, която приема указател към масив и размер, като добавя съответните елементи в края на масива.
- да се реализира конструктор, който приема размер `s` и константа `t`, и запълва масива с `s` на брой стойности `t`.
- да се реализира метод, който копира някаква подредица от масива в нов Vector (от индекс `i` до индекс `j`)
- да се реализира метод, който сортира масива спрямо подадена функция $f: int \times int -> \{0, 1\}$, която да играя ролята на сравнение $<$.

## 2) Бонус
Използвайте типа Vector за да реализирате функция `map`, която приема масив, както и функция, която да приложи върху всеки от елементите на масива. Да се връща нов масив (не непременно от същия тип като изходния), който съдържа резултатите след прилагането на функцията.

Пример:
```cpp
Vector<int> arr(10);
for(std::size_t i = 0; i < arr.size(); ++i) {
	arr.get(i) = i;
}
Vector<float> res = map<int, float>(arr, [](int x) -> float {return std::sqrt(x);});
// 0 1 1.41421 1.73205 2 2.23607 2.44949 2.64575 2.82843 3
```
Ако изпращате тази задача като домашно, отделете функцията `map` в отделен хедър файл. Предайте също и своята имплементация на Vector. Помислете и защо не можем тук да ползваме UncopiableArray?
