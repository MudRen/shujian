
#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIW"������"NOR,({ "luodi xiucai", "hua" ,"flower" }) );
	set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 11);
                set("material", "plant");
                set("long", "����һ�������š�\n");
                set("wear_msg", "$N����һ��$n������ǰ��\n");
                set("unequip_msg", "$Nժ����ǰ��$n��\n");
                set("armor_prop/armor", 0);
        }

        setup();
}
