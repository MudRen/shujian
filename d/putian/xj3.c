// Room: /d/putian/xj3.c С��
// lklv 2001.9.11

inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
����һ���ľ���С�������Ժ����ܵ������޼��ĺ����룬��������һ��ϸ
���ʯ�ӡ�
LONG
        );

        set("outdoors", "����");

        set("exits", ([
                "north" : __DIR__"celang5",
                "south" : __DIR__"mf-dian",
        ]));

        set("objects",([
        	__DIR__"npc/seng-bing" : 2,
        	__DIR__"npc/wuseng" : 2,
        ]));

        setup();
}
