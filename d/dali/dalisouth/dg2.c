// Room: /d/dali/dg2.c
// bbb 1997/06/10 
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "�ɻ���");
	set("long", @LONG
ֱ�����У�����е����ɳط������ԡ�ÿ��ʢ�ģ��ǡ����������Ⱦ����
�ɻ�����Ҷ�򸡻��������ܲ�㣬������̣������������ס��ۡ��졢��졢
������ɫ��Ȼ����ֵ���������̣�΢��������������磬�����˿��⡣
LONG
	);
        set("outdoors", "����");

	set("exits", ([
		"east" : __DIR__"dg1",
		"west" : __DIR__"dg3",
	]));

	set("coor/x",-310);
  set("coor/y",-500);
   set("coor/z",0);
   setup();
}
