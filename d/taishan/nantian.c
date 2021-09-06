// Room: /d/taishan/.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ʮ���̣��������̩ɽ������ڴ��������︽��ɽ�£�Ⱥɽ����
�أ����������ƣ���ؿ������޿���״���������������߿ɵ�һ���м�����
���߱����¹۷壬���������ǵ���ʶ�֮·��
LONG
	);

	set("exits", ([
//		"eastup" : __DIR__"tianjie",
		"northup" : __DIR__"yuhuang",
//		"west" : __DIR__"yueguan",
		"southdown" : __DIR__"shengxian",
	]));

	set("objects",([
                __DIR__"npc/qinbing" : 1,
		__DIR__"npc/qinbing1" : 2,
	]));

	set("outdoors", "̩ɽ");
	setup();
}

int valid_leave(object me, string dir)
{

	if(dir == "northup"
		&& present("qinbing", environment(me))
		&& me->query("combat_exp") < 100000 ) {
                return notify_fail(HIY "�ױ��ӳ���Ȼ��ŭ���ȵ�������, ����ɧ�����������Ҹ���ƴ�ˣ�\n");
	}
       	if(dir == "northup"
               && present("qinbing duizhang", environment(me))
               && me->query("combat_exp") >= 100000) 
                      message_vision("�ױ��ӳ�������λӢ�������롣\n", me);
	return ::valid_leave(me, dir);
}
