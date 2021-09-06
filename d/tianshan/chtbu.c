// Room: /d/tianshan/chtbu.c
// By Linux

#include <ansi.h>
inherit ROOM;
string look_deng1();
string look_deng2();
string look_deng3();
string look_deng4();

void create()
{
	set("short", "���첿");
	set("long", @LONG
��ǰ��һ�������������˵Ĵ������ǳ��첿�����ڵأ�����ǽ���ϻ�����
�����춥�ϻ�����һ���������ӣ�ͷ���нǣ����ֳֳ����������ս�������
��һֻ������������𡣵�������ɫ��ʯĥ�ͣ��ֺ��޷죬��Ȼ��ɡ�������
�ǵ�����յ���ƣ������ڴ����������������Ǵӵ��﷢����
LONG);

	set("exits", ([
                "eastdown" : __DIR__"dadao9",
        ]));       

        set("objects", ([
                __DIR__"npc/f-dizi" : 1,
        ]));    

	set("item_desc", ([
		"east deng" : (: look_deng1 :),
		"south deng" : (: look_deng2 :),
		"west deng" : (: look_deng3 :),
		"north deng" : (: look_deng4 :),
	]));
	set("zhbfang", 1);
	setup();	
}

void init()
{
	add_action("do_smell", ({"smell", "wen"}));
	add_action("do_move", ({"move", "yi"}));
}

void reset()
{
	set("zhbfang", 1);
}

string look_deng1()
{
	object me = this_player();
	if (!me->query_temp("ts/smell")) return "ʲô��\n";
	if(random(me->query("kar")+me->query("per")+me->query("pur")) <= 40){
		me->delete_temp("ts/smell");
		return "����ϸ���ŵ�ȼ�ڴ������ǵ�ͭ�ƣ�����û��ʲô������\n";
	}
	else {
		me->set_temp("ts/smell2",1);
		return "����ϸ���ŵ�ȼ�ڴ������ǵ�ͭ�ƣ����ڷ�������һյ�ĵ������ƺ������ƶ���\n";
	}
}

string look_deng2()
{
	object me = this_player();
	if (!me->query_temp("ts/smell")) return "ʲô��\n";
	if(random(me->query("kar")+me->query("per")+me->query("pur")) <= 40){
		me->delete_temp("ts/smell");
		return "����ϸ���ŵ�ȼ�ڴ����Ͻǵ�ͭ�ƣ�����û��ʲô������\n";
	}
	else {
		me->set_temp("ts/smell2",1);
		return "����ϸ���ŵ�ȼ�ڴ����Ͻǵ�ͭ�ƣ����ڷ�������һյ�ĵ������ƺ������ƶ���\n";
	}
}

string look_deng3()
{
	object me = this_player();
	if (!me->query_temp("ts/smell")) return "ʲô��\n";
	if(random(me->query("kar")+me->query("per")+me->query("pur")) <= 40){
		me->delete_temp("ts/smell");
		return "����ϸ���ŵ�ȼ�ڴ������ǵ�ͭ�ƣ�����û��ʲô������\n";
	}
	else {
		me->set_temp("ts/smell2",1);
		return "����ϸ���ŵ�ȼ�ڴ������ǵ�ͭ�ƣ����ڷ�������һյ�ĵ������ƺ������ƶ���\n";
	}
}

string look_deng4()
{
	object me = this_player();
	if (!me->query_temp("ts/smell")) return "ʲô��\n";
	if(random(me->query("kar")+me->query("per")+me->query("pur")) <= 40){
		me->delete_temp("ts/smell");
		return "����ϸ���ŵ�ȼ�ڴ������ǵ�ͭ�ƣ�����û��ʲô������\n";
	}
	else {
		me->set_temp("ts/smell2",1);		
		return "����ϸ���ŵ�ȼ�ڴ������ǵ�ͭ�ƣ����ڷ�������һյ�ĵ������ƺ������ƶ���\n";
	}
}

int do_smell(string arg)
{
	object me=this_player();
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");
	tell_object(me,"����ϸ���ſ�������������ƺ�������������������ζ��ͬ�����ɵİ�������!\n");
	me->set_temp("ts/smell",1);
	me->add_busy(2);
	return 1;
}

int do_move(string arg)
{
	object ob, *ob2;
	object here = this_object();
	object me = this_player();
	int i;

	if (me->is_busy() || me->is_fighting())	return notify_fail("����æ���أ�\n");
	if (!me->query_temp("ts/smell2"))
		return notify_fail("ʲô��\n");
	if( (!arg) || !((arg == "deng") || (arg == "��") || (arg == "tong deng") || (arg == "ͭ��")))
		return notify_fail("��Ҫ�ƶ�ʲô��\n");
	if (query("zhbfang") < 1)
		return notify_fail ("���ͭ�����Ա������ƣ���û�����κζ�����\n");

	ob=new(__DIR__"npc/zhbfan");
	ob->move(environment(me));
	message_vision(HIW"$N��ͭ�����Ա������ơ�\n"NOR, me);
	message_vision(HIW"ͻȻһ����Ӱ��$N���˹�����\n"NOR, me);
	message_vision(HIR"׿������$N���һ������Ȼ���ϵ�ɽ��������Ҫ��������Щ��ν���ӣ�ƴ�������һ\n"+
			"��Ȼ�����" + RANK_D->query_rude(me) + "�����ˣ��������������һ\n"NOR, me);
	here->add("zhbfang",-1);
	ob2 = all_inventory(here);
	for(i=0; i<sizeof(ob2); i++) {
		if(! ob2[i]->is_character()) continue;
		if( ob2[i]->is_corpse()) continue;
		ob->kill_ob(ob2[i]);
		ob2[i]->kill_ob(ob);
	}
	me->delete_temp("ts/smell1");
	me->delete_temp("ts/smell2");
	return 1;
}

int valid_leave(object me,string dir)
{
	me->delete_temp("ts/smell");
	me->delete_temp("ts/smell2");
	return ::valid_leave(me);
}
