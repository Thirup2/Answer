- run
```bash
./show-bytes.c 328

./show-bytes.c 4294967295

./show-bytes.c 65535
```

- output
```
calling test_show_bytes
 48 01 00 00
 00 00 a4 43
 cc fd 61 00 00 00 00 00
```
```
calling test_show_bytes
 ff ff ff 7f
 00 00 00 4f
 cc fd 61 00 00 00 00 00
```
```
calling test_show_bytes
 ff ff 00 00
 00 ff 7f 47
 cc fd 61 00 00 00 00 00
```