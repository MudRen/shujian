// Room: /u/jpei/guiyun/road1.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
һ��������С·����Զ�����ƺ�����һ��С�ӡ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","����ׯ");

	set("objects",([
		__DIR__"npc/youke" : 1,
	]));  
	set("exits", ([
        "east": "/d/suzhou/hubiandadao",
		"west": __DIR__"rivere",
	]) );

	set("coor/x",110);
  set("coor/y",-330);
   set("coor/z",0);
   setup();
}

