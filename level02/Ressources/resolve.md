~> scp -P 4242 level02@192.168.56.101:level02.pcap .

~> open level with wireshark

~> in trame 43 data = "password:"

~> in the next trame data in hex = "66 74 5f 77 61 6e 64 72 7f 7f 7f 4e 44 52 65 6c 7f 4c 30 4c"

~> Decode hex = "ft_wandr...NDRel.L0L"

~> man ascii: 7f = delete char

~> Decode with delete char: ft_waNDReL0L

~> su flag03 (password: ft_waNDReL0L)

~> getflag
Check flag.Here is your token : kooda2puivaav1idi4f57q8iq

~> su level03
