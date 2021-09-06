// caiji@SJ 8/25/2000
// for a job

#include <room.h>
#include <ansi.h>
inherit ROOM;

string look_guo();

void create ()
{
	set ("short", "ҩ®");
	set ("long", @LONG
�����������ɵ�ҩ®�����޵����Ը��ײ��߼��࣬������ҽ��ᣬ����
Ҳ�������ˣ�����׼����һЩ��ҩ�����ڹ����ϡ����ӽ��䴦����һ�ڴ�
������guo���������޵����Լ�����ҩ�õġ�
LONG);

	set("item_desc", (["guo" : (: look_guo :) ]));

	set("exits", ([ //sizeof() == 4
		"south" : __DIR__"ryd",
	]));
	
	set("resource", ([ /* sizeof() == 1 */
		"water" : 1,
	 ]));

	setup();
}


void init()
{					     
	add_action("do_add", "fang");
	add_action("do_add", "add");
	add_action("do_jian", "jian");
	add_action("do_jian", "ao");
}

int do_add(string arg)
{
	string item_name;
	object who = this_player();
	object item;
	mapping fam=who->query("family");

	if (who->is_busy()) 
		return notify_fail("��������æ���أ�\n");

	if (!fam || fam["family_name"] !="������")
		return notify_fail("�㲻�����޵��ӣ����������ﰾҩ��\n");

	if(!arg) 
		return notify_fail("��Ҫ��ʲô�����ӽ����\n");

	if( sscanf(arg, "%s in guo", item_name)!=1 )
		return notify_fail("�÷���fang <����> in guo��\n");

	if (item_name=="water") {
		message_vision( "$N������Ҩ��һ��ˮ��\n",who);
		who->set_temp("cook/allow", 1);
		return 1;
	}

	item = present(item_name, who);

	if (! present(item_name, who)) 
		return notify_fail("������û���ⶫ����\n");

	if ( item->query("cook/allow") !=1 ) 
		return notify_fail("�����������ҩ�ģ���ʲô�����������ӡ�\n");

	if ( !item->query("cook/owner") || item->query("cook/owner") != who) 
		return notify_fail("������͵��˭�Ķ�������������ذ���\n");

	message_vision(HIC"$N��һ"+item->query("unit")+item->query("name")+HIC"�ӽ����\n"NOR,who);

	if ( who->query_temp("cook/"+item->query("cook/type")) < item->query("cook/value"))
		who->set_temp("cook/"+item->query("cook/type"), item->query("cook/value"));

	who->set_temp("last_put", 1);
	destruct(item);
	return 1;
}

int do_jian(string arg)
{
	object who = this_player();
	object gao;
	mapping fam=who->query("family");
	int prices;
	if (who->is_busy()) return notify_fail("��������æ���أ�\n");
	if (!fam || fam["family_name"] !="������")
		return notify_fail("�㲻�����޵��ӣ����������ﰾҩ��\n");

	if(!arg || arg != "yao") return notify_fail("��ɶ��\n");

	if ( !who->query_temp("cook/allow"))
		return notify_fail("������ˮ��û�У���ô��ҩ��\n");

	if (!who->query_temp("last_put"))
		return notify_fail("����������Ŷ�����û�а���\n");

	prices = who->query_temp("cook/xiezi") * who->query_temp("cook/shachong") * who->query_temp("cook/zhizhu") * who->query_temp("cook/wugong");

	if(!prices ) 
		gao=new("/d/xingxiu/obj/yao");
	else {
		gao=new("/d/xingxiu/obj/gao");
		if(prices<10 && prices>0 )
			prices=10+random(10);
		if(prices>200)
			prices=200+random(100);
		gao->set("xx/owner",who);
		gao->set("prices",prices);
		gao->set("long",gao->query("long")+"�����������ɵ�"+who->name()+"��ҩ®�������ģ�\n");
	}
	message_vision(HIY"$N�ڹ�����ҽ��˽���Ȼ�󰾰������������������ڰ�����"+gao->query("name")+HIY"��\n"NOR,who);
	who->start_busy(2+random(3));
	gao->move(who);

	who->delete_temp("cook/allow");
	who->delete_temp("cook/wugong");
	who->delete_temp("cook/zhizhu");
	who->delete_temp("cook/shachong");
	who->delete_temp("cook/xiezi");
	who->delete_temp("last_put");

	return 1;
}

string look_guo()
{
	object me = this_player();
	if ( me->query_temp("last_put"))
		return "һ�ڴ���������ҩ��(ao yao)���������߰���Ĳ�֪��(fang)��Щʲô��\n";
	else
		return "һ�ڴ�������������Ӷ�����(add)����ҩ��(ao yao)��\n";
}
