// Room: eroad4.c С·
// By jpei

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�������˴��������С·�ϣ�ż��������������ҴҶ������������ĳ�
����������ͨ�����ɶ��Ĵ��������������������
LONG);
	set("outdoors", "�ɶ�");

	set("exits", ([
		"east" : "/d/xiangyang/xiaolu2",
		"west" : __DIR__"eroad3",
	]));

	set("coor/x",-60);
  set("coor/y",-10);
   set("coor/z",0);
   setup(); 
}
