// Room: /d/putian/xj4.c С��
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

        set("exits", ([
                "north" : __DIR__"celang4",
                "south" : __DIR__"dc-dian",
        ]));

        set("objects",([
        	__DIR__"npc/seng-bing" : 2,
        ]));

        set("outdoors", "����");

        setup();
}
