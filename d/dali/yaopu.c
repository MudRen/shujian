// Room: /dali/yaopu.c
// Modify By River 98/12
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIC"ҩ��"NOR);
	set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�С
������ɢ�������ġ�ҩ���ƹ�������ڲ輸�ԣ����Ժ��Ų裬��Ҳ������һ�ۡ�
һ��С���վ�ڹ�̨���к��Ź˿͡���̨������һ�ŷ��Ƶ�ֽƬ��
LONG
	);
	set("objects", ([
//      "/d/zhiye/obj/yaolu" : 1,
		"/d/zhiye/npc/yaodian-zhanggui" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"dongjie2",
	]));
	set("no_fight", 1);
	set("no_zhiye", 1);
	set("incity", 1);
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
		me->set_temp("dali_xc/yaopu",1);
}
