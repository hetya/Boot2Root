```Shell
thor@BornToSecHackMe:~$ ls
README  turtle
thor@BornToSecHackMe:~$ cat README
Finish this challenge and use the result as password for 'zaz' user.
```

Download the file, it's name turtle and when it is open we can see that it conatain turtle instructions.
So we write a program to tarce the instruction (script in scripts/turtle_draw).
We can see that the turtle write the word "SLASH".

At the end of the turtle instruction file we have a clue with the term "digest"
Using Md5 we calculate the digest of `SLASH`:

```Shell
➜  Boot2root git:(main) ✗ cat sandbox/turtle/tt
SLASH%
➜  Boot2root git:(main) ✗ md5sum sandbox/turtle/tt
646da671ca01bb5d84dbb5fb2238dc8e  sandbox/turtle/tt
```

Password of `zaz` : `646da671ca01bb5d84dbb5fb2238dc8e`
