// Room: /d/dali/xs1.c
// bbb 1997/06/10 
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "��ɽɭ��");
	set("long", @LONG
����λ�ڴ��СС�ķ��ͼ䡣��Ҫ�ɻ�ͤ�¡�̫���¡���������ŵȷ�
������ɡ���ͤ��λ�ں���2050�׵�ɽ�䣬������14���ͣ����ڵ����ģ��ΰ
׳�ۣ������������ķ��ʥ�ء�̫���½���14���ͳ�����ľ��ʢ������Ϯ�ˡ�
LONG
	);
        set("outdoors", "����");
	set("exits", ([
           "northwest" : __DIR__"shanlu7",
           "south" : __DIR__"lunan",
	   "north" : __DIR__"xs2",
	]));
        set("objects", ([
	     __DIR__"npc/yetu" : 1,
             __DIR__"npc/songshu" : 1,
	]));

	set("coor/x",-260);
  set("coor/y",-430);
   set("coor/z",-20);
   setup();
}
