// cloth1.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIY "��˿����" NOR, ({ "chang pao", "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ�����ı�֯��������˿�ĳ��ۡ�\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 30);
                set("wear_msg","$N�ó�һ��$n�������ϡ�\n");
                set("remove_msg","$N��$n����������������\n");
        }
        setup(); 
}
