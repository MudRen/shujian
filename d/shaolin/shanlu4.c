// Room: /d/shaolin/shanlu4.c
// Date: bren

inherit ROOM;


void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������ɽ������µ�һ��С·��·�Գ�������ݡ������̾͵�С·��
�������������ƺ����˾�����ɨ����Զ����������壬ɽ��ͦ�Σ����㾳��
����������������������΢��������������������������ǳ����֣������
�������¡�
LONG
	);

	set("exits", ([
		"north" : __DIR__"czan",
		"south" : __DIR__"shanlu3",
	]));

	
	set("outdoors", "shaolin");

	set("coor/x",50);
  set("coor/y",470);
   set("coor/z",140);
   setup();
}




