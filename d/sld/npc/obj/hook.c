// hook.c ˫��

#include <weapon.h>
inherit HOOK;

void create()
{
        set_name("˫��", ({ "shuang gou", "gou" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������ƳɵĹ��ӡ�\n");
                set("value", 30);
                set("material", "steel");
        }
        init_hook(30);
        setup();
}
