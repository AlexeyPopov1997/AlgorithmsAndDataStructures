# Спровочник по Python

## Содержание
### 1. [Лямда-функции](#Лямда-функции)
### 2. [Декораторы](#Декораторы)
####    * [Полезные декораторы](#Полезные-декораторы)

## Лямда-функции
Ключевое слово `lambda` в Python предоставляет краткую форму для объявления небольших анонимных функций. Лямбда-функции ведут себя точно так же, как обычные функции, объявляемые ключевым словом `def`. Они могут использоваться всякий раз, когда требуются объекты-функции.

Например, ниже показано определение простой лямбда-функции, выполняющей сложение:

 ```python
add = lambda x, y: x + y

add(5, 3) 
 ```

Та же самая функция `add` может быть определена при помощи ключевого слова `def`, но она была бы чуть-чуть многословнее:

 ```python
def add(x, y):
    return x + y

add(5, 3) 
 ```

С помощью лямда-функции можно определить однострочную функцию `add`, а затем немедленно вызвать ее с аргументами `5` и `3`:

 ```python
 (lambda x, y: x + y)(5, 3)
 ```

Основное отличие лямда-функций в том, что перед её использованием не приходится связывать объект-функцию с именем.

Существует еще одно синтаксическое различие между определениями лямбд и обычных функций. Лямбда-функции ограничены одним-единственным выражением. Это означает, что в лямбда-функциях не могут применяться инструкции или аннотации — и даже инструкция `return`.

При исполнении лямбда-функции ее выражение вычисляется и затем результат выражения автоматически возвращается, поэтому всегда существует **неявная** инструкция `return`.

Вот еще одна интересная вещь о лямбдах: как и обычные вложенные функции, лямбды работают также и как **лексические замыкания**.

**Замыкание** - это лишь затейливое название для функции, которая помнит значения из объемлющего лексического контекста, даже когда поток управления программы больше не находится в этом контексте:

 ```python
def make_adder(n):
    return lambda x: x + n

plus_3 = make_adder(3)
plus_5 = make_adder(5)

plus_3(4)
plus_5(4) 
 ```

* **Лямбда-функции — это функции одного-единственного выражения, которые не обязательно привязаны к имени (анонимны).**
* **В лямбда-функциях нельзя использовать обычные инструкции `Python`, и в них всегда содержится неявная инструкция возврата `return`.**
* **Всегда спрашивайте себя: обеспечит ли применение обычной (именованной) функции либо конструкции включения в список большую ясность?**

#### Используемые материалы:
1) Лямбды — это функции одного выражения - Чистый Puthon (Дэн Бейдер)


## Декораторы

**Функции в python являются объектами**, соответственно, их можно возвращать из другой функции или передавать в качестве аргумента. Также следует помнить, что функция в python может быть определена и внутри другой функции.

**Декораторы** — это, по сути, "обёртки", которые дают нам возможность изменить поведение функции, не изменяя её код.

 ```python
def decorator(function_to_decorate):
    # Внутри себя декоратор определяет функцию-"обёртку". Она будет обёрнута вокруг декорируемой,
    # получая возможность исполнять произвольный код до и после неё.
    def the_wrapper_around_the_original_function():
        print("Я - код, который отработает до вызова функции")
        function_to_decorate() # Сама функция
        print("А я - код, срабатывающий после")
        # Вернём эту функцию
        return the_wrapper_around_the_original_function

# Представим теперь, что у нас есть функция, которую мы не планируем больше трогать.
def stand_alone_function():
    print("Я простая одинокая функция, ты ведь не посмеешь меня изменять?")

stand_alone_function()

# Однако, чтобы изменить её поведение, мы можем декорировать её, то есть просто передать декоратору,
# который обернет исходную функцию в любой код, который нам потребуется, и вернёт новую,
# готовую к использованию функцию:
stand_alone_function_decorated = decorator(stand_alone_function)
stand_alone_function_decorated()
```

Для того, чтобы каждый раз, во время вызова `stand_alone_function`, вместо неё вызывалась `stand_alone_function_decorated` нужно перезаписать `stand_alone_function`:

```python
stand_alone_function = decorator(stand_alone_function)
stand_alone_function()
```

Используя синтаксис декораторов, предыдущий пример можно записать следующим образом:

```python
@mdecorator
def another_stand_alone_function():
    print("Оставь меня в покое")

another_stand_alone_function()
```

То есть, **декораторы в python — это просто синтаксический сахар** для конструкций вида:

```python
another_stand_alone_function = decorator(another_stand_alone_function)
```

