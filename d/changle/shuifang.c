// Room: /d/changle/shuifang.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "˯��");
	set("long", @long
�����ǳ��ְ��˯��������ƹ�ڰ��������Ծɵ�ľ���������ڵ�ǽ�ǡ�
��Ϊ����̿�ʢ�У��ſ��м����˰��ء����ð��е����ܰ�Ȼ��˯�����غ���
�д̡�
long
	);

	set("sleep_room", 1);
	set("no_fight", 1);
	set("exits", ([
                "south" : __DIR__"zoulang3",
	]));

	setup();
}
