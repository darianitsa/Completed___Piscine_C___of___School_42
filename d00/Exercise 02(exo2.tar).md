# day 00 Exercise 02



- Создать файлы и директории с требуемым названием;
- Задать им требуемые из скриншота свойства и размер в байтах;

```
$> ls -l
total 42
drwx--xr-x 2 login wheel XX Jun 1 20:47 test0
-rwx--xr-- 1 login wheel  4 Jun 1 21:46 test1
dr-x---r-- 2 login wheel XX Jun 1 22:45 test2
-r-----r-- 2 login wheel  1 Jun 1 23:44 test3
-rw-r----x 1 login wheel  2 Jun 1 23:43 test4
-r-----r-- 2 login wheel  1 Jun 1 23:44 test5
lrwxr-xr-x 1 login wheel  5 Jun 1 22:20 test6 -> test0
$>
```

___



#### 1)Создадим две директории с названием `test0`:

	mkdir  test0

	mkdir  test2




#### 2)Создадим 4 файла с названием `test`:

	touch test{1,3,4,5}



#### 3)Создадим символьную ссылку с названием `test6` на директорию `test0`:

	ln -s test0 test6



#### 4)Зададим обьем нужных нам документов - запишем в них данные:
```
printf "1234" > ./test1

printf "1" > ./test3

printf "12" > ./test4

printf "1" > ./test5
```



#### 5)Установим дату на файлы и папки
```
touch -c -t 06012047  test0

touch -c -t 06012146  test1

touch -c -t 06012245  test2

touch -c -t 06012344  test3

touch -c -t 06012343  test4

touch -c -t 06012344  test5

touch -c -t 06012220  test6
```




#### 6)Установим права `чтения`/`записи`/`выполнения`:
```
chmod 715 ./test0

chmod 714 ./test1

chmod 504 ./test2

chmod 404 ./test3

chmod 641 ./test4

chmod 404 ./test5
```


#### 7)Проверка:

	ls -l


#### 8)Выполнив предыдущие шаги, выполните следующую команду, чтобы создать
файл для отправки из всех файлов в этой директории: 

	tar -cf exo2.tar *




## Документация.



Создание Файлов и управление их временем:

https://itproffi.ru/sozdanie-fajlov-v-linux-komanda-touch/

Установка прав чтения/записи/выполнения:

https://habr.com/ru/post/469667/

Запись данных в файл:

https://linux-notes.org/vstavit-tekst-v-fajl-v-unix-linux/

Джокеры:

https://habr.com/ru/post/99827/


