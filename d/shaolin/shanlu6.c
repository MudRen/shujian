// Room: /d/shaolin/shanlu6.c
// Date: bren

inherit ROOM;


void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������ɽ������µ�һ��С·��·�Գ�������ݡ������̾͵�С·��
�������������ƺ����˾�����ɨ����Զ����������壬ɽ��ͦ�Σ����㾳��
����������������������΢���������������������ǰ������������һƬ��
������֣�һ��С��ֱͨ���ڡ�
LONG
	);

	set("exits", ([
		"northup" : __DIR__"shanlu7",
		"southdown" : __DIR__"shanlu5",
                "northwest" : __DIR__"bamboo1",
	]));

	
	set("outdoors", "shaolin");

	set("coor/x",50);
  set("coor/y",500);
   set("coor/z",150);
   setup();
}




