// Room: /d/city/beidajie2.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
	������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"beimen",
  "west" : __DIR__"wumiao",
  "south" : __DIR__"beidajie1",
  "east" : __DIR__"zuixianlou",
]));
	set("outdoors", "city");

	setup();
}
//�Ǿ���
int is_mirror() { return 1; }