// Room: /d/shaolin/xiaolu1.c
// Date: YZC 96/01/19
// by bren

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һƬ���ܵ����֡������˼�������Ω�����ߵ��·�棬��ɮ��ľ��
����΢�紵����Ҷ�������������������˳���Ϊ֮һ�ӣ����Ǿ��ѵ�������
�ڡ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"xiaolu2",
		"west" : __DIR__"sblu-2",
	]));

	set("outdoors", "shaolin");
	set("coor/x",60);
  set("coor/y",370);
   set("coor/z",130);
   setup();
}



