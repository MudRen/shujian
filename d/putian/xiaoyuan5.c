// Room: /d/putian/xiaoyuan5.c СԺ
// lklv 2001.7.22

inherit ROOM;
void create()
{
        set("short", "СԺ");
        set("long", @LONG
����һ���ž����ŵ�СԺ���������������һ��鷽ש�������и������
�����ţ�������һ�����ȣ��·����һֱͨ��ǰԺ������ķ����ǹ㳡����ʱ
�����������ӵ�����������Ʈ��������㡣
LONG
        );

        set("exits", ([
                "east" : __DIR__"guangchang",
                "north" : __DIR__"celang3",
                "south" : __DIR__"jnlw-dian",
                "west" : __DIR__"celang5",

        ]));

        set("outdoors", "����");
        setup();
}

