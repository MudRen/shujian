// Room: /d/putian/guangchang.c �㳡
// lklv 2001.7.21

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"�㳡"NOR);
        set("long", @LONG
�������еĹ㳡���㳡����ܴ�ܿ�������������һ����ɫ�ķ�ש������
�ط��ķ�ש��Щ��ƽ����ϸ���ܿ��������ӡ��״�İ��ݡ������Ǹߴ�Ĵȱ�
����������ϵĴ��۱�������ļⶥ�����������Ź⡣
LONG
        );

        set("exits", ([
                "north" : __DIR__"cb-dian",
                "east" : __DIR__"xiaoyuan4",
                "west" : __DIR__"xiaoyuan5",
                "southup" : __DIR__"dxb-dian",

        ]));
        set("objects",([
        	__DIR__"npc/jxiang-ke" : 2,
        	__DIR__"npc/seng-bing" : 2,
        ]));

        set("outdoors", "����");
        setup();
}
