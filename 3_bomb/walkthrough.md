# Bomb:

```Shell
cat README
Diffuse this bomb!
When you have all the password use it as "thor" user with ssh.

HINT:
P
 2
 b

o
4

NO SPACE IN THE PASSWORD (password is case sensitive).
```

## Phase 1:

`Public speaking is very easy.`

## Phase 2:

`1 2 6 24 120 720`

## Phase 3:

`0 q 777`
`1 b 214`
`2 b 755`
`3 k 251`
`4 o 160`
`5 t 458`
`6 v 780`
`7 b 524`

## Phase 4:

`9`

## Phase 5:

`OPEKMA`
`OPUKMA`
`OPUKMQ`
`OPEKMQ`

## Phase 6:

Get the value of Node:

```Shell
laurie@BornToSecHackMe:~$ gdb bomb
...
(gdb) b main
Breakpoint 1 at 0x80489b7: file bomb.c, line 36.
(gdb) r
Starting program: /home/laurie/bomb

Breakpoint 1, main (argc=1, argv=0xb7fd0ff4) at bomb.c:36
36      bomb.c: No such file or directory.
(gdb) p &node1
$1 = (<data variable, no debug info> *) 0x804b26c
(gdb) x/4xw 0x804b26c
0x804b26c <node1>:      0x000000fd      0x00000001      0x0804b260      0x000003e9
(gdb) x/4xw 0x0804b260
0x804b260 <node2>:      0x000002d5      0x00000002      0x0804b254      0x000000fd
(gdb) x/4xw 0x0804b254
0x804b254 <node3>:      0x0000012d      0x00000003      0x0804b248      0x000002d5
(gdb) x/4xw 0x0804b248
0x804b248 <node4>:      0x000003e5      0x00000004      0x0804b23c      0x0000012d
(gdb) x/4xw 0x0804b23c
0x804b23c <node5>:      0x000000d4      0x00000005      0x0804b230      0x000003e5
(gdb) x/4xw 0x0804b230
0x804b230 <node6>:      0x000001b0      0x00000006      0x00000000      0x000000d4
(gdb) q
```

Response : `4 2 6 3 1 5`

# Thor password

Possible password :

```
Publicspeakingisveryeasy.126241207201b2149opekma426135
Publicspeakingisveryeasy.126241207202b7559opekma426135
Publicspeakingisveryeasy.126241207207b5249opekma426135

Publicspeakingisveryeasy.126241207201b2149opukma426135
Publicspeakingisveryeasy.126241207202b7559opukma426135
Publicspeakingisveryeasy.126241207207b5249opukma426135

Publicspeakingisveryeasy.126241207201b2149opukmq426135
Publicspeakingisveryeasy.126241207202b7559opukmq426135
Publicspeakingisveryeasy.126241207207b5249opukmq426135

Publicspeakingisveryeasy.126241207201b2149opekmq426135
Publicspeakingisveryeasy.126241207202b7559opekmq426135
Publicspeakingisveryeasy.126241207207b5249opekmq426135
```

pwd : `Publicspeakingisveryeasy.126241207201b2149opekmq426135`
