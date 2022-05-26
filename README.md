Базовые структуры и классы.

vector - шаблон касса вектор
имеет как конструктор по умолчанию, конструктор, который задаст длину, так и копирующий конструктор.
push_back(t) - добавление нового элемента со значение t в конец
[i] - образение к элементу под номером i  
claer() - очистка вектора
pop_back() - удаление последнего добавленного элемента. Возвращает его значение. если вектор пуст - выкидывает исключение с когдом -1
erase_by_index(i) - удаляет элемент, стоящий на позиции i
erase(t) - удаляет все элементы, значение которых совпадает с t
insert(t,p) - добавляет элемент со значение t на позицию p. Если p<0 или p больше размера вектора - элемент не добавляется
find(t) - возвращает индекс первого элемента, значение которого равно t
count(t) - возвращает кол-во элементов, значение которых = t
len() - возвращает длину вектора
isEmpty() - проверяет пуст ли вектор

stack - шаблок класса стэка, работающего по LIFO
имеет конструктор по умолчанию, так и копирующий
push(t) - добавление узла в конец
front() - получение данных из последнего добавленного узла. Если стэк пуст - выдает исключение -1.
pop() - удаление последнего узла. возвращает значение, хранящееся в узле. Если стэк пуст - выдает исключение -1
size() - возвращает длину стэка
isEmpty() - проверяет пуст ли стэк

queue - шаблон класса очерели, работающей по FIFO
имеет конструктор по умолчанию и копирующий конструктор
push(t) - добавляет узел в начало
pop() - удаление узла из конца. Возвращает значение, хранящееся в узла. Если очередь пуста - выдает исключение -1
back() - возвращает значение, хранящееся в последнем узле очереди. Если очередь пуста - выдает исключение -1
isEmpty() - проверяет пуста ли очередь
size() - возвращает размер очереди

deque - шаблон класса дека
имеет конструктор по умолчанию и копирующий конструктор 
front() - возвращает значение, хранящееся в "первом" узле. Если дек пуст - выдает исключение -1
back() - возвращает значение, хранящееся в "последнем" узле. Если дек пуст - выдает исключение -1
pop_fornt() - удаляет "первый" узел и возвращает значение, хранящееся в этом узле. Если дек пуст -выдает исключение -1
pop_back() - удаляет "последний" узел и возвращает значение, хранящееся в этом узле. Если дек пуст - выдает исключение -1
push_front(t) - добавляет узел со значение t в начало
push_back(t) - добавляет узел со значение t в конец
size() - возвращает размер дека
isEmpty() - проверяет пуст ли дек

ListOD - шаблон класса односвязного списка
имеет конструктор по умолчанию и копирующий конструктор
isEmpty() - проверяет пуст ли список
push_back(t) - добавляет узел со значением t в конец
push_front(t) -добавляет узел со значением t в конец
pop_front() - удаляет "первый" узел и возвращает значение, хранящееся в нем. Если список пуст - выдает исключение -1
pop_back() - удаляет "последний" узел и возвращает значение, хранящееся в нем. Если список пуст - выдает исключение -1
remove(t) - удаляет "первый" узел, значение которого равно t
front() - возвращает значение "первого" узла
back() - возвращает значение "последнего" узла
find(t) - возвращает указатель на "первый" узел со значением t
find_index(t) - возвращает индекс "первого" узла со значение t
insert(t,p) - вставляет узел со значение t на позицию p. если p<0 или не > индекс_последнего_элемента+1 - выдает исключение -1
[i] - возвращает ссылку на значение, хранящееся в узле под номером i

ListTD - шаблон класса двусвязного списка
имеет конструктор по умолчанию и копирующий конструктор
isEmpty() - проверяет пуст ли список
push_back(t) - добавляет узел со значением t в конец
push_front(t) -добавляет узел со значением t в конец
pop_front() - удаляет "первый" узел и возвращает значение, хранящееся в нем. Если список пуст - выдает исключение -1
pop_back() - удаляет "последний" узел и возвращает значение, хранящееся в нем. Если список пуст - выдает исключение -1
remove(t) - удаляет "первый" узел, значение которого равно t
front() - возвращает значение "первого" узла
back() - возвращает значение "последнего" узла
find(t) - возвращает указатель на "первый" узел со значением t
find_index(t) - возвращает индекс "первого" узла со значение t
insert(t,p) - вставляет узел со значение t на позицию p. если p<0 или не > индекс_последнего_элемента+1 - выдает исключение -1
[i] - возвращает ссылку на значение, хранящееся в узле под номером i

CTree - декартово дерево
insert(root, x) - добавление в дерево узла со значением x
erase(root, x) - удаление из дерева узла со значением x
exist(root,x) - проверка, есть ли узел с таки значением в дереве
ostream<<root - вывод дерева в стандартный поток вывода
depth(root) - возвращает высоту дерева
size(root) - возвращает кол-во узлов в дереве
get_by_index(root,i) - возвращает элемент в узле, находящемся на позиции i

AVLTree - АВЛ дерево
insert(root,key) - добавление узла в дерево со значением key
erase(root,key) - удаление узла из дерева со значением key
