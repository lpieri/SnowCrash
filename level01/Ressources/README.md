# Level 01

Dans le `level01`, en ayant cat le fichier `/etc/passwd`, on a pu voir qu'un hash était présent pour l'utilisateur `flag01`.


```shell
~ cat /etc/passwd
[...]
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
[...]
```

Un indice nous est donné dans le `level00` : le fichier qui contient l'indice s'appelle `john`. De plus, la vidéo du projet nous parle de `John the Ripper`.

`John the Ripper` est un binaire qui permet de cracker un mot de passe à partir d'un hash de `/etc/passwd` ou/et `/etc/shadow`

Pour cela il faut crée un fichier `flag01pwd.txt` contenant l'user et le hash du password comme dans `/etc/passwd`.

`John` est une commande présente de base sur [Kali Linux](https://www.kali.org/), il nous faut donc lancer une VM Kali et d'executer `John` :

```shell
~ echo "flag01:42hDRfypTqqnw" > flag01pwd.txt
~ john --show flag01pwd.txt
flag01:abcdefg

1 password hash cracked, 0 left
```

Un fois `John` executé il nous reste plus qu'à nous connecter avec l'utilisateur `flag01` et récupérer le flag:

```shell
~ su flag01
~ getflag
Check flag.Here is your token : f2av5il02puano7naaf6adaaf
~ su level02
Password:
```

