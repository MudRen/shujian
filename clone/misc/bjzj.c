//File : /clone/misc/bjzj.c By Ciwei@SJ
// 
#include <ansi.h>
#include <armor.h>

inherit FINGER;

string do_drop();

void create()
{
	set_name(HIW "�׽����" NOR, ({ "baijin zuanjie", "zuanjie" }) );
	set_weight(1000);
	if (clonep()) set_default_object(__FILE__);
	{
		set("unit", "ö");
		set("value", 10000000);//ǧ���׵ã�֪������
		set("material", "jade");
		set("armor_prop/armor",1);
		set("no_get",1);
		set("no_drop",(:do_drop:));
		set("no_give",1);
		set("remove_msg","$Nϸ�ĵý�"+name()+"ժ�£����������ղء�\n");
		set("wear_msg","$N��"+name()+"�����Լ�����������Σ�����Ƿ���\n");
	}
	setup();
}

int query_autoload()
{
	return 1;
}

int do_qiuhun(string arg)
{
	object me = this_player();
	object ob = this_object();
	object obj;
	if("/cmds/std/propose"->main(me,arg))
	{
		obj = me->query_temp("pending/marry");
		if(!obj) return 0;
		ob->set_temp("qiu_from",me);
		ob->set_temp("qiu_to",obj);
		message_vision(CYN"˵��$N�Ͱ�"+name()+"����$n���һ���ڴ��ؿ���$p��\n"NOR,me,obj);
		tell_object(obj,YEL"�����Ը��ʹ�����ö��ָ�������Ը��Ͷ������ɡ�\n"NOR);
		move(obj);
		return 1;
	}
	return 0;
}

string do_drop()
{
	object me = this_player();
	if(query_temp("qiu_from") && query_temp("qiu_to") && query_temp("qiu_to")==me)
	{
		if(present(query_temp("qiu_from"),environment(me)))
			message_vision(CYN"$N��$n���ᵫ�Ǻܼ����ҡ��ҡͷ����"+name()+"������$p��\n"NOR,me,query_temp("qiu_from"));
		else
			tell_object(me,"��ѽ�ָ������"+query_temp("qiu_from")->query("name")+"��\n");

		tell_object(query_temp("qiu_from"),YEL"�ۿ���"+me->name()+"�ܾ��������飬No s-f Just Drink(��ϵ��ַ��������¥���һ��һŪӢ����¥)��\n"NOR);
		
		query_temp("qiu_from")->delete_temp("pending/marry");
		move(query_temp("qiu_from"));
		delete_temp("qiu_from");
		delete_temp("qiu_to");
		return "   \n";
	}
	return "�ⶫ������ö�ô��\n";
}

int wear()
{
	object me = this_player();
	if(query_temp("qiu_from") && query_temp("qiu_to") && query_temp("qiu_to")==me)
	{
		if(!"/cmds/std/marry"->main(me,getuid(query_temp("qiu_from"))))
		{
			//write("���ǵȻ��ٴ��ɡ�\n");
			return notify_fail(query_notify_fail());
		}
		message_vision("$Nϲ���̵ش�����"+name()+"��\n",me);
		delete_temp("qiu_from");
		delete_temp("qiu_to");		
	}
	return ::wear();
}

void init()
{
	object ob = this_player();
	
	if (environment() != ob	) return;
	
	if(ob->query("gender")=="����")
	{
		set("long","�����ð׽��Ƶ����,�����ϵ���ʯ����ҫ�۵Ĺ�â~~\nŮ������ϲ���ľ��Ǿ�������ʯ�������ָ���������п����°빦����\n");
		add_action("do_qiuhun",({"qiu","propose"}));
		return;
	}
	if(ob->query("gender")=="����")
	{
		set("long","�����ð׽��Ƶ����,�����ϵ���ʯ����ҫ�۵Ĺ�â~~\nŮ������ϲ���ľ��Ǿ�������ʯ�����⼸�������䣬�����ණ��Ҳ���ر����⡣\n");
		wear();
		return;
	}
	if(query_temp("qiu_from") && query_temp("qiu_to") && query_temp("qiu_to")==ob)
	{
		set("long","�����ð׽��Ƶ����,�����ϵ���ʯ����ҫ�۵Ĺ�â~~\n����"+query_temp("qiu_from")->query("name")+"��������֤���������Ը�������������ʹ������������Ը��Ͷ�������\n");
		return;		
	}
	if (!ob->query("marry/id") || !ob->query("marry/name")) {
		ob->delete("marry");
		call_out("lost", 1);
		return;
	}
	set("long","�����ð׽��Ƶ����,�����ϵ���ʯ����ҫ�۵Ĺ�â~~\n������һ���ӻ�����"+ob->query("marry/name")+"����������һ�̡�\n");
	wear();
}

void lost()
{
	object ob = environment();

	if (userp(ob) && (!ob->query("marry/id") || !ob->query("marry/name"))) {
		message_vision(HIB"\n\n$N�����ң������ԶԶ�ö��˳�ȥ��\n"NOR,ob);
		destruct(this_object());
	}
}
/*
int unequip()
{
	object ob = environment();

	if (ob && userp(ob) && ob->query("marry/id") && ob->query("marry/name"))
		return notify_fail("�㲻��ж����Ķ������\n");

	return ::unequip();
}
*/