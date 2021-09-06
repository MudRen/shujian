//caiji@SJ 8/24/2000
#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;

void create()
{
	set_name("����", ({ "kan shou", "kanshou", "shouwei" }) );
	set("gender", "����" );
	set("title", "���������");
	set("age", 35);
	set("location", 1);
	set("unique", 1);
	set("long", "����������������������ȣ�һ�������ĵĵ��ӡ�\n");
	set("str", 20);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
	set("per", 30);
	set("shen", -7500);

	set_skill("force", 105);
	set_skill("huagong-dafa", 115);
	set_skill("dodge", 110);
	set_skill("zhaixingshu", 110);
	set_skill("strike", 110);
	set_skill("chousui-zhang", 110);
	set_skill("poison", 110);
	set_skill("parry", 110);
	set_skill("staff", 110);
	set_skill("tianshan-zhang", 110);
	set_skill("literate", 70);
	set_skill("claw", 110);
	set_skill("sanyin-zhua", 110);
	map_skill("claw", "sanyin-zhua");
	prepare_skill("claw", "sanyin-zhua");
	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixingshu");
	map_skill("strike", "chousui-zhang");
	map_skill("parry", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");

	set("max_qi", 2000);
	set("max_jing", 2000);
	set("eff_jingli", 1800);
	set("score", -14000);
	set("combat_exp", 750000);
	set("chat_chance_combat", 5);
	set("chat_msg_combat", ({
		(: exert_function, "huagong" :),
		(: perform_action, "strike.biyan" :),
	}));
	create_family("������", 2, "����");
	set("attitude", "peaceful");
	set("inquiry", ([
		"������" : "����������е���û��ûС�ġ��Ժ�����ɣ�",
		"caiji" : "�ǿ���λ�˲�������ˣ�",
		"�ʼ�" : "�ʼ�����е���û��ûС�ġ��Ժ�з��ɣ�",
	]));	
	setup();
	carry_object(BINGQI_D("gangzhang"))->wield();
	carry_object(ARMOR_D("changpao"))->wear();
	add_money("silver", 10);
}

int do_xian(string arg)
{
	object me=this_object();
	object who, obj;
	who = this_player();

	if(who->is_busy() || who->is_fighting()) 
		return notify_fail("����æ���ء�\n");
	if(me->is_busy() || me->is_fighting()) 
		return notify_fail("û����������æ����\n");
	if(!arg || !objectp(obj = present(arg, who))) 
		return notify_fail("��Ҫ�׸�����ʲô������\n");
   
	if(!who || environment(who) != environment()) return 0;
	if(userp(obj)){
		command("consider "+(string)who->query("id"));
		command("say ���ø�����������ƭ�ң�");
		return 1;
	}
	message_vision(HIY"\n$n�Ϲ��Ͼ��ؽ�"+obj->query("name")+HIY"�ó���˫�����ϣ���Ҫ�׸�$N��\n\n"NOR, me, who);     
	if(me->is_busy()) {
		command("say ����æ���أ���ȵȡ�");
		return notify_fail("��������ȵȡ�\n");
	}
	if((obj->query("id") == "zhizhu" 
	|| obj->query("id") == "wugong" 
	|| obj->query("id") == "xiezi" 
	|| obj->query("id") == "shachong") 
	&& obj->query("cook/owner") == who){
		command("nod "+(string)who->query("id"));
		command("say �����ģ�\n");
		message_vision(HIY"$N��$n"HIY"�����Ա�һ����̳������ó�����ͭǮ��\n"NOR,me, obj);
		remove_call_out("destroying");
		call_out("destroying", 0, obj, me,who);		       
		me->add_busy(2);
		who->add_busy(2);
		return 1;
	}
	if(obj->query("money_id")) {
		command("pat " + who->query("id"));
		command("say Ǯ���е��ǣ����Ժ��������Լ��ɡ�");
		return 1;
	}
	if(obj->query("cook/allow") && obj->query("cook/owner") != who->query("id")){
 //fixed by caiji��change who to who->query("id")
		command("hehe "+(string)who->query("id"));
		command("say ������������Ӳ�����ץ�ġ�");
		return 1;
	}
	else return 1;       
}

void destroying(object obj, object ob, object me)
{   
	int gain;
	object n_money;

	if(obj){
		gain=obj->query("cook/value")+1+random(4);
		destruct(obj);
	}
	if(!ob) return;
	if(!me || environment(me) != environment()){
		command("say �ף����أ�");
		return;
	}
	command("nod "+me->query("id"));
		message_vision(HIY"$N��$n˵����������������������Ҫ�ģ�лл��λ"+RANK_D->query_respect(me)+"�ĺ�������\n"NOR,ob, me);
	n_money = new("/clone/money/coin");
	n_money->move(me); 
	n_money->add_amount(random(50));
	if((!me->query_temp("xx_zuji")) && me->query("combat_exp") > 100000)
		gain /= 4;

	if ( me->query("combat_exp") < 2000000){
		me->add("combat_exp", gain);
		me->add("potential", gain/5);
		if ( me->query("potential", 1) > me->query("max_pot", 1) )
			me->set("potential" , me->query("max_pot", 1));
		tell_object(me, YEL "��ľ����Ǳ�ܸ�������"+chinese_number(gain)+"�㣡\n" NOR);
		log_file("job/chong",sprintf("%8s%-10s��%5d������ץ�棬�õ�����:%3d��Ǳ�ܣ�%2d���־��飺%d��\n",
			me->name(), "("+getuid(me)+")", me->query("job_time/���ް���"),gain,gain/5,me->query("combat_exp")),me);
	}
	me->add("job_time/���ް���",1);
	message_vision(HIY"$N��$n˵����һ��С��˼�����ɾ��⣬�´����ٰ�æ����\n$N����$n����ͭǮ��\n"NOR,ob,me);
	return;      
}

void init()
{       
	object me;
	me = this_player();
	::init();
	add_action("do_order", "order");
	add_action("do_xian", "xian");
}

int do_order(string arg)
{
	object env,me;

	me = this_player();
	env = environment(this_object());

	if(arg=="remove" && (me->query_temp("chonggu_allow") || (int)me->query("family/generation")<=2) &&
	 (string)env->query("short")=="������" && (string)me->query("family/family_name")=="������" &&
	 (!env->query("exits/north"))){
		me->delete_temp("chonggu_allow");
		message_vision("$n��$N��������˵�˼��仰��\n", me,this_object());
		message_vision("$N����˵������Ȼ�ѵõ�����Ӧ�ʣ����Ե�������붾��ȡ�\n",this_object());
		message_vision("ֻ��$N�������Ա�һ��ʯͷ�ϰ���һ����\n", this_object());
		env->open_enter1();
		//call_out("open-enter",2);
		//env->start_call_out( (: call_other, env, "open-enter":), 2);
		message_vision("$N�����ʱ������yell��һ���Ϳ����ˡ�\n",me);
		return 1;
	}
	else if(arg=="defense" && (me->query_temp("chonggu_allow") || (int)me->query("family/generation")<=2) &&
	 (string)env->query("short")=="������" && (string)me->query("family/family_name")=="������"&&
	 env->query("exits/north")){
		me->delete_temp("chonggu_allow");
		message_vision("$N��$n��������˵�˼��仰��\n", me,this_object());
		message_vision("$N����˵������Ȼ��ˣ����Ե����Ϲ��ţ���ֹ���˽�ȥ��\n",this_object());
		message_vision("ֻ��$N�������Ա�һ��ʯͷ�ϰ���һ����\n", this_object());
		env->close_enter1();
		return 1;
	}
	else
		return 0;
}
