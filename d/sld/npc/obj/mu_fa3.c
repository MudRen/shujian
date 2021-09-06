//mu_fa.c
//wzfeng
#include <ansi.h>
inherit ROOM;
void run_mufa(object me);
void run_mufa1(object me);
void run_mufa2();
int do_hua(string arg);
int canhua;

void create()
{
	set("short", "Сľ��");
	set("long", @LONG
������һ��Сľ���ϣ��������ޱ��޼ʵĵ�ãã�󺣣�һ�󺣷����ᴵ����
Сľ������֨��֨��������ҡ�Σ��㲻���ĵ���Щ���飬����ͼȥ��(hua)��
ľ��ǰ����
LONG
);
	set("no_fight",1);

	set("outdoors", "������");
	set_temp("curstatus","ready");

	setup();
}

void init()
{
	canhua=1;
	add_action("do_hua", "hua");
	if(userp(this_player())) {
		remove_call_out("run_mufa2");
		call_out("run_mufa2", 600);
	}
}

int do_hua(string arg)
{
	object me;

	me=this_player();
	if( !arg || arg=="" || canhua==0 ) return 0;

	if(arg!="mufa")
		return notify_fail("��Ҫ��ʲô��\n");

	if(me->query("jing")<30)
		return notify_fail("������̫ƣ���ˣ���Ϣһ���ٻ��ɡ�\n");   
	me->receive_damage("jing", 20);
	message_vision( HIY "$N����ľ���ϵ�һ��ľͷ����ľ����ǰ��ȥ��\n" NOR, me);
	set("player",me->query("id"));
	me->start_busy(5);
	if(canhua==1) {
		canhua=0;
		remove_call_out("run_mufa");
		call_out("run_mufa", 10,me);
	}
	return 1;
}

void run_mufa(object me)
{
	mapping myfam;
 
	message("vision","Сľ��˳�ź��磬һֱ��Ʈȥ��\n", this_object());
    
	myfam = (mapping)me->query("family");
	remove_call_out("run_mufa1");
	if(!myfam || myfam["family_name"] != "������") {
		if(random(10) > 4)
			call_out("run_mufa1", 10, me);
		else
			canhua=1;
	}
	else	 
		call_out("run_mufa1", 10, me);
}

void run_mufa1(object me)
{
	object* ob;
	int i;

	message("vision","ֻ�����䡱��һ����Сľ������ײ����ʲô��������һ�����ӱ����˳�����\n", this_object());
	message("vision","���ͷһ����Сľ��ײ��ɢ�ܣ����������ˡ�\n", this_object());
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if(!living(ob[i])) continue;
		ob[i]->move("/d/sld/dukou");
		tell_room(environment(me), ob[i]->name() + "�����ϰ�����\n",({ ob[i] }));  
	}
	remove_call_out("run_mufa2");
	set_temp("curstatus","ready");
}

void run_mufa2()
{
	object* ob,obj=this_object();
	int i;

	if(query_temp("curstatus",1)=="ready")	return;
	message("vision","ֻ�����䡱��һ����Сľ������ײ����ʲô��������һ�����ӱ����˳�����\n", obj);
	message("vision","���ͷһ����Сľ��ײ��ɢ�ܣ����������ˡ�\n", obj);
	ob = all_inventory(obj);
	for(i=0; i<sizeof(ob); i++) {
		if(!living(ob[i])) continue;
		ob[i]->move("/d/sld/dukou");
		tell_room(obj, ob[i]->name() + "�����ϰ�����\n");  
	}
	set_temp("curstatus","ready");
}
