// Room: /d/putian/cbdian.c
// Lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"�ȱ���"NOR);
        set("long", @LONG
�����Ǵȱ�������������µļ�����Ҫ��������֮һ�����п������ܰ�
������������һЩ�����������ׯ�����¡��������಼ɮ�µ�Сɳ����æ
µ�ز����Ű��ϵĻҳ���
LONG
        );

        set("exits", ([
                "north" : __DIR__"qianyuan",
                "south" : __DIR__"guangchang",
        ]));
        set("objects",([
                CLASS_D("putian") + "/yuanjue" : 1,
                __DIR__"npc/shami" : 2,
        ]));

        setup();
}

