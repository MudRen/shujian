// Room: /city/bingqiku.c
// YZC 1995/12/04 
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
	�����Ǳ����⣬�������������������ۻ����ҡ��������������𹿰�����
�����������ڰ����̵����̽����̹�����ɫ�����ı���Ӧ�о��У���һʱ��֪����
ʲô�á�
LONG
	);
	set("exits", ([
		"north" : __DIR__"bingyin",
	]));
	setup();
}
//�Ǿ���
int is_mirror() { return 1; }
