// /u/beyond/obj/chahua2.c
// this is made by beyond
// update 1997.6.30
#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIM"���ɹ���"NOR,({ "baxian guohai", "flower", "hua" }) );
	set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 130);
                set("material", "plant");
                set("long", "����һ����ɹ�����\n");
                set("wear_msg", "$N����һ��$n������ǰ��\n");
                set("unequip_msg", "$Nժ����ǰ��$n��\n");
                set("armor_prop/armor", 0);
        }

        setup();
}
