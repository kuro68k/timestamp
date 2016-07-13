# timestamp
Timestamp and build number tool for C projects.

Timestamp outputs the current time as an int (epoch either 2000/01/01 or 1970/01/01) and optionally an incremental build number. The build number is stored in buildnum.txt, which is created if it doesn't already exist.

```
-d   Produces #defines in output
-b   Include build number in output
-u   Use Unix epoch (1970) instead of 2000
```

Example output:

```
>timestamp
521720813
```

```
>timestamp -d -b
// seconds since 2000/01/01 00:00:00
#define BUILD_TIME      521720818
#define BUILD_NUMBER    1
```
