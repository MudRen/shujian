// /d/wudang/shijie4.c 
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",CYN"ʯ��"NOR);
        set("long", @LONG
������һ�����ӵ�ʯ���ϣ���ʱ���н���ʹ��������߹���Զ����ײ��
���������š�̧ͷ��Լ�ɼ������������е������壬��֪���쵽ɽ���ˣ�һ��
�ܶ�ʱ���˻����ƣ�롣
LONG
        );
        set("exits", ([
                "southup" : __DIR__"gsdao5",
                "northdown" :__DIR__"gsdao4",
        ]));

        set("objects",([
                __DIR__"npc/jxk" : random(2)+1,
        ]));
        set("outdoors","�䵱");
        setup();
}
