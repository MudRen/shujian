// Lime.c
// Creator : Numa@Sj 00-6-3

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"��ʯ��"NOR, ({"shihui", "lime"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�ƳγεĽ��ӣ��˼��˰��Ľ��ӣ����������ӣ�\n");
                set("unit", "��");
        }
        setup();
}