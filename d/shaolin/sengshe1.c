// Room: /d/shaolin/sengshe1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "ɮ��");
	set("long", @LONG
������ɮ����͵ĵط�����ǽ�����������һ��̫ʦ�Ρ�ǽ��һ������
�ż���������и�������������ˡ����ݴ�������׭�֣������������ڣ���
���Ǹ�����²衣һλСɳ����һ�ߴ���վ����
LONG
	);

	set("exits", ([
		"west" : __DIR__"celang2",
		"south" : __DIR__"sengshe3",
		"north" : __DIR__"sengshe2",
	]));
//        set("no_get_from", 1);

	set("objects",([
		CLASS_D("shaolin") + "/hui-he" : 1,
	]));
	set("coor/x",70);
  set("coor/y",280);
   set("coor/z",110);
   setup();
}



