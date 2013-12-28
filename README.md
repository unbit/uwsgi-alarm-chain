uwsgi-alarm-chain
=================

uWSGI plugin for mapping multiple alarms to a single event

```ini
[uwsgi]
plugins = alarm_chain

; create threee alarms
alarm = one log:hello world
alarm = two log:yep
alarm = three log:nope

; combine the three alarms into one
alarm = combo chain:one,two,three
...
```
