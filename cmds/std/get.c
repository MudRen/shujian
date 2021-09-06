// get.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_get(object me, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string from, item;
	object obj, *inv, env, obj2;
	int i, amount;

	if (!arg) return notify_fail("��Ҫ����ʲô������\n");
	if (me->is_busy())
		return notify_fail("����һ��������û����ɣ�\n");

	// Check if a container is specified.
	if( sscanf(arg, "%s from %s", arg, from)==2 ) {
		env = present(from, me);
		if (!env) env = present(from, environment(me));
		if (!env) return notify_fail("���Ҳ��� " + from + " ����������\n");
		if (living(env) && (wiz_level(me) <= wiz_level(env)))
			return notify_fail("�����ʦ�ȼ�����ȶԷ��ߣ���������\n");
	} else
		env = environment(me);

	if (userp(env) && environment(me)->query("sleep_room"))
		return notify_fail("�����ﶯ��Ҫ��һ�㣬��ó��ѱ��ˡ�\n");

	// һЩװ��������Ʒ����������player�������Ʒ��
	if (!wizardp(me) && env->query("no_get_from"))
		return notify_fail("���컯�յ������ٰ���\n");

	// Check if a certain amount is specified.
	if (sscanf(arg, "%d %s", amount, item)==2) {
		if (!objectp(obj = present(item, env)))
			return notify_fail("����û������������\n");
		if (!obj->query_amount())
			return notify_fail( obj->name() + "���ܱ��ֿ����ߡ�\n");
		if (amount < 1)
			return notify_fail("�����ĸ���������һ����\n");
		if (amount > obj->query_amount())
			return notify_fail("����û����ô���" + obj->name() + "��\n");
		else if (amount == (int)obj->query_amount())
			return do_get(me, obj);
		else {
			obj2 = new(base_name(obj));
			obj2->set_amount( obj->query_amount() - amount);
			obj2->set("broken", obj->query("broken"));
			obj->set_amount(amount);
			// Counting precise amount costs more time.
			if (me->is_fighting()) me->start_busy(3);
			if (do_get(me, obj)) {
				obj2->move(env, 1);
				return 1;
			}
			obj2->move(env, 1);
			return 0;
		}
	}

	// Check if we are makeing a quick get.
	if (arg == "all") {
		if (me->is_fighting())
			return notify_fail("�㻹��ս���У�ֻ��һ����һ����\n");
		if (!env->query_max_encumbrance())
			return notify_fail("�ǲ���������\n");
		if (environment(me)->query("sleep_room"))
			return notify_fail("������˯������ֻ��һ����һ��������\n");
		if (env->query("no_get_from"))
			return notify_fail("�㲻�ܴ��������ó���������\n");
		inv = all_inventory(env);
		if (!sizeof(inv))
			return notify_fail("������û���κζ�����\n");

		for(i=0; i<sizeof(inv); i++)
			do_get(me, inv[i]);

		write("Ok��\n");
		return 1;
	}

	if (!objectp(obj = present(arg, env)) || living(obj))
		return notify_fail("�㸽��û������������\n");

	if (userp(obj) && env->query("sleep_room"))
		return notify_fail("�����ﶯ��Ҫ��һ�㣬��ó��ѱ��ˡ�\n");

	if (obj->query("no_get"))
		if (!wizardp(me)) {
			if (stringp(obj->query("no_get")))
				return notify_fail(obj->query("no_get"));
			return notify_fail("��������ò�������\n");
		}

	return do_get(me, obj);
}

int do_get(object me, object obj)
{
	object old_env;
	int equipped;	

	if (!obj) return 0;
	if (obj->query("invisible") && !wizardp(me)) return 0;
	old_env = environment(obj);

	if (living(obj) || !wizardp(me) && obj->query("no_get"))
		return 0;
		
  //for zhuanji by LinuX                
	if(!wizardp(me) && userp(me) && stringp(obj->query("owner")) && obj->query("owner") != "" && obj->query("owner") != "0" && obj->query("owner") != getuid(me))
		return notify_fail("���컯�յ������ٰ���\n");
	if(!wizardp(me) && userp(me) && stringp(obj->query("tmp_owner")) && obj->query("tmp_owner") != "" && obj->query("tmp_owner") != "0" && obj->query("tmp_owner") != getuid(me))
		return notify_fail("���컯�յ������ٰ���\n");
                
	//������ж�������Ʒ���������� ����������get�Ķ��� :) Ciwei@SJ �������corpse
        if(!wizardp(me) && obj->query_max_encumbrance() && !(obj->is_corpse()&&obj->query("victim_user")) ){
        	object* inv = all_inventory(obj);
        	for(equipped=0;equipped<sizeof(inv);equipped++)
        		if(userp(me) && stringp(inv[equipped]->query("owner")) && inv[equipped]->query("owner") != "" && inv[equipped]->query("owner") != "0" && inv[equipped]->query("owner") != getuid(me))
                		return notify_fail("���컯�յ������ٰ���\n");        		
        }                	

	equipped = 0;
	if (obj->query("equipped")) equipped = 1;
	if (obj->move(me)) {
		obj->delete("embedded");
		if (me->is_fighting())
			me->start_busy(3);
		if (obj->is_character())
			message_vision( "$N��$n�����������ڱ��ϡ�\n", me, obj );
		else message_vision( sprintf("$N%sһ%s%s��\n",
			old_env==environment(me)? "����":
				(old_env->is_character() ?
					"��" + old_env->name() + "����" + (equipped? "����" : "�ѳ�"):
					"��" + old_env->name() + "���ó�"),
			obj->query("unit"), obj->name()), me);
		return 1;
	}
	return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : get <��Ʒ����> [from <������>]

���ָ��������������ϻ������ڵ�ĳ����Ʒ.

HELP
    );
    return 1;
}
