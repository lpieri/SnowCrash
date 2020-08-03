# Level 00

Il a aucun fichier dans le home de l'user `level00`, nous commençons donc à explorer l'ISO.

Pour avoir la liste des users, des groups existant nous avons fait un cat des fichiers `/etc/passwd` et `/etc/group`

Après un long moment de recherche on se demande `On cherche quoi exactement ? Un fichier mais quoi ?`. On as donc l'idée de rechercher un fichier appartenant au group `level00` ou `flag00` et quoi de mieux que `find` pour le faire ?

```shell
~ find /* -group flag00 2> /tmp/error
/rofs/usr/sbin/john
/usr/sbin/john
```

Avec la recherche de fichier appartenant au groupe `flag00` on trouve 2 fichier un dans le dossier parent `rofs` (une copie de l'ISO en read only) et un autre dans `/usr/sbin/john`, les deux étant les même fichier il suffit d'en cat un seul

```shell
~ cat /usr/sbin/john
cdiiddwpgswtgt
```

On trouve alors un mot bizarre et on se dit que ça doit être un ROT13 (un truc du style), en fessant un ROT 11 on peut trouver quelque chose de lisible

```
cdiiddwpgswtgt --rot11--> nottoohardhere
```

Nous venons de trouver le mot de passe de l'utilisateur `flag00`, il ne nous reste plus qu'a se `su flag00` et `getflag`.

```shell
~ su flag00
Password:
Dont forget to launch getflag !
~ getflag
Check flag.Here is your token : x24ti5gi3x0ol2eh4esiuxias
~ su level03
Password:
```

