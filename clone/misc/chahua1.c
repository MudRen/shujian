// /u/beyond/obj/chahua1.c
// this is made by beyond
// update 1997.6.30
#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIY"ʮ��ѧʿ"NOR,({ "shiba xueshi", "hua", "flower" }) );
	set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 70);
                set("material", "plant");
                set("long", "����һ��ʮ��ѧʿ��\n");
                set("wear_msg", "$N����һ��$n������ǰ��\n");
                set("unequip_msg", "$Nժ����ǰ��$n��\n");
                set("armor_prop/armor", 0);
        }

        setup();
}
