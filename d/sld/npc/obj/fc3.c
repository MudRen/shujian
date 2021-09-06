//mu_fa.c
//wzfeng
#include <ansi.h>
inherit ROOM;
void run_mufa(object me);
void run_mufa1(object me);
void run_mufa2(object me);
int do_order(string arg);
string target;

void create()
{
        set("short", "С����");
        set("long", @LONG
����һ��С��������û��������ֻ�����ź��˵������������ǰƮȥ��
ˮ��վ�ڴ�β�����ڵȴ��������(order ����)��
LONG
);
	set("no_fight",1);
	set("outdoors", "����");
	set_temp("curstatus","ready");
	setup();
}

void init()
{
	add_action("do_order", "order");
}

int do_order(string arg)
{
	mapping myfam;
	int flag=0;
	if( !arg || arg=="" ) return 0;
	if( query_temp("curstatus") == "run") 
		return notify_fail("���Ѿ����ˡ�\n");
        myfam = (mapping)this_player()->query("family");
        if(!myfam || myfam["family_name"] == "������") flag=1;
	if( arg != "����" && arg != "ȥ�뺣��")
		return notify_fail("������ʲô��\n");
		
	target="un";
	if( arg=="ȥ�뺣��"  )
	{
		if (flag) target="hk";
		else return notify_fail("������ʲô��\n");
	}

	message_vision( HIY "$N�Դ�β��ˮ�ִ��˸����ƣ�˵��������������\n" NOR, this_player());
	message_vision( HIY "ˮ����������緫�������÷���\n"+
			"һ�󺣷紵����ֻ��������Ȼ���٣���ǰ��ʻ��ȥ��\n"NOR,this_player());

	set("long", "����һ��С������������緫��ǰ��ʻ�����ź��˵�����������͵�����\n"+
		"ҡ�Ρ���β��ˮ�ֺ���Ҳ��Щ��������������һ����С�ı�����û��\n");
	
	set("player",this_player()->query("id"));
	set_temp("curstatus","run");
	remove_call_out("run_mufa");
	call_out("run_mufa", 10,this_player());
	return 1;
}

void run_mufa(object me)
{
	message("vision","\nС����ͻȻ����һ�գ�������ǰ��ʻ��ȥ��\n", this_object());
	remove_call_out("run_mufa1");
	call_out("run_mufa1", 10,me);
}

void run_mufa1(object me)
{
	message("vision","\nС��������������ʻ��ȥ���㿴����һ��½�ص�Ӱ�ӡ�\n", this_object());
	remove_call_out("run_mufa2");
	call_out("run_mufa2", 10,me);
}

void run_mufa2(object me)
{
	object* ob;
	int i;

	message("vision","\nֻ��С���������ļ��٣������򰶱�ʻȥ��", this_object());
	ob = all_inventory(this_object());
	for(i=0; i<sizeof(ob); i++) {
		if(!objectp(ob[i])) continue;
		if(!ob[i]->is_character()) continue;
		tell_object(ob[i], "�����ˣ���ˮ�ֶ���ߺ��һ����\n");
		message_vision("$N����һԾ�����˴���\n",ob[i]);
		if(target=="hk") ob[i]->move("/d/huanghe/huanghe8");
		else ob[i]->move("/d/sld/haitan");
		tell_room(environment(ob[i]), ob[i]->name() + "����һԾ�����˴���\n",({ ob[i] }));
	}
	if( i > 0)
		message("vision","\nС����������ͷ,����ʻ��󺣡�\n", ob[0]);
	set_temp("curstatus","ready");
}
