// Room: /d/city/xidajie1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "�ǳ�");
	set("long", @LONG
	ɽ���صĳǳأ��ܳ�Լ4�����һ��С�ǣ������ǳ��볤����������
��Ϊ�ء��Ǹ�14�ף���7�ס�ȫ����������Ҫ���ţ����ж��ֹŴ��ķ�����������
һ��������ϵ�Ƚ������ĳǹء�
LONG
	);
	set("outdoors", "city");

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"xidajie2",
  "north" : __DIR__"yamen",
  "south" : __DIR__"bingyindamen",
  "east" : __DIR__"guangchang",
]));

	setup();
}
//�Ǿ���
int is_mirror() { return 1; }