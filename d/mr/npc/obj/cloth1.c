// /u/beyond/mr/obj/cloth1.c
// this is made by beyond
// update 1997.6.20
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(MAG"�ۺ����"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","����һ���ۺ�ɫ��Ů�����¡�\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 10);
        }
        setup();
}