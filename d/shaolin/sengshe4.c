// Room: /d/shaolin/sengshe4.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ɮ��");
	set("long", @LONG
������ɮ���д��͵ĵط�����ǽ�����������һ��̫ʦ�Ρ�ǽ��һ����
���ż���������и�������������ˡ����ݴ�������׭�֣������������ڣ�
�ƺ��Ǹ�����²衣
LONG
	);

	set("exits", ([
		"east" : __DIR__"celang1",
//		"west" : __DIR__"zhulin4",
		"south" : __DIR__"sengshe6",
		"north" : __DIR__"sengshe5",
	]));
//        set("no_get_from", 1);
	set("objects",([
		CLASS_D("shaolin") + "/hui-xu" : 1,
	]));
	set("coor/x",30);
  set("coor/y",290);
   set("coor/z",120);
   setup();
}



