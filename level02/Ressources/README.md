# Level 02

Quand on se connecte à l'utilisateur `level02` nous trouvons un fichier `level02.pcap`.

Un fichier `pcap` est un fichier de captures des trames réseaux, on peux l'ouvrir par exemple avec `Wireshark`.

Lorsque on l'ouvre avec `Wireshark` on vois plein de trames réseaux, en examinant un peu plus les trames on peux voir dans la section `data` une demande de password avec des trames suivantes contenant des enregistrements de clavier `Password:....` `

Les entrées du clavier donne `ft_wandr...NDRel.L0L` `Wireshark` remplace les charactères pas imprimable en `.`. Ces `.` dans la partie hex de `Wireshark` sont égaux à `7f`. Selon `man ascii`, `7f` est le charactères est égal à `delete`

En supprimants les charactères supprimés par `delete` le mot de passe est égal à `ft_waNDReL0L`. Nous pouvons donc nous connecter à `flag02` et récupérer le flag:

```sh
~ su flag02
Password: 

~ getflag
Check flag.Here is your token : kooda2puivaav1idi4f57q8iq
```