// Room: /d/jiaxing/jxnanmen.c

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǽ��˵����ţ�����������һ��ϸϸ�����С������Χ����һ��Ƭï
�ܵ����֡�������ȥ����İ�ݺᣬһƬ����ˮ���⡣����ķ�����һ���ƾ�
�������������������
LONG
        );

        set("exits", ([
                "north" : __DIR__"jiaxing",
                "east" : __DIR__"tieqiang",
                "south" : __DIR__"xiaojing1",
        ]));

        set("outdoors", "����");
	setup();
}