Можно использовать несколько декораторов для одной функции:

```python
def bread(func):
    def wrapper():
        print()
        func()
        print("<\______/>")
    return wrapper

def ingredients(func): 
    def wrapper():
        print("#помидоры#")
        func()
        print("~салат~")
    return wrapper

def sandwich(food="--ветчина--"):
    print(food)

sandwich = bread(ingredients(sandwich))
sandwich()
```

И используя синтаксис декораторов:

```python
@ingredients
@bread
def sandwich(food="--ветчина--"):
    print(food)

sandwich()
```

### Передача декоратором аргументов в функцию

```python
def a_decorator_passing_arguments(function_to_decorate):
    def a_wrapper_accepting_arguments(arg1, arg2):
        print("Смотри, что я получил:", arg1, arg2)
        function_to_decorate(arg1, arg2)
    return a_wrapper_accepting_arguments

# Теперь, когда мы вызываем функцию, которую возвращает декоратор, мы вызываем её "обёртку",
# передаём ей аргументы и уже в свою очередь она передаёт их декорируемой функции
@a_decorator_passing_arguments
def print_full_name(first_name, last_name):
    print("Меня зовут", first_name, last_name)
    
print_full_name("Vasya", "Pupkin")
```

### Декорирование методов

```python
def a_decorator_passing_arguments(function_to_decorate):
    def a_wrapper_accepting_arguments(arg1, arg2):
        print("Смотри, что я получил:", arg1, arg2)
        function_to_decorate(arg1, arg2)
    return a_wrapper_accepting_arguments

# Теперь, когда мы вызываем функцию, которую возвращает декоратор, мы вызываем её "обёртку",
# передаём ей аргументы и уже в свою очередь она передаёт их декорируемой функции
@a_decorator_passing_arguments
def print_full_name(first_name, last_name):
    print("Меня зовут", first_name, last_name)
    
print_full_name("Vasya", "Pupkin")
```

### Декорирование методов

Один из важных фактов, которые следует понимать, заключается в том, что функции и методы в `Python` — это практически одно и то же, за исключением того, что методы всегда ожидают первым параметром ссылку на сам объект (`self`). Это значит, что мы можем создавать декораторы для методов точно так же, как и для функций, просто не забывая про `self`.

```python
def method_friendly_decorator(method_to_decorate):
    def wrapper(self, lie):
        lie -= 3
        return method_to_decorate(self, lie)
    return wrapper

class Lucy:
    def __init__(self):
        self.age = 32
        
        @method_friendly_decorator
        def sayYourAge(self, lie):
            print("Мне {} лет, а ты бы сколько дал?".format(self.age + lie))

l = Lucy()
l.sayYourAge(-3)
```

Конечно, если мы создаём максимально общий декоратор и хотим, чтобы его можно было применить к любой функции или методу, то можно воспользоваться распаковкой аргументов:

```python
def a_decorator_passing_arbitrary_arguments(function_to_decorate):
    # Данная "обёртка" принимает любые аргументы
    def a_wrapper_accepting_arbitrary_arguments(*args, **kwargs):
        print("Передали ли мне что-нибудь?:")
        print(args)
        print(kwargs)
        function_to_decorate(*args, **kwargs)
    return a_wrapper_accepting_arbitrary_arguments

@a_decorator_passing_arbitrary_arguments
def function_with_no_argument():
    print("Python is cool, no argument here.")

function_with_no_argument()

@a_decorator_passing_arbitrary_arguments
def function_with_arguments(a, b, c):
    print(a, b, c)

function_with_arguments(1, 2, 3)

@a_decorator_passing_arbitrary_arguments
def function_with_named_arguments(a, b, c, platypus="Почему нет?"):
    print("Любят ли {}, {} и {} утконосов? {}".format(a, b, c, platypus))

function_with_named_arguments("Билл", "Линус", "Стив", platypus="Определенно!")

class Mary(object):
    def __init__(self):
        self.age = 31
        
        @a_decorator_passing_arbitrary_arguments
        def sayYourAge(self, lie=-3): # Теперь мы можем указать значение по умолчанию
            print("Мне {} лет, а ты бы сколько дал?".format(self.age + lie))

m = Mary()
m.sayYourAge()
```

### Декораторы с аргументами

А теперь попробуем написать декоратор, принимающий аргументы:

