// hshacha.c
// build by lklv 2001.9.28

#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
	set_name(HIR"��װ�ع�"NOR,({ "hongzhuang suguo", "flower", "hua" }) );
	set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 90);
                set("material", "plant");
                set("long", "����һ���װ�ع���\n");
                set("wear_msg", "$N����һ��"HIR"��װ�ع�"NOR"������ǰ��\n");
                set("unequip_msg", "$Nժ����ǰ��$n��\n");
                set("armor_prop/armor", 0);
        }

        setup();
}
