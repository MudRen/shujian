// Room: /d/putian/jnlwdian.c
// Lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"����������"NOR);
        set("long", @LONG
���ǽ�����������й����ŷ�����ڵĽ������������������ܵ�ǽ��
�ϻ���������ʤ������ʮ��Ը����ʮ������ıڻ����ڻ�������������������
ϸ��ٲȻ��������֮�֡�һ��Сɳ����ɨ�ء�
LONG
        );

        set("exits", ([
                "north" : __DIR__"xiaoyuan5",
        ]));

        set("objects",([
                __DIR__"npc/shami" : 1,
                CLASS_D("putian") + "/yuannu" : 1,
        ]));

        setup();
}

