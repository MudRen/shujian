// bishou.c ذ��

#include <weapon.h>
inherit DAGGER;

void create()
{
	string * pre=({"��","��","ͭ","��","��"});

        set_name(pre[random(sizeof(pre))]+"ذ��", ({ "bishou"}));
        set_weight(2300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����Ƶ�ذ�ס�\n");
                set("value", 30);
                set("material", "steel");
        }
        init_dagger(35+random(15));
        setup();
}
