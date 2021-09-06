// arrow.c

#include <weapon.h>

inherit F_EQUIP;

varargs void init_arrow(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", flag);
	set("skill_type", "arrow");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :));
		set("verbs", ({ "shot" }) );
	}
}
