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
        set_name( BLU"�ش�����"NOR,({ "falun" ,"lun" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "ֻ");
                set("long","��ֻ�������������ƣ�Լ�г߰��С�������������ڷ�ħ���ԣ��ڲؾŸ�С�����ӱ�Եĥ�ü�����������˸�������ޱȡ�\n");
                set("value", 80000);
                set("rigidity", 3);
                set("weapon_prop/dodge", -5);
		set("no_sell", 1);
                set("weapon_prop/parry", 20);    
                set("material", "iron");
                set("base_unit", "ֻ");
                set("base_weight", 18000);
                set("wield_msg", "$N�ӻ����ͳ�$n���˵�������������У������������á�\n");
                set("unwield_msg","$N�����е�$n���ػ��С�\n");
        }    
        set_amount(5);           
        init_hammer(60);
        setup();
}


