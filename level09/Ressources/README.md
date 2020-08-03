# Level 09

Comme pour le `level08`, il y a 2 fichiers un binaire et un fichier token.

Cette fois nous avons les droits de lecture sur le fichier `token`.

```sh
~ cat token
f4kmm6p|=�p�n��DB�Du{��
```

Il contient des caractère ilisible donc ça ne peux pas être le `flag`.

Le binaire `level09` prend un paramêtre et le transforme en un truc ilisible.

```sh
~ ./level09 token
tpmhr
```

En décompilant le binaire on comprend que `level09` ajoute l'index à chaque `char` de l'argument et l'affiche:

Pour rendre le token lisible il nous suffit alors de faire l'inverse du binaire `level09`.

```sh
~ scp -P 4242 flag09.c level09@192.168.56.101:/tmp
~ gcc /tmp/flag09.c -o /tmp/flag09
~ /tmp/flag09 `cat token`
f3iji1ju5yuevaus41q1afiuq
~ su flag09
Password:
Don\'t forget to launch getflag !
~ getflag
Check flag.Here is your token : s5cAJpM8ev6XHw998pRWG728z
```

