// Room: /d/city/dongdajie3.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣���߲�ʱ�ش������ʵ���
������������һ�����ֵĹ㳡���ϱ�����һ�ҹ����ɫ�ĵ��̣���߲�ʱ����
�����������������
LONG
	);
        set("outdoors", "����");

	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"south" : __DIR__"yueqidian",
	        "west" : __DIR__"guangchangnan",
		"north" : __DIR__"guangchangdong",
	]));

	set("coor/x",120);
  set("coor/y",-20);
   set("coor/z",0);
   set("incity",1);
	setup();
}

