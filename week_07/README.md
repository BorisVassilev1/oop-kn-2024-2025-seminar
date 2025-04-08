# Week 7: Unit Testing

## Doctest

Лесна за използване и бърза библиотека за тестване на C++. 

## Инсталаця: 

```cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN // optional
#include "doctest.h"
```

## Пример:

```cpp
// ...

TEST_CASE("Тест на функция") {
    int a = 5;
    int b = 10;
    CHECK(a + b == 15); // Проверка, че a + b е равно на 15
    CHECK_EQ(a + b, 15);
    CHECK_NEQ(a + b, 0);
    CHECK_GT(a, b); // Проверка, че a е по-голямо от b
}
```







