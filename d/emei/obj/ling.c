// ling.c ��ͷ

#include <weapon.h>
inherit AXE;

void create()
{
        set_name("��������", ({ "ling" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѷ����ɺ�����ӵ����ơ�\n");
                set("value", 1500);
                set("rigidity",100);
                set("material", "steel");
                set("no_get", 1);
        }
        init_axe(25);
        setup();
}
