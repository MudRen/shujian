// Room: /city/beimen.c
// YZC 1995/12/04 
#include <room.h>
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "��Ұ����");
	set("long", @LONG
	������һ����ս�����ż��������Ҳ���Ұ�ݴ����������н�ʬ��û������������

LONG
	);
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"south" : __DIR__"beidajie2",
                "west" : __DIR__"postoffice",
          "east" : __DIR__"work2",
	]));
	set("outdoors", "city");
	setup();
}

//�Ǿ���
int is_mirror() { return 1; }