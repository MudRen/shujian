// huxiong.c                                                                           
// caiji@SJ 8/27/2000 �������ֻ����޸ģ���о���ͬ�Ļ������æCUT��

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
        set_name(HIY "̴ľ����" NOR, ({ "tanmu huxiong", "huxiong" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
                set("long", "����һ˫�����õķ����ߡ�\n");
                set("value", 6000);
                set("material", "wrists");
                set("armor_prop/armor", 4);
                set("wudang",1);
        }
        setup();
}
