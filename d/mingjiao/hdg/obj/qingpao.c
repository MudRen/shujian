//qingpao.c ����

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIC"���³���"NOR, ({"chang pao", "cloth", "pao"}) );
        set_weight(2000);
        if( clonep() )
            set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("long", "����һ���ʼѵ���ɫ���ۡ�\n");
        set("material", "cloth");
        set("armor_prop/armor", 20);
        set("value",2000);
    }
    setup();
}
