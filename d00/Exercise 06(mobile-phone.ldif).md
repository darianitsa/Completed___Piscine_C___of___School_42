# day 00 Exercise 06

 - Теперь, когда вы являетесь экспертом по LDAP, вы сможете добавить свой номер телефона в область мобильной связи.
 - Добавьте свой реальный номер: как с вами связаться! Ваши будущие товарищи по команде будут рады узнать!
 - Чтобы проверить, сработала ли ваша команда, попробуйте поискать себя на LDAP!
 - Не стесняйтесь заполнять другие поля, если вы готовы. у вас нет всех прав, мы не идиоты;)
 - Вы можете изменить свой адрес электронной почты в любое время через поле "адрес электронной почты".


#### Вот шаблон файла LDIF:
```
dn: uid=pnom,ou=people,dc=42,dc=fr

changetype: modify

delete: pouette
```

---
---
---

#### Создайте файл

    touch mobile-phone.ldif



#### Поиск  пользователя boris:

    ldapsearch -b "o=home, c=sys" "uid=boris"


#### ИЛИ 

    ldapsearch -Q uid=boris 

> #### `slapcat` команда выводит содержимое базы данных объектов.

#### Хотя в интернете достаточно много статей по настройке `LDAP`, где рекомендуют отредактировать `ldif-файлы` схемы, это делать не нужно, более того, в самих файлах указан комментарий о том, что файлы нельзя редактировать вручную и необходимо для редактирования использовать команду ldapmodify. 

> #### Утилита командной строки `ldapmodify` используется для отправки операции модификации на ваш сервер `LDAP`. Этот инструмент принимает `LDIF` в качестве входных данных. См. `RFC 2849` для спецификации `LDIF`, особенно посмотрите на примеры.

#### Пример фрагмента `LDIF` для добавления номера мобильного телефона в существующую запись, если заданное  значение отсутствует в атрибуте mobile:  


```
uid=pnom,ou=people,dc=42,dc=fr

changetype: modify

add: mobile

mobile: +1 2345 6789

-
```


#### Следующее заменяет полный атрибут и его значения двумя указанными значениями:


```
uid=pnom,ou=people,dc=42,dc=fr

changetype: modify

replace: mobile

mobile: +1 2345 6789

mobile: +4 567 89012345

-
```


#### Следующее удалит ровно одно конкретное значение из атрибута (delete-by-value):


```
uid=pnom,ou=people,dc=42,dc=fr

changetype: modify

delete: mobile

mobile: +4 567 89012345

-
```


---
---
---


## Документация:


`LDAP` инструменты

https://pro-ldap.ru/tr/zytrax/ch14/

https://serverfault.com/questions/922114/add-a-mobile-number-to-ldap-mobile-field

https://www.ibm.com/support/knowledgecenter/ru/ssw_ibm_i_72/rzahy/rzahyldapadd.htm


https://mnorin.com/ldap-ustanovka-i-nastrojka-ldap-servera.html



`LDIF` формат

https://www.8host.com/blog/vnesenie-izmenenij-v-sistemu-openldap-s-pomoshhyu-fajlov-ldif/




wiki.dvo.ru/wiki/Инструкция_по_управлению_пользователями_LDAP

https://ru.wikipedia.org/wiki/LDAP

https://www.opennet.ru/base/net/ldap_auth2.txt.html

https://gremlinable.livejournal.com/31645.html

https://stackoverflow.com/questions/49249834/ldap-add-telephone-number

http://www.redmine.org/projects/redmine/wiki/RedmineLDAP
