// By River@sj 99.5.24
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
    set("short", YEL"ɽ·"NOR);
    set("long", @LONG
�������ٲ������һ����᫵�ɽ·��·���ϼ�����һЩ��ɳ����ϥ��Ұ��
������·���ڸ��ˣ���������Ұ��Ʈ�������㡣���ܲ�ʱ����һ�����Ұ��
����, ͷ����һЩ��֪����С����������ȥ��
LONG
    );

    set("outdoors", "����");

    set("exits", ([
        "east" : __DIR__"pubu",
        "northwest" : __DIR__"dongkou",
        "southdown" : __DIR__"xiaolu2",
    ]));

    setup();
}
