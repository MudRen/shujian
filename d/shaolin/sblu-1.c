// Room: /u/zqb/shaolin
// by zqb

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
������һ��������ʯ��·�ϡ�������һ�׼����ľ޴�ʯ��������ɵģ�
���Բ���ʮ������Ҳ�������⡣�����ǲ���Űأ�ֱ�����죬�϶��������
��������ա�����ɮ���������������䡣·�ľ�ͷ�������Ž�ڻԻ͵Ĵ�
�۱��
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"celang-4",
		"southwest" : __DIR__"celang-2",
                "south" : __DIR__"twdian",
                "north" : __DIR__"xianglu",
		]));
         set("objects",([
          CLASS_D("shaolin") + "/hui-ming" : 1,
          __DIR__"npc/zjseng1" : 1,
          __DIR__"npc/slseng1" : 1
      ]));

	set("outdoors", "shaolin");
	set("coor/x",50);
  set("coor/y",250);
   set("coor/z",110);
   set("coor/x",50);
 set("coor/y",250);
   set("coor/z",110);
   setup();
}
