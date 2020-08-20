# Level 00

Il a aucun fichier dans le home du user `level00`, nous commençons donc à explorer les dossiers à la racine.

Pour avoir la liste des users et des groupes existants nous avons fait un cat des fichiers `/etc/passwd` et `/etc/group`

Après un long moment de recherche, nous décidons de nous demander `On cherche quoi exactement ? Un fichier mais quoi ?`. Nous avons donc l'idée de rechercher un fichier appartenant au group `level00` ou `flag00` et quoi de mieux que `find` pour le faire ?

```shell
~ find /* -group flag00 2> /tmp/error
/rofs/usr/sbin/john
/usr/sbin/john
```

En recherchant les fichiers appartenant au groupe `flag00`, on trouve 2 fichier un dans le dossier parent `rofs` (une copie de l'ISO en read only) et un autre dans `/usr/sbin/john`. Les deux étant les même fichier, il suffit d'en cat un seul.

```shell
~ cat /usr/sbin/john
cdiiddwpgswtgt
```

Nous nous trouvons face à une chaîne de charactères pour le moins étrange, et nous en déduisons qu'il s'agit d'un ROT, ou un cryptage équivalent. En faisant un ROT 11, on tombe sur une phrase en anglais.

```
cdiiddwpgswtgt --rot11--> nottoohardhere
```

Nous venons de trouver le mot de passe de l'utilisateur `flag00`, il ne nous reste plus qu'a effectuer la commande `su flag00`, puis `getflag`.

```shell
~ su flag00
Password:
Dont forget to launch getflag !
~ getflag
Check flag.Here is your token : x24ti5gi3x0ol2eh4esiuxias
~ su level03
Password:
```

