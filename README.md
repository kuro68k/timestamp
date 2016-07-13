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

Sometimes it is handy to keep a copy of every build you do, so that they can be debugged later. For example, keeping .map files for old builds lets you peek/poke or examine memory dumps of old builds more easily.

The `archive_build.cmd` script is an example of how to create archived versions of build output automatically. You can run it as a post-build action automatically in Visual Studio/Atmel Studio. It takes three parameters, `<source dir>`, `<destination dir>` and `<base file name>`.
