// Room: /d/shaolin/shanlu7.c
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
		"northeast" : __DIR__"shanlu8",
		"southdown" : __DIR__"shanlu6",
               
	]));

	
	set("outdoors", "shaolin");

	set("coor/x",50);
  set("coor/y",510);
   set("coor/z",160);
   setup();
}




