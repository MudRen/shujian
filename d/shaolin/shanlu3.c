// Room: /d/shaolin/shanlu3.c
// Date: bren

inherit ROOM;


void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������ɽ������µ�һ��С·��·�Գ�������ݡ������̾͵�С·��
�������������ƺ����˾�����ɨ����Զ����������壬ɽ��ͦ�Σ����㾳��
����������������������΢���������������������
LONG
	);

	set("exits", ([
		"north" : __DIR__"shanlu4",
		"southdown" : __DIR__"shanlu2",
	]));

	
	set("outdoors", "shaolin");

	set("coor/x",50);
  set("coor/y",460);
   set("coor/z",140);
   setup();
}




