//silver-falun.c ������
//by iceland

#include <weapon.h>
#include <ansi.h>
inherit HAMMER;

void create()
{
        set_name( HIW"������"NOR,({ "silver falun" ,"lun" ,"falun","yin falun","yinfalun" }));
        set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
                set("long","����һ���������֣�Լ�г߰��С�������������ڷ�ħ���ԣ��ڲؾŸ�С���Ǹ�ɮ�������õ�һ�ַ�����\n");
                set("value", 1500);
                set("unique", 1);
                set("rigidity", 5);
                set("sharpness", 3);
                set("treasure",1);  
                set("weapon_prop/dodge", -7);
                set("weapon_prop/parry", 7);     
                set("wield_neili", 300);
                set("wield_maxneili", 1200);
                set("wield_str", 30);
                set("material", "silver");
                set("wield_msg", "$N�ӻ����ͳ�һ��$n���˵�������������У������������á�\n");
                set("unwield_msg","$N�����е�$n���ػ��С�\n");
	}
        init_hammer(60);
	setup();
}