```python
def decorator_maker():
    print("Я создаю декораторы! Я буду вызван только раз: когда ты попросишь меня создать декоратор.")
    def my_decorator(func):
        print("Я - декоратор! Я буду вызван только раз: в момент декорирования функции.")
        def wrapped():
            print ("Я - обёртка вокруг декорируемой функции.\n"
                   "Я буду вызвана каждый раз, когда ты вызываешь декорируемую функцию.\n"
                   "Я возвращаю результат работы декорируемой функции.")
            return func()
        print("Я возвращаю обёрнутую функцию.")
        return wrapped
    print("Я возвращаю декоратор.")
    return my_decorator

# Давайте теперь создадим декоратор. Это всего лишь ещё один вызов функции
new_decorator = decorator_maker()

 Теперь декорируем функцию
def decorated_function():
    print("Я - декорируемая функция.")

decorated_function = new_decorator(decorated_function)

# Теперь наконец вызовем функцию:
decorated_function()
```

Теперь перепишем данный код с помощью декораторов:

```python
def decorator_maker_with_arguments(decorator_arg1, decorator_arg2):
    print("Я создаю декораторы! И я получил следующие аргументы:", decorator_arg1, decorator_arg2)
    
    def my_decorator(func):
        print("Я - декоратор. И ты всё же смог передать мне эти аргументы:", decorator_arg1, decorator_arg2)
        
        # Не перепутайте аргументы декораторов с аргументами функций!
        def wrapped(function_arg1, function_arg2):
            print ("Я - обёртка вокруг декорируемой функции.\n"
                   "И я имею доступ ко всем аргументам\n"
                   "\t- и декоратора: {0} {1}\n"
                   "\t- и функции: {2} {3}\n"
                   "Теперь я могу передать нужные аргументы дальше"
                   .format(decorator_arg1, decorator_arg2, function_arg1, function_arg2))
            return func(function_arg1, function_arg2)
        return wrapped
    return my_decorator

@decorator_maker_with_arguments("Леонард", "Шелдон")
def decorated_function_with_arguments(function_arg1, function_arg2):
    print ("Я - декорируемая функция и я знаю только о своих аргументах: {0}"
           " {1}".format(function_arg1, function_arg2))

decorated_function_with_arguments("Раджеш", "Говард")
```

Таким образом, мы можем передавать декоратору любые аргументы, как обычной функции. Мы можем использовать и распаковку через `*args` и `**kwargs` в случае необходимости.

### Некоторые особенности работы с декораторами

* Декораторы несколько замедляют вызов функции, не забывайте об этом.
* Вы не можете "раздекорировать" функцию. Безусловно, существуют трюки, позволяющие создать декоратор, который можно отсоединить от функции, но это плохая практика. Правильнее будет запомнить, что если функция декорирована — это не отменить.
* Декораторы оборачивают функции, что может затруднить отладку.

Последняя проблема частично решена добавлением в модуле `functools` функции `functools.wraps`, копирующей всю информацию об оборачиваемой функции (её имя, из какого она модуля, её документацию и т.п.) в функцию-обёртку.

```python
def foo():
    print("foo")

print(foo.__name__)

# Однако, декораторы мешают нормальному ходу дел:
def bar(func):
    def wrapper():
        print("bar")
        return func()
    return wrapper

@bar
def foo():
    print("foo")

print(foo.__name__)

import functools  # "functools" может нам с этим помочь
def bar(func):
    # Объявляем "wrapper" оборачивающим "func" и запускаем магию:
    @functools.wraps(func)
    def wrapper():
        print("bar")
        return func()
    return wrapper

@bar
def foo():
    print("foo")

print(foo.__name__)
```

### Примеры использования декораторов

Декораторы могут быть использованы для расширения возможностей функций из сторонних библиотек (код которых мы не можем изменять), или для упрощения отладки (мы не хотим изменять код, который ещё не устоялся).

Также полезно использовать декораторы для расширения различных функций одним и тем же кодом, без повторного его переписывания каждый раз, например:

```python
def benchmark(func):
    """
    Декоратор, выводящий время, которое заняло
    выполнение декорируемой функции.
    """
    import time
    def wrapper(*args, **kwargs):
        t = time.clock()
        res = func(*args, **kwargs)
        print(func.__name__, time.clock() - t)
        return res
    return wrapper

def logging(func):
    """
    Декоратор, логирующий работу кода.
    (хорошо, он просто выводит вызовы, но тут могло быть и логирование!)
    """
    def wrapper(*args, **kwargs):
        res = func(*args, **kwargs)
        print(func.__name__, args, kwargs)
        return res
    return wrapper

def counter(func):
    """
    Декоратор, считающий и выводящий количество вызовов
    декорируемой функции.
    """
    def wrapper(*args, **kwargs):
        wrapper.count += 1
        res = func(*args, **kwargs)
        print("{0} была вызвана: {1}x".format(func.__name__, wrapper.count))
        return res
    wrapper.count = 0
    return wrapper

@benchmark
@logging
@counter
def reverse_string(string):
    return ''.join(reversed(string))

print(reverse_string("А роза упала на лапу Азора"))

print(reverse_string("A man, a plan, a canoe, pasta, heros, rajahs, a coloratura,"
                     "maps, snipe, percale, macaroni, a gag, a banana bag, a tan, a tag,"
                     "a banana bag again (or a camel), a crepe, pins, Spam, a rut, a Rolo, cash,"
                     "a jar, sore hats, a peon, a canal: Panama!"))
```

