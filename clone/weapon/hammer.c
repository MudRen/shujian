//iron-falun ������
// copy to hammer.c
//modified by campsun 2003/09/20
//���ӣ������������Ļ���������
#include <ansi.h>
#include <weapon.h>
inherit F_HAMMER;
inherit F_EQUIP;
inherit COMBINED_ITEM;

void create()
{
        set_name( BLU"������"NOR,({ "iron falun" ,"lun" ,"falun","tie falun","tiefalun" }));
        set_weight(25000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "ֻ");
                set("long","����һֻ���Ʒ��֣�Լ�г߰��С�������������ڷ�ħ���ԣ��ڲؾŸ�С����ɮ�����������õ�һ�ַ�����\n");
                set("value", 100);
                set("rigidity", 1);
                set("weapon_prop/dodge", -6);
                set("weapon_prop/parry", 2);    
                set("material", "iron");
                set("base_unit", "ֻ");
                set("base_weight", 18000);
                set("wield_msg", "$N�ӻ����ͳ�$n���˵�������������У������������á�\n");
                set("unwield_msg","$N�����е�$n���ػ��С�\n");
        }    
        set_amount(5);           
        init_hammer(40);
        setup();
}


