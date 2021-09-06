// equip.c

inherit ITEM;
inherit F_EQUIP;

int is_owner(object me)
{
	if(!me) return 0;		
	if( query("owner") == getuid(me) ) return 1;	
	return 0;
}

void setup()
{
	if (!clonep()) {
		if (query("armor_type"))
			add("armor_prop/dodge", - weight() / 2500 );
		if (query("weapon_type"))
			add("weapon_prop/dodge", - weight() / 2500 );
	}
}

nosave int use_flag = 1;
nosave object *buf = ({ });

void hit_ob(object me, object victim)
{
	if (use_flag < 2 && me->query("combat_exp") / 4 < victim->query("combat_exp") / 3) {
		buf -= ({ 0 });
		if (member_array(victim, buf) < 0) {
			buf += ({ victim });
			use_flag++;
		}
	}
}

void ob_hit()
{
	if (use_flag < 2)
		use_flag++;
}

void reset()
{
	object env =environment();

	switch (query("armor_type")) {
		case 0:
		case "armor":
		case "cloth":
			break;
		default:
			return;
	}
	if (!env || !userp(env) || use_flag--)
		return;
	if (query("unique")) {
		message_vision("$Nһʱ�벻��"+query("name")+"��ʲô�ô��������ְ��������ˡ�\n", env);
		destruct(this_object());
	}
}