#### Используемые материалы:
1) [Декораторы - pythonworld.ru](https://pythonworld.ru/osnovy/dekoratory.html)

#### Полезные декораторы

#### Свойства @property

Декоратор `@property` облегчает создание свойств в классах `Python`. Свойства выглядят как обычные атрибуты (поля) класса, но при их чтении вызывается геттер (`getter`), при записи – сеттер (`setter`), а при удалении – делитер (`deleter`). Геттер и делитер опциональны.

Свойства нужны, чтобы элегантно в стиле ООП обрабатывать работу с полями класса. В ООП с полями класса не работают напрямую, они сокрыты. В интерфейс взаимодействия выводятся геттеры и сеттеры. Кроме того, геттер может производить вычисления, если свойство не хранится в классе, а является результатом какой-то математической формулы. А сеттер может проверять входные данные на корректность и вызывать побочные эффекты, например, сеттер при установке позиции картинки на экране может вызвать перерисовку экрана.

Декоратор `@property` возвращает объект-дескриптор. `@property` встроен и виден без `import`.

```python
class Box:
    def __init__(self):
        self.__weight = 0

    @property
    def weight(self):
        return self.__weight

    @weight.setter
    def weight(self, new_weight):
        if new_weight < 0:
            raise ValueError('negative weight')
        self.__weight = new_weight


b = Box()
b.weight = 100
print(b.weight)  # 100
b.weight = -10  # ValueError
```

Вычислимое свойство:

```python
class Circle:
    def __init__(self, r):
        self.r = r

    @property
    def area(self):
        return 3.1415 * self.r**2


c = Circle(10)
print(c.area)
```

#### Статические и классовые методы

Методы могут быть не только у экземпляра класса, но и у самого класса, которые вызываются без какого-то экземпляра (без `self`). Декораторы `@staticmethod` и `@classmethod` как раз делают метод таким (**статическим** или **классовым**). Эти декораторы встроены и видны без `import`.

**Статический метод** – это способ поместить функцию в класс, если она логически относится к этому классу. Статический метод ничего не знает о классе, из которого его вызвали.

```python
class Foo:
    @staticmethod
    def help():
        print('help for Foo class')


Foo.help()
```

**Классовый метод** напротив знает, из какого класса его вызывают. Он принимает неявный первый аргумент (обычно его зовут `cls`), который содержит вызывающий класс. Классовые методы прекрасно подходят, когда нужно учесть иерархию наследования. Пример: метод `group` создает список из нескольких людей. Причем для `Person` – список `Person`, а для `Worker` – список `Worker`. Со `@staticmethod` такое бы не вышло:

```python
class Person:
    @classmethod
    def group(cls, n):
        # cls именно тот класс, который вызвал
        return [cls() for _ in range(n)]

    def __repr__(self):
        return 'Person'


class Worker(Person):
    def __repr__(self):
        return 'Worker'


print(Person.group(3))
# [Person, Person, Person]

print(Worker.group(2))
# [Worker, Worker]
```

#### Кэширование @lru_cache

Запоминает результаты функции для данного набора аргументов, при следующем вызове уже не выполняет функцию, а достает результат из кэша. Размер кэша регулируется. Часто используемые элементы остаются в кэше, редкие – вытесняются, если размер доходит до максимального.

Пример. Без кэша это рекурсивная функция чисел Фибоначчи была бы крайне неэффективна:

```python
import functools

@functools.lru_cache(maxsize=128)
def fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    return fibonacci(n - 1) + fibonacci(n - 2)
```

#### @functools.wraps

Декоратор `@functools.wraps` полезен при разработке других декораторов. Передает имя, документацию и прочую мета-информацию из декорируемой функции к ее обертке.

#### Используемые материалы:
1) [Полезные декораторы - tirinox.ru](https://tirinox.ru/useful-decorators/)