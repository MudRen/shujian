// bing.c �ٱ�

inherit NPC;

void create()
{
	set_name("ֵ�ڱ�", ({ "zhiqin bing", "bing" }));
	set("age", 22);
	set("gender", "����");
	set("long", "��Ȼ�ٱ������ղ��ܺ�������ʿ��ȣ��������ǽ��������˶�������\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 25000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

	set("chat_chance", 2);
	set("chat_msg", ({
		"ֵ�ڱ��ȵ���վס����ʲô�ģ�\n",
		"ֵ�ڱ��ȵ����󵨵��񣬾����췴���ɣ�\n",
	}));
	setup();
	carry_object(BINGQI_D("gangdao"))->wield();
	carry_object(ARMOR_D("junfu"))->wear();
}

void init()
{
	object ob;
	::init();
	
	if(interactive(ob = this_player()) 
	&& visible(ob) 
	&& !is_fighting()
	&& ob->query("shen") < 0) {
		message_vision("$N�ȵ����󵨵��񣬾���˽������Ҫ�أ�ɱ��\n",ob);
		kill_ob(ob);
		return;
	}
}
