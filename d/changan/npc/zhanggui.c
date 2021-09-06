// Write By Yanyang@SJ 2001.9.20
// NPC: /d/changan/npc/zhanggui.c

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>

void create()
{
	set_name("��¥�ƹ�",({ "jiulou zhanggui", "zhanggui" }) );
	set("long", "���Ǿۺ���¥���ƹ񡣾�¥����СС�����鶼��������\n"+
		"���������������ϯ��������Ԥ�����硣\n");

	set("shen_type", 1);
	set("str", 20);
	set("unique", 1);
	set("gender", "����");
	set("age", 45);
	set("combat_exp", 35000);
	set("qi", 300);
	set("max_qi", 300);
	set("attitude", "friendly");

	set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);

	set("vendor_goods", ({
		(["name":FOOD_D("hdjiudai"),"number":20]),
		(["name":FOOD_D("jitui"),"number":20]),
		(["name":FOOD_D("kaoya"),"number":15]),
	}));

	set("inquiry", ([
		"��ϯ" : "����¥�������־�ϯ�������硢Ⱥ���磬�͹�Ҫ��ding����һ�ְ���",
	]));

	setup();

	carry_object(ARMOR_D("cloth"))->wear();
	add_money("silver", 50);
}

void init()
{        
	add_action("do_list", "list");
	add_action("do_buy", "buy");
	add_action("do_ding","ding");
}

int do_ding(string arg)
{
	object me = this_player();
	mixed *ob_list;
	int max,i;
	object obj;
//	object room;

	if(!arg) {
		command("say ��Ҫ���������硱�͡�Ⱥ���硱����һ�־�ϯ��");
		return 1;
	}
	if(arg != "������" && arg != "Ⱥ����") {
		command("say ��Ҫ���������硱�͡�Ⱥ���硱����һ�־�ϯ��");
		return 1;
	}
	if(me->query_temp("zhubanren"))  {
		command("say �͹٣�����"+ me->query_temp("��ϯ") +"�Ѿ�׼�����ˣ�����¥�á�start���Ը����ǿ��磡");
		return 1;
	}
          
	ob_list = filter_array(children(USER_OB), (: clonep($1) && !wizardp($1) :));
	max=sizeof(ob_list);

	for(i=0;i<max;i++) {
		obj = ob_list[i];
		if (obj->query_temp("zhubanren")) {
			command("say ��Ǹ���������ڲٰ�" + obj->query("name") +"("+capitalize(obj->query("id"))+")��"+ obj->query_temp("��ϯ",1)+"�أ�");
			return 1;
		}
	}

	if (! me->query_temp("��ϯ")){
		switch (arg){
			case "������":	me->set_temp("��ϯ", arg);	break;
			case "Ⱥ����":	me->set_temp("��ϯ", arg);	break;
			default:	return notify_fail("û��������ϯ��\n");
		}
		command("say �õģ�������λ"+RANK_D->query_respect(me)+"���ƽ���������Ϳ����ˡ�");
		return 1;
	}
	command("say �ţ���λ�͹ݲ����Ѿ�Ԥ����"+me->query_temp("��ϯ")+"��ô��");
	return 1;
}

int accept_object(object me, object ob)
{
	if( ob->query("money_id")) {
		if ( me->query_temp("��ϯ") && ob->value() >= 5000000) {
			if (!me->query_temp("zhubanren")) {
				command("smile");
				command("say �õģ�������Ͳٰ죬�͹�¥���룬�á�start���Ը����ǿ��磡");
				me->set_temp("zhubanren",1);
				return 1;
			}
			command("? "+me->query("id"));
			command("say ��λ�͹ٵ�Ǯ̫���ˣ�");
			return 0;
		}
		command("? "+me->query("id"));
		command("say ��λ�͹ٵ�Ǯ̫���ˣ�");
		return 0;
	}
	command("? "+ me->query("id"));
	command("say ��λ"+RANK_D->query_respect(me)+"��������"+ob->query("unit")+ob->query("name")+CYN"���𰡣�"NOR);
	return 0;
}
