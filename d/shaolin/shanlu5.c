// Room: /d/shaolin/shanlu5.c
// Date: bren

inherit ROOM;


void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��������ɽ������µ�һ��С·��·�Գ�������ݡ������̾͵�С·��
�������������ƺ����˾�����ɨ����Զ����������壬ɽ��ͦ�Σ����㾳��
����������������������΢��������������������������ǳ����֣������
��������ϡ�
LONG
	);

	set("exits", ([
		"northup" : __DIR__"shanlu6",
		"south" : __DIR__"czan",
	]));

	
	set("outdoors", "shaolin");

	set("coor/x",50);
  set("coor/y",490);
   set("coor/z",140);
   setup();
}




