// xiao.c ��

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("��",({"xiao"}));
	set_weight(150);
	if (clonep())
		set_default_object(__FILE__);
	else{
		set("unit", "֧");
		set("value", 600);
		set("material", "wood");
		set("long","����һ֧����ľ���������ʮ�־�ϸ��\n");
		set("wield_msg","$N��������һ�У�һ֧$n�ѳ�����$N���С�\n");
		set("unwield_msg","$N΢΢һЦ,��$n�����ڡ�\n");
	}
	init_sword(15);
	setup();
}

int wield() 
{
        object me = environment();
        if (living(me) && !me->query_skill("yuxiao-jian", 1)){
            message_vision("$N����"+name()+"�����ǲ���ʹ�á�\n", me);
            return 0;
        }           
        if(!query("weapon_prop/damage")) return 0;
        return ::wield();
}

