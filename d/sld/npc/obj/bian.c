// bian.c ��

#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("�߱�", ({ "bian", "whip" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������Ƥ�Ƴɵĳ��ޣ������ֲڡ�\n");
                set("value", 30);
                set("material", "fur");
                set("wield_msg", "$N��ৡ���һ����������һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n�������\n");
		set("no_return",1);
        }
        init_whip(30);
        setup();
}

