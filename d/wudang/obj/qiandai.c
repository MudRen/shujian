// OBJ : /d/wudang/obj/qiandai.c Ǧ��
// By lius 99/8

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
        set_name( WHT"Ǧ��"NOR, ({ "qian dai", "dai" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�����������Ǧ������������䵱������ϰ�Ṧ�ĸ��ߡ�\n");
                set("value", 6000);
                set("material", "boots");
                set("armor_prop/armor", 8);
                set("wudang",1);
set("wear_msg","$N�ó�һ��Ǧ�������ذ������ϡ�\n"NOR);
set("remove_msg","$N��Ǧ�����Ƚ�ȡ����������ʱ�����������ࡣ\n"NOR);
        }
        setup();
}
