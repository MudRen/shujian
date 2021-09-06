// Room : /d/wudang/guangchang.c  �䵱�㳡
// by ydh
#include <ansi.h>
inherit ROOM;
int do_zhao(string arg);

void create()
{
	set("short",HIG"�䵱�㳡"NOR);
	set("long", @LONG
����һ���ɴ��ʯ���̳ɵĹ㳡�����������������ܣ�ʮ������������ȫ��
ǽ�ǻ�ɢ���ż���������ʯ����һЩ������䵱����ѧϰ�书�ͻ����д��
�ص㡣��Χ��������ͩ����һ������������ص���Ҷ��һ���������ĵ�ͯ��
�ڴ�ɨ���ϱ�������������
LONG                           
	);
	set("outdoors", "�䵱");
	set("exits", ([
		"south" : __DIR__"zhenqing",
		"north" :__DIR__"nanyan",
	]));

	set("objects",([
		__DIR__"npc/daotong" :1,
	]));
	set("yaochu_count", 5);

	setup();
}

void reset()
{
	::reset();
	set("yaochu_count", 5);
}

void init()
{
	add_action("do_zhao", ({"zhao","find"}));
}

int do_zhao(string arg)
{
	mapping fam; 
	object me,yc;
	me=this_player();
	fam = me->query("family");

	if ( arg != "yao chu" )
		return notify_fail("��Ҫ��ʲô��\n");
              
	if (!fam || fam["family_name"] != "�䵱��")
		return notify_fail("���ֲ����䵱���ӣ��ܵ��䵱��Ϲ��ʲ�ᶫ������\n");

	if (query("yaochu_count") < 1) {
		message_vision("$N��ǽ�ŵ�������﷭����ȥʲôҲû���š�\n", me);
		return 1;
	}

	if (me->query_temp("yaochu_get"))
		return notify_fail("��ô��ô̰�������ù�һ������\n");         
 
	if (me->query("combat_exp",1) <= 20000)
		return notify_fail("������䵱��ҪϹ��������\n");

	yc = new(MISC_D("yaochu"));
	message_vision("$N��ǽ�ŵ�������﷭����ȥ�ҳ�һ��ҩ����\n", me);
	me->set_temp("yaochu_get",1);
	add("yaochu_count", -1);
	yc->move(me);
	return 1;
}
