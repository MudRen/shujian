// lu.c ½��˫
// By River@SJ 
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("½��˫", ({ "lu wushuang", "lu", "wushuang" }));
	set("long", "ֻ����һ�Ź���������Ϊ������Ƥɫ��Ȼ������𪣬����ò������\n");
	set("gender", "Ů��");
	set("age", 17);
	set("attitude","firendly");
	set("str", 22);
	set("dex", 23);
	set("con", 20);
	set("int", 24);
	set("per", 25);
	set("shen_type", 1);

	set_skill("parry", 120);
	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("sword", 120);
	set_skill("throwing",100);
	set_skill("meinu-quanfa", 120);
	set_skill("cuff", 120);
	set_skill("meinu-quanfa", 120);       
	set_skill("yunu-shenfa", 120);
	set_skill("yunu-jianfa", 120);
	set_skill("yunu-xinjing", 120);
	map_skill("force", "yunu-xinjing");
	map_skill("dodge", "yunu-shenfa");
	map_skill("cuff", "meinu-quanfa");
	map_skill("sword", "yunu-jianfa");
	prepare_skill("cuff", "meinu-quanfa");

	set("combat_exp", 700000);

	set("max_qi", 1700);
	set("max_jing", 1200);
	set("eff_jingli", 1200);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali",30);

	set("chat_chance", 60);
	set("chat_msg", ({ (: random_move :) }) );

	setup();
	carry_object("/d/gumu/obj/qun1")->wear();
	carry_object(BINGQI_D("changjian"))->wield();
	call_out("dest", 1500, this_object());
}

void dest(object ob)
{
	if(!ob) return;
	destruct(ob);
}

void unconcious()
{
	object me, book;
	me = query_temp("last_damage_from");
	
	if(!objectp(me)){
		tell_room(environment(this_object()),CYN"\n½��˫����һ����ԭ������ʦ���˰����������ҹ��ˡ����һؼ�ȥ��\n\n"NOR);
		destruct(this_object());
		return;
	}
        
	if (me->query_temp("limochou/ask")){
		book = new(__DIR__"obj/wudu");
		book->set("owner", me->query("id"));
		book->move(me);
		message_vision(CYN"\n½��˫����һ�����������Ǳ�����ô���Ҳ�Ҫ�ˡ�\n\n"NOR,me);
		message_vision("�Աϣ�½��˫��һ���鶪�˹�����˳������Ծ��������$N�ӹ���󣬵��£�Ҳ����׷�ϡ�\n\n",me);
		destruct(this_object());
		return;
	}
	else{
		message_vision(CYN"\n½��˫˵����СŮ�ӿɲ������ˡ�\n\n"NOR,me);
		message_vision("����δ�䣬½��˫һ��ת����ȻԶȥ��\n\n",me);
		destruct(this_object());
		return;
	}
}

void die()
{
	unconcious();
}
