#include <uwsgi.h>

static void alarm_chain_init(struct uwsgi_alarm_instance *uai) {
	char *list = uwsgi_str(uai->arg);
        char *p, *ctx = NULL;
	uwsgi_foreach_token(uai->arg, ",", p, ctx) {
		struct uwsgi_string_list **l = (struct uwsgi_string_list **) &uai->data_ptr;
		uwsgi_string_new_list(l, p);
	}
	free(list);
}

static void alarm_chain_func(struct uwsgi_alarm_instance *uai, char *msg, size_t len) {
	struct uwsgi_string_list *usl = NULL, *alarms = (struct uwsgi_string_list *) uai->data_ptr;
	uwsgi_foreach(usl, alarms) {
		uwsgi_alarm_trigger(usl->value, msg, len);
	}
}

static void alarm_chain_register() {
	uwsgi_register_alarm("chain", alarm_chain_init, alarm_chain_func);
}

struct uwsgi_plugin alarm_chain_plugin = {
	.name = "alarm_chain",
	.on_load = alarm_chain_register,
};
