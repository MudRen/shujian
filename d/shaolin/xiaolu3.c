// Room: /d/shaolin/xiaolu3.c
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
		
		"southeast" : __DIR__"xiaolu4",
		"southwest" : __DIR__"xiaolu2",
	]));

	set("outdoors", "shaolin");
	set("coor/x",80);
  set("coor/y",380);
   set("coor/z",130);
   setup();
}



