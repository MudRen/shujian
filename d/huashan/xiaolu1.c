// Room: /d/huashan/xiaolu1.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "Сɽ·");
	set("long", @LONG
�����ǻ�ɽ��һ��Сɽ·�����ƽ�Ϊƽ�������������ط���ô�վ�������
��������ܾ����ĵģ�������߽���һ��������Դ��
LONG
	);
	set("exits", ([
		"southeast" : __DIR__"yunu",
		"northwest" : __DIR__"xiaolu2",
	]));
	set("no_clean_up", 0);
	set("outdoors", "��ɽ" );

	set("coor/x",60);
  set("coor/y",40);
   set("coor/z",60);
   setup();
}