// Room: /d/putian/lzdian.c
// Lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"�����"NOR);
        set("long", @LONG
�������������湩����������ʷ����λ��������ʦ�������Ħ������
�ݿɣ�����ɮ貣�������ţ�������̣�������ܵ����񡣸���������������
����֡�һλɮ�������������ϱ�Ŀ����
LONG
        );

        set("exits", ([
                "north" : __DIR__"xiaoyuan4",
        ]));
        set("objects",([
                __DIR__"npc/shami" : 1,
                CLASS_D("putian") + "/yuanai": 1,
        ]));
        setup();
}
