// /d/xingxiu/silk1a.c
inherit ROOM;

void create()
{
        set("short", "ˮ����");
        set("long", @LONG
����Ⱥ����ʣ������������֣����·ת��ʯ����¶���й��ζ��ߣ�����
ˮ����̦�����̰ವ����ʯ���ס��꼾ɽ������ֱ����ˮ�������д�����
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "southeast" : __DIR__"silk1b",
                "northeast" : __DIR__"silk1",
        ]));

        setup();
}

#include "/d/xingxiu/job2.h";