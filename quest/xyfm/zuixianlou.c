// Room: /d/city/zuixianlou.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "��¥");
	set("long", @LONG
	��¥Ϊ����Ъɽ������Ͳ�����������ߡ����¹��Ĳ㣬
�����ϡ������濪����94��������������á�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"beidajie2",
  	
]));
	setup();
}

//�Ǿ���
int is_mirror() { return 1; }