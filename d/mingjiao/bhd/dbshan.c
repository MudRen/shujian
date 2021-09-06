// dbshan.c ��ɽ
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"��ɽ"NOR);
	set("long", @LONG
���ɽ���չ�������·������۵Ĺ�â���Ե�ʮ�����������ﵽ�����Ǳ�
ѩ����ɽ�Ĵ���½����֮ɽ��һ����ȥ��������ɣ��ݳ���ʮ�ɣ���ɽ��
�������������в�ʱ�м���С����(fubing)������Ʈ����
LONG);	
	set("outdoors", "����");
	set("arrive", 0);
	set("exits", ([
		"east" : __DIR__"dbshan1",
	]));
	set("item_desc", ([
		"fubing" : "�Աߵĺ�ˮ����Ư���ż��鸡�������������Զ��������û����ȥ��\n",
	]));
	setup();
}

void init()
{
	if ( query("arrive") != 1){
		set("arrive", 1);
		remove_call_out("change");
		remove_call_out("change1");
		call_out("change", random(150) + 50);
	}
	add_action("do_jump", "jump");
}

void change()
{
	tell_room(this_object(),HIW"���ڴ�ʱ��ֻ���ö���������������������ද�������鸡��Ʈ���ˡ�\n"NOR);
	this_object()->set_temp("fubing", 1);
	remove_call_out("change1");
	call_out("change1", 10);  
}

void change1()
{
	tell_room(this_object(),"���г���ӿ���������֮���ֽ���Զȥ�ˡ�\n");    
	set("arrive", 0);
	this_object()->delete_temp("fubing");    
	remove_call_out("change");
	call_out("change", 50+random(150));  
}

int do_jump(string arg)
{
	object me = this_player();
	object room;
	if(!query_temp("fubing")) return 0;
	if( ! arg || arg=="fubing" ) {
		if(!( room = find_object(__DIR__"foubing")))
			room = load_object(__DIR__"foubing");
		if ( room->query("ppl") > 0 ) {
			tell_object(me, "�����Ѿ������ˣ��������Ļ������ܻᷭ��\n");
			return 1;
		}
		message("vision",me->name() + "һ�����������ѵ��˸����ϡ�\n",environment(me), ({me}) );
		me->move(__DIR__"foubing");
		message("vision",me->name() + "�ӱ�ɽ�Ϸ��������\n",environment(me), ({me}) );
		if(random(me->query_dex()) < 50) {
			message_vision("���$Nһ��С�Ľ���һ��������һ����ˤ�ӣ�\n",me);
			me->set_temp("last_damage_from", "ˤ���ڱ�ɽ�ϣ�����Ѫ��");
			me->receive_wound("qi", 50);
			me->receive_damage("qi", 100);
		}
		return 1;
	}
	return 0;
}

void reset()
{
	change1();
	remove_call_out("change");
	remove_call_out("change1");
	call_out("change", random(150) + 50); 
	::reset();
}
