// Room: tulu2.c ��·
// By jpei

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�����������С·����Ϊ�Ĵ��Թž��Ǹ���֮�أ����Է�����ȥ��
���ܵ��������������ࡣ
LONG);
	set("outdoors", "����");

	set("exits", ([
		"northeast" : __DIR__"tulu3",
		"southwest" : __DIR__"tulu1",
	]));

	set("coor/x",-170);
  set("coor/y",-90);
   set("coor/z",0);
   setup(); 
}
