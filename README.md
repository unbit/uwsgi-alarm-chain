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

the plugin is 2.0-friendly, so you can easily build it with:

```sh
uwsgi --build-plugin uwsgi-alarm-chain
```
