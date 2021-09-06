// Room: /city/beimen.c
// YZC 1995/12/04 
#include <room.h>
inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "����");
	set("long", @LONG
	���Ǳ����ţ���Ϊ����ʧ�𣬵����ڳ�ǽ���Ǻں����ģ���˰�
ֽ���ֵĹٸ���ʾ(gaoshi)���Ե��ر����ۡ�������һƬ��ɽ���룬һ��
����С����ɽ�����Ѷ��ϡ�
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