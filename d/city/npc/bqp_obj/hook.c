// hook.c

#include <weapon.h>
inherit HOOK;

void create()
{
        set_name("��", ({ "gou", "hook" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������Ƴɵġ�\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��������\n");
        }
        init_hook(20);
        setup();
}
