// yuxiao.c ����

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("����", ({"yu xiao", "xiao"}));
	set_weight(250);
	if (clonep())
		set_default_object(__FILE__);
	else{
		set("unit", "֧");
		set("value", 2000);
		set("material", "gem");
                set("rigidity", 1);
		set("long","����һ֧����������������������������࣬���˰������֡�\n");
		set("wield_msg","$N��������һ�У�һ֧$n�ѳ�����$N���С�\n");
		set("unwield_msg","$Nһ����Х����$n������䡣\n");
	}
	init_sword(25);
	setup();
}

int wield() 
{
        object me = environment();
        if (living(me) && me->query_skill("yuxiao-jian", 1) < 50){
            message_vision("$N����"+name()+"�����ǲ���ʹ�á�\n", me);
            return 0;
        }           
        if(!query("weapon_prop/damage")) return 0;
        return ::wield();
}

