// Room: /d/putian/fzshi.c ������
// Lklv 2001.9.12

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"������"NOR);
        set("long", @LONG
�����Ƿ����ң����ڰ���һ�����������Ա��м������Σ�������λ����һ
�Ų輸���輸ǰ��һ�����ţ��������һ���񴲣��������ܼ򵥡�����ǽ��д
��һ�ν�վ��ľ��ģ�
LONG
        );

        set("exits", ([
                "east" : __DIR__"changlang2",
        ]));

        set("objects",([
                __DIR__"npc/shami" : 1,
        ]));

        setup();
}
