// /area/jiangbei/wudang/wulong.c ������
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"������"NOR);
        set("long", @LONG
���������������������䵱ɽ�Ž���Ⱥ������Ľ�����Ԫ������֮ʿ����
�������������׷˷�����������䵱���̵ķ���ʥ�أ���ʷ�ϱ���Ϊ��Ӧ֮�ء�
������Ϊ��������Ⱥ��������ס�ĵط������ԣ��������һ�鱮���������
�������ڽ����������������Դ˸�����ǣ����һ�������ͥ��һ�������񸮣�
�ڴ˹���Ҫ������������⾪�����顣 
LONG
        );

        set("exits", ([
                "eastdown" : __DIR__"yxyan",
        ]));

        set("no_clean_up", 0);

        set("objects",([
                __DIR__"npc/daotong" : random(2)+1,
        ]));

        set("outdoors", "�䵱");

        setup();
}
