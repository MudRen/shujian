// Room: /d/taishan/.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIY"����̨"NOR);
	set("long", @LONG
��������ʱ��ѡ�����书��һ��֮������·Ӣ������սʤ������ͨ������
�ɳ�Ϊͳ����ԭ���ֵ����䡣��̨�ϰڷ��ź���������̨�ϸ߸�����һ���죬
���飺�����е���
LONG
	);

	set("exits", ([
		"down" : __DIR__"yuhuang",
	]));

	set("objects",([
		"/clone/npc/zhong-shentong" :1,
		__DIR__"npc/wei-shi1": 2,
	]));
        set("no_clean_up", 1);
	set("outdoors", "̩ɽ");
	setup();
}
void init()
{
	object me = this_player();
	add_action("do_jieti","jieti");
}

