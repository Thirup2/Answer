- run
> AMD 4600U - Windows11
```bash
./show-bytes.c

./show-bytes.c 12345
```
- output
```
calling show_twocomp
 39 30
 c7 cf
Calling simple_show_a
 21
 21 43
 21 43 65
Calling simple_show_b
 78
 78 56
 78 56 34
Calling float_eg
For x = 3490593
 21 43 35 00
 84 0c 55 4a
For x = 3510593
 41 91 35 00
 04 45 56 4a
Calling string_ueg
 41 42 43 44 45 46
Calling string_leg
 61 62 63 64 65 66
```
```
calling test_show_bytes
 39 30 00 00
 00 e4 40 46
 cc fd 61 00 00 00 00 00
```