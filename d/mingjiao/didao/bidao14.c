// /d/mingjiao/bidao14.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
	set("short","����");
	set("long", @LONG
����һ���ϴ�����ҡ��������������������ĵط�������������������ȫ��
������һ�Ŵ�ʯ������������һ���Ѹɿݵĵ����Ժ���(haigu����ֻ��ë����
�·���û���ã����ӷ���һ�߽�Ϊ��С�ĺ���(haigu��������ΪŮ���·�����
���ϲ���һ�Ѷ̽������ǵ����Ծ���æ���������ܽ�Ϊʯ��(wall)��û���κ�
�ĳ�·ͨ�����档
LONG);
	set("objects",([
		__DIR__"../npc/haigu1"  : 1,
		__DIR__"../npc/haigu2"  : 1,
	]));
	set("no_save", 1);
	set("item_desc", ([
		"wall" : "ʯ���ϲ����ҳ�������ϸһ���������м������䡣\n"
	]));                         
	setup();
}

void init()
{
	add_action("do_gua","gua");
	add_action("do_push","push");
}

void check_trigger()
{
	object me;
	me=this_player();
	if( (int)query("push_trigger")==1){
		message("vision", "ʯ��������Ӧ�������ˡ�\n", this_object() );
		set("exits/east", __DIR__"bidao15");
		delete("push_trigger");
		me->delete_temp("marks/��1");
		remove_call_out("close_passage");
		call_out("close_passage", 10);
	}
}

void close_passage()
{
	if( !query("exits/east") ) return;
	message("vision", "ʯ�š����ǡ��������Զ������ˡ�\n", this_object() );
	delete("exits/east");
}

int do_gua(string arg)
{
	object me;
	object weapon;
	me = this_player();
	if (!arg || arg!="wall") return 0;
	if (!objectp(weapon = me->query_temp("weapon")))
		return notify_fail("��Ҫ��ʲô������\n");
	if((string)weapon->query("skill_type")=="axe" ) {
		write("���ô��������ǵġ��������ϣ��ô󸫽�ʯ��ɳ����ȥ��\n\n"+
			"    ֻ��һ������Ȼ���ɵĴ���ʯ���ɵ�ʯ�ţ��ҵ���װ��һ��\n"+
			"���������ɵ����ࡣ�뵱�����̽�����ص�֮ʱ��������������\n"+
			"���������£���֪���˶��ٹ��򣬶�����Ѫ��\n");
		me->set_temp("marks/��1", 1);    
		return 1;
	}
}

int do_push(string arg)
{
	object me;
	me=this_player();
	if (! arg || arg !="men") return 0;
	if (me->query_skill("qiankun-danuoyi",1) < 50)
		return notify_fail("�������˿���������������ʯ����ȥ������ʯ��һ��������\n");
	if ( arg=="men" 
	 && me->query_skill("qiankun-danuoyi",1) >= 50
	 && me->query_temp("marks/��1")){
		message_vision(YEL"\n$NĬ��Ǭ����Ų��ϰ����һ��Ų��Ǭ����ʯ�ŷ�����֨֨����������\n"
				"һ���ô���ʯ���ɵĴ�ʯ��Ӧ������������\n\n"NOR,me);
		add("push_trigger", 1);
		me->start_busy(2);
		check_trigger();
		return 1;
	}
	else {
		write("��Ҫ��ʲô��\n");
		return 1;
	}
}
