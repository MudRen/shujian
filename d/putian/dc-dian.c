// Room: /d/putian/dc-dian.c ��˵�
// lklv 2001.9.12

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��˵�");
        set("long", @LONG
�����Ǵ�˵�������ܶ࣬�ſ���һ���ο̵�ʮ�־����Ĵ���¯����
¯ǰ����һ����ɫ�Ĺ���������������һ���ܴ�����硣������濿ǽ�ڸ߸�
�İڷ��ż�����񡣴������Ҳ��һ���š�
LONG
        );

        set("exits", ([
                "north" : __DIR__"xj4",
                "southup" : __DIR__"wgg",
                "west" : __DIR__"lhtang",
        ]));

        set("objects",([
                __DIR__"npc/shami" : 2,
                __DIR__"npc/wuseng" : 2,
        ]));

        setup();
}
