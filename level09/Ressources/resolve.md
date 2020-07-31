level09 ajoute l'index du char acteul dans la string a ce char et le print
token est le resultat de level09 du password flag09
il suffit de faire un binaire qui fait l'inverse

scp -P 4242 flag09.c level09@192.168.56.101:/tmp

gcc /tmp/flag09.c -o /tmp/flag09

level09@SnowCrash:~$ /tmp/flag09 `cat token`
f3iji1ju5yuevaus41q1afiuq

level09@SnowCrash:~$ su flag09
Password:
Don't forget to launch getflag !

flag09@SnowCrash:~$ getflag
Check flag.Here is your token : s5cAJpM8ev6XHw998pRWG728z

flag09@SnowCrash:~$ su level10
Password:
