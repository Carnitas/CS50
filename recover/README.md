# Recover Problem

This program parses the included `card.raw` file to identify the number of
distinct jpgs found on the card.

I experimented with `enum` to avoid arbitrary error codes. There's more that
this function could do, but it's a start.

I also wanted to affirm that each write operation completed correctly. There are
edge cases where the program will silently fail, but that'll be for a later
revision.

Lastly, I learned about bitmasking as a way to identify the first four bits in
the fourth byte of a jpg file sigature.

```
➜  CS50 git:(recover) ✗ cd recover; cschecker cs50/problems/2024/x/recover; cd ..
Connecting.......
Authenticating...
Verifying........
Preparing........
Uploading.........
Waiting for results....................
Results for cs50/problems/2024/x/recover generated by check50 v3.3.11
:) recover.c exists.
:) recover.c compiles.
:) handles lack of forensic image
:) recovers 000.jpg correctly
:) recovers middle images correctly
:) recovers 049.jpg correctly
:) program is free of memory errors
```
