// Room: /d/shaolin/xiaolu2.c
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
		
		"northeast" : __DIR__"xiaolu3",
		"west" : __DIR__"xiaolu1",
	]));

	set("outdoors", "shaolin");
	set("coor/x",70);
  set("coor/y",370);
   set("coor/z",130);
   setup();
}



