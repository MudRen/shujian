// huyao.c
// caiji@SJ 8/27/2000 �������ֻ����޸ģ���о���ͬ�Ļ������æCUT��

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
        set_name(HIR "���ﻤ��" NOR, ({ "danfeng huyao", "huyao" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ü���֮Ƥ���Ƴɵĸ߼�������������һ�����ķ�ˡ�\n");
                set("value", 6000);
                set("material", "waist");
                set("armor_prop/armor", 4);
                set("wudang",1);
        }
        setup();
}
