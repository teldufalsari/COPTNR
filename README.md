# СОРТИР 2.0

## Легендарная сортировка возвращается после долгого перерыва

Никто не ждал, не просил, но мы решили сделать то, что напрашивалось само собой - 
выпустить новую версию нашей сортировки, снабдив её невероятным количеством фичей.

Собственно,

## Фичи
- Алгоритм Quick Sort (сортировка Хоара), дающий среднюю сложность `O(n log(n))`
 вместо использованной ранее сортировки выбором сложностью `O(n^2)`.
- Распараллеливание! сортировки: Вы можете задать количество потоков в специальном скрипте,
поставляемом вместе с сортировкой. Не можете решиться? Не беда, СОРТИР сам разделит вычисление на
число потоков, равное числу ядер на вашей машине.
- Ввод из командной строки или из файла. У прошлой версии СОРТИР был один фатальный недостаток:
ввод массива для сортитровки не был предусмотрен, в связи с чем после запуска создавался
случайный массив, который затем сортитровался. В новой версии вы можете ввести ввести массив
из командной строки, либо из файла, причём в последнем случае СОРТИР сам сосчитает числа;
указывать размер массива явно не нужно. Скучаете по старому режиму работы? Специально для Вас
мы приложили скрипт на Python, запускающий СОРТИР и подающий ему на вход случайно сгенерированный
массив: просто запустите и наслаждайтесь
- Прошлая версия была написана на Pascal, из-за чего производительность страдала даже не беря в
расчёт недостатки алгоритма. СОРТИР 2.0 написан на Си, а приложенный скрипт сборки для системы
GNU Make скомпилирует код со всеми возможными оптимизациями прямо под вашу машину.

## Почему СОРТИР
- Удобный интерфейс
- Богатый набор функций (для сортировки-то)
- Непревзойдённая скорость
- Фирменное лого


# СОРТИР 2.0
### ПРОВЕРЕНО. СОРТИРУЕТ

## Как собрать

Просто склонируйте репозиторий и запустите make. Нет ошибок? Всё собралось, можно сортировать :) Есть ошибки компиляции? Проверьте, что все зависимости установлены, и снова запустите make. Всё ещё не компилируется? Напишите в нашу техподдержку, мы что-нибудь придумаем.

## Как запустить

### Ввод чисел из командной строки 
Для этого запустите скрипт

`./cli.sh N [N_threads]`

где `N` - количество чисел, которое Вы собираетесь отсортировать, а `N_threads` - число потоков (опциональный аргумент, по умолчанию число потоков равно числу ядер Вашего процессора). Теперь введите `N` чисел, нажмите `enter` и наслаждайтесь.

### Ввод чисел из командной строки

Запустите скрипт

`./file.sh file [N_threads]`

В файле `file` должны быть через пробел записаны целые числа (не более 10000). `N_treads`, как и в случае с командной строкой, аргумент необязательный.

### Сортировка случайного массива

Просто запустите скрипт `./sortir.py` и наслаждайтесь.

## Зависимости

- `gcc`  версии не ниже `10` или `clang` не ниже `11`
- `make` версии `3.x` и выше
- `openmp` версии не ниже `3.0`
- `python3.x` для работы скрипта-генератора массива