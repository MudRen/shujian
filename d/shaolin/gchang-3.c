// Room: /d/shaolin/gchang-3.c
// Date: YZC 96/01/19
// by zqb

inherit ROOM;

void create()
{
	set("short", "�㳡����");
	set("long", @LONG
������������ǰ��һ���㳡���㳡���з��Ÿ����˸ߵ���ͭ����¯��ǰ
����Ÿ���̨����λ����������Ӱݡ��Դ�������һ��ƫ��������Ǵ�
���о�֮�á�������һ�����ȣ�ͨ���������
LONG
	);

	set("exits", ([
		"east" : __DIR__"cdian-1",
//		"south" : __DIR__"smdian",
		"west" : __DIR__"gchang-1",
		"north" : __DIR__"celang-3",
	]));

	set("outdoors", "shaolin");
	set("objects",([
		__DIR__"npc/xiang-ke" : 1,
	]));
	set("coor/x",60);
  set("coor/y",220);
   set("coor/z",110);
   set("coor/x",60);
 set("coor/y",220);
   set("coor/z",110);
   setup();
}



