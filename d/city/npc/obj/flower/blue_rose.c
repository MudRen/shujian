
#include <ansi.h>
#include <armor.h>

//inherit HEAD;
inherit COMBINED_ITEM;


int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(BLU "��ɫ����" NOR, ({"lanse yaoji", "lanse", "yaoji"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ��õ���еļ�Ʒ����˵�е���ɫ����������������������顣\n");
		set("unit", "��");

		set("value", 300000);
		set("base_unit", "��");
        set("base_weight", 100);
	set("flower_w",1);
	
	        set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unequip_msg", "$N����ذ�$n��ͷ��ժ��������\n");

			}
	set_amount(1);
	 
}
#include "flower.h"