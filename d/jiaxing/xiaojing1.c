// /d/jiaxing/xiaojing1.c �������С��

inherit ROOM;

void create()
{
	set("short", "���С��");
	set("long", @LONG
���������İ�ݺᣬС·������ȥ����·��խ��������̤�����У�˫��ȫ
�����ࡣ
LONG
        );

	set("exits", ([
		"north" : __DIR__"jxnanmen",
		"southeast" : __DIR__"shulin1",
		"east" : __DIR__"river",
	]));

	set("outdoors", "����");
	setup();
}
