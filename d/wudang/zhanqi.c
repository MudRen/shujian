// /area/jiangbei/wudang/zhanqi.c չ���
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", WHT"չ���"NOR);
        set("long", @LONG
չ���Ϊ�䵱������ɽ�壬�������㣬������Σ���Թžͱ���Ϊ�����µ�
һ�ɷ塱���������������Ͻ����죬������ȣ�����չ���Ĵ���һ�㣬�ʵô�
����չ���ǰ����ɽ�������ɽ������������������ɽ���������������񶴣�
�󲿷��䵱���ӵĻ�ڴ˷�֮�ϡ�
LONG
        );

        set("exits", ([
                "northdown" : __DIR__"shijie2",
                "west" : __DIR__"gsdao3",
                "southup" : __DIR__"shijie3",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "�䵱");

        setup();
}
