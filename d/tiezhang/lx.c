// Room: /u/zqb/tiezhang/lx.c

inherit ROOM;

void create()
{
	set("short", "��Ϫ");
	set("long", @LONG
������������һ��С����Ȼ�ش�ƫƧ��������������������Ȼ�ܶࡣ��
����һ�乩����Ϣ����С�͵ꡣ���Ϸ���ʮ�ﴦ�����Ǵ˴������ĺ�צɽ��
LONG	);
	set("outdoors", "tiezhang");
	set("exits", ([ 
		"southwest" : __DIR__"road-1",
		"north" : "/d/xiangyang/hunanroad2",
		"west" : __DIR__"kedian",
	]));
	set("no_clean_up", 0);

	set("coor/x",-290);
  set("coor/y",-290);
   set("coor/z",-20);
   setup();
}
