# Level 14

Pour le dernier niveau, aucun fichier n'appartient au à `flag14` ou à `level14` et aucun fichier n'est dans le home...

Pourtant, un utilisateur `flag14` existe, on suppose donc qu'il doit avoir un flag à récupérer.

Mais le seul moyen de le récupérer est d'exploiter le fameux binaire `getflag`.

Comme pour le niveau précendent nous avons utilisé `gdb`. C'est un peu près la même manipulation que le niveau précédent, sauf qu'ici nous devons modifier aussi la sortie de `ptrace` pour que `eax` soit égal à `0`.

```sh
~$ gdb getflag
(gdb) disassemble main
[...]
   0x08048989 <+67>:	call   0x8048540 <ptrace@plt>
   0x0804898e <+72>:	test   %eax,%eax
   0x08048990 <+74>:	jns    0x80489a8 <main+98>
[...]
   0x08048afd <+439>:	call   0x80484b0 <getuid@plt>
   0x08048b02 <+444>:	mov    %eax,0x18(%esp)
[...]
(gdb) break *0x0804898e
Breakpoint 1 at 0x804898e
(gdb) break *0x08048b02
Breakpoint 2 at 0x8048b02
(gdb) r
Starting program: /bin/getflag

Breakpoint 1, 0x0804898e in main ()
(gdb) set $eax = 0
(gdb) s
Single stepping until exit from function main,
which has no line number information.

Breakpoint 2, 0x08048b02 in main ()
(gdb) set $eax = 0xbc6
(gdb) s
Single stepping until exit from function main,
which has no line number information.
Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
```



