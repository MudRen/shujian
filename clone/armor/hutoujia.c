// hutoujia.c

#include <armor.h>
#include <ansi.h>
inherit ARMOR;

void create()
{
        set_name(YEL"��ͷ���޼�"NOR, ({ "hutou jia" , "armor", "jia" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "bronze");
		set("value", 8000);
// cut armor river@
                set("armor_prop/armor", 15);
                set("long","�������������ͭ����죬�ؿڻ��Ĵ����Ÿ������Ļ�ͷ��\n");
           }
        setup();
}
