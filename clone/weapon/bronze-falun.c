//bronze-falun.c ͭ����
//by iceland
#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit HAMMER;
void create()
{
        set_name( YEL"ͭ����"NOR,({ "bronze falun",  "falun","lun","tong falun", "tongfalun"}));
        set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
               	set("unit", "ֻ");
	        set("long","����һ��ͭ�����֣�Լ�г߰��С�������������ڷ�ħ���ԣ��ڲؾŸ�С����ɮ�����������õ�һ�ַ�����\n");
                set("value", 300);
                set("unique", 1);
                set("rigidity", 3);
                set("sharpness", 1);
                set("treasure",1);  
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 3);   
                set("wield_maxneili", 800);
                set("wield_str", 25);
                set("material", "bronze");
                set("wield_msg", "$N�ӻ����ͳ�һ��$n���˵�������������У������������á�\n");
                set("unwield_msg","$N�����е�$n���ػ��С�\n");
	}
        init_hammer(45);
	setup();
}
