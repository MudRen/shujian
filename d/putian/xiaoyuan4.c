// Room: /d/putian/xiaoyuan4.c СԺ
// lklv 2001.7.22

inherit ROOM;
void create()
{
        set("short", "СԺ");
        set("long", @LONG
����һ���ľ�������СԺ���������������һ�����ʯ�������и������
�����ţ�������һ�����ȣ��·����һֱͨ��ǰԺ������ķ����ǹ㳡����ʱ
�����������ӵ�������
LONG
        );

        set("exits", ([
                "west" : __DIR__"guangchang",
                "north" : __DIR__"celang2",
                "east" : __DIR__"celang4",
                "south" : __DIR__"lz-dian",

        ]));

        set("outdoors", "����");
        setup();
}

