// xtbs.c ذ��
// by snowman@SJ

#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("����ذ��", ({ "xuantie bishou","bishou"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����Ƶ�����ذ�ס�\n");
                set("value", 30);
		set("rigidity",6);
set("sharpness",3);
		set("unique", 1);
                set("treasure",1);
                set("material", "steel");
        }
        init_dagger(100);
        setup();
}
