// Modify By River 98/12
#include <weapon.h>
inherit CLUB;

void create()
{
        set_name("��ͭ��", ({ "shu tonggun", "gun" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ͭ����ĳ������ɹ�����Ƭ���ˡ�\n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
		set("dali",1);
        }
        init_club(25);
        setup();
}

