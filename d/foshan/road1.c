//road1.c by XiaoYao

inherit ROOM;
void create()
{
        set("short","�ּ��");
        set("long",@LONG
������һ���ּ�С���������������ѡ����������������ɽ������ͨ���
����
LONG);
        set("objects", ([
		__DIR__"obj/shuzhi": 1,
        ]));
        set("outdoors", "��ɽ");
        set("exits",([ /* sizeof() == 1 */
		"west" : __DIR__"road2",
		"east" : __DIR__"ximen",
        ]));
	setup();
}
