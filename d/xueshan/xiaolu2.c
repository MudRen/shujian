// Room: xiaolu2.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
������ߵ�һ��С·����ǰ��������ͷ����֪��ͨ�����·��Ұ���ҷ���
�������裬�������Լ��ĽŲ�����������ֻ����һ����һ���͵�������
LONG
	);

	set("exits", ([
		"east" : __DIR__"xiaolu3",
		"northwest" : __DIR__"xiaolu1",
	]));
        set("outdoors", "ѩɽ");
	set("coor/x",-250);
  set("coor/y",120);
   set("coor/z",0);
   setup();
}
