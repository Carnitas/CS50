## Runoff

We could only change the supporting functions in this one, everything after line
126\. If I did this again, I'd try to find out a better way to approach the
problem than divining in and trying to solve for the tests, function by
function.

Spoiler, because it's a dumb timesink: The `print_winner()` function requires a
`\n` character when you print the winner's name in order to pass the tests.

```
➜  CS50 git:(runoff) ✗ cd runoff; cschecker cs50/problems/2024/x/runoff; cd -
Connecting.......
Authenticating...
Verifying........
Preparing.......
Uploading.........
Waiting for results.........................
Results for cs50/problems/2024/x/runoff generated by check50 v3.3.11
:) runoff.c exists
:) runoff compiles
:) vote returns true when given name of candidate
:) vote returns false when given name of invalid candidate
:) vote correctly sets first preference for first voter
:) vote correctly sets third preference for second voter
:) vote correctly sets all preferences for voter
:) tabulate counts votes when all candidates remain in election
:) tabulate counts votes when one candidate is eliminated
:) tabulate counts votes when multiple candidates are eliminated
:) tabulate handles multiple rounds of preferences
:) print_winner prints name when someone has a majority
:) print_winner returns true when someone has a majority
:) print_winner returns false when nobody has a majority
:) print_winner returns false when leader has exactly 50% of vote
:) find_min returns minimum number of votes for candidate
:) find_min returns minimum when all candidates are tied
:) find_min ignores eliminated candidates
:) is_tie returns true when election is tied
:) is_tie returns false when election is not tied
:) is_tie returns false when only some of the candidates are tied
:) is_tie detects tie after some candidates have been eliminated
:) eliminate eliminates candidate in last place
:) eliminate eliminates multiple candidates in tie for last
:) eliminate eliminates candidates after some already eliminated
```
