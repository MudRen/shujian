// bianfuxuejia.c

#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
        set_name(RED"����Ѫ��"NOR, ({ "bianfuxue jia" , "armor", "jia"  }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "bronze");
		set("value", 5000);
                set("armor_prop/armor", 15); // cut 50 -> 15 River@SJ
                set("long","�������������ƬͭƬ���Ӷ��ɣ���������չ˫�������Ϊ�Σ��ɺ�ɫ���ڳ�Ԣ��մ�����˵���Ѫ��\n");
           }
        setup();
}
