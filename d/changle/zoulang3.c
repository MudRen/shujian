// Room: /d/changle/zoulang.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"������"NOR);
	set("long", @long
����������������Щ��������˯����������ԼԼ�����������ӷ��ﴫ������
�����Ǽ���ӻ�Ĳ񷿣������������̾���ζ�������Ե����ǰ��࣬������һ
Щ����Ĳи�ʣ�ˡ�
long
	);

	set("exits", ([
		"north" : __DIR__"shuifang",
		"east" : __DIR__"zoulang4",
		"south" : __DIR__"chaifang",
	]));

	set("outdoors", "���ְ�");
	setup();
}
