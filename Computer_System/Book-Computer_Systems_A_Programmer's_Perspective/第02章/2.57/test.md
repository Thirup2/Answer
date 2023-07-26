- run
```bash
./main 12345

./main 65535

./main 0xffffffff
```

- output
```
show_short
 39 30
show_long
 39 30 00 00
show_double
 00 00 00 00 80 1c c8 40
```
```
show_short
 ff ff
show_long
 ff ff 00 00
show_double
 00 00 00 00 e0 ff ef 40
```
```
show_short
 ff ff
show_long
 ff ff ff 7f
show_double
 00 00 c0 ff ff ff df 41
```