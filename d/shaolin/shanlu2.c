// Room: /d/shaolin/shanlu2.c
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
		"northup" : __DIR__"shanlu3",
		"south" : __DIR__"shanlu1",
	]));

	
	set("outdoors", "shaolin");

	set("coor/x",50);
  set("coor/y",450);
   set("coor/z",130);
   setup();
}




