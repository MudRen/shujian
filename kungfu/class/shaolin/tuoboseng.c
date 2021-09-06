// tuoboseng.c
// 2004.12.14 lane add ask gold

inherit NPC;

int ask_gold(object who);
void create()
{
	set_name("�в�ɮ", ({"tuobo seng","seng"}));
	set("title", "���ֵ���");
	set("long", "����һλδͨ���ʵ�������У����Ϲ��ź������΢Ц��\n");

	set("gender", "����");
	set("attitude", "heroism");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 15);
	set("int", 30);
	set("con", 30);
	set("dex", 18);
	set("max_qi", 880);
	set("max_jing", 500);
	set("neili", 380);
	set("max_neili", 380);
	set("jiali", 7);
	set("combat_exp", 120000);
	set("shen_type", 1);
	set("chat_chance", 30);

	set("chat_msg", ({
		"�в�ɮ˵��: ����λʩ�����������Ӹ�ƶɮ���������£��츣������\n",
		(: random_move :)
        }) );

        set("inquiry", ([
               // "��Ե" : (: ask_gold :),
        ]));

	set_skill("force", 41);
	set_skill("cuff", 41);
	set_skill("dodge", 41);
	set_skill("parry", 41);
	set_skill("shaolin-shenfa", 42);
	set_skill("jingang-quan", 41);
	set_skill("yijin-jing", 41);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");
	prepare_skill("cuff","jingang-quan");

	create_family("������", 40, "����");
	setup();
        carry_object("/d/putian/npc/obj/cloth")->wear();
        carry_object("/d/putian/npc/obj/sengxie")->wear();

	setup();
}

int accept_object(object me, object ob)
{
	object ling;
	//add by look@SJ because ���˽�ر��
	//add by caiji@SJ because �����³��ҵ��ӽ��������֡�
	if( ob->query("money_id") && ob->value() >= 10000 && ((me->query("class") != "bonze"
	&& ( me->query("family/family_name") != "������"))
	|| me->query("gender")== "Ů��")) {
		command("smile");
		command("say �����ӷ𣬶�л��λ" + RANK_D->query_respect(me) + " ��");
		command("say " + RANK_D->query_respect(me) +
		"������ƺ�ʩ�����������գ����·�������һ������Ӣ�ۣ���֪��Ը����������һ�Σ�");
		ling=new("/d/shaolin/obj/tie-ling");
		ling->move(me);
		message_vision("�в�ɮ��$Nһ���������ơ�\n", me);
		command("say ������ʱһ�գ���ʱʧЧ��������ʱǰ���£�������в��㣬�м��мǣ�");
	}
	else return notify_fail("�в�ɮ˵����" + RANK_D->query_respect(me) + "��ƶɮ��Щ��������֪�Ǻ����⣿\n");
	return 1;
}

int ask_gold(object who)
{
	object me = this_player();
	int gold = 0;

	if( me->query("family/family_name") != "������" ) {
		command("say ����λʩ�����������Ӹ�ƶɮ���������£��츣������");
		return 1;
	}

	if( me->query("shen") < 0 ) {
		command("say " + RANK_D->query_respect(me) + "��Ϊ���ֵ��ӣ�ȴ����������ʵ�ڴ�Ӧ�ð���");
		return 1;
	}
	if( (int)me->query_skill("buddhism", 1) < 30 ) {
		command("say " + RANK_D->query_respect(me) + "��Ϊ���ֵ��ӣ������֮������������˵ļ��࣡");
		return 1;
	}
        if( (int)me->query_skill("yijin-jing", 1) < 216 ) {
		command("say " + RANK_D->query_respect(me) + "��Ϊ���ֵ��ӣ��ڹ���˲��ã�ϣ�����Ŭ����");
		return 1;
	}
        if( (int)me->query_skill("yijin-jing", 1) > 300 ) {
		command("say " + "���Ѿ�����ɮ�ˣ���Ҫ��Ե��������Ц����");
		return 1;
	}	
	if( (int)me->query("shaolin_given") + 10 < (int)me->query_skill("yijin-jing", 1) ) {
		gold = (int)me->query_skill("yijin-jing", 1) - (int)me->query("shaolin_given");
		if( (int)me->query_skill("yijin-jing", 1) >= 180 ) gold *= 3; 
		else if( (int)me->query_skill("yijin-jing", 1) >= 120 ) gold *= 2; 
		//gold *= 30;000
		gold *= 15000;
		if( random(2) ) gold = gold + random(gold/3);
		else gold = gold - random(gold/4);
		command("buddhi tuobo seng");
		me->add("balance", gold);
		me->set("shaolin_given", (int)me->query_skill("yijin-jing", 1));
		command("say ���ղ���" + RANK_D->query_respect(me) + "�ķ���Ϊ�ָ���һ�㣬������̾���簡��");
		command("say ���ľͽ���Щ���������������и����㣬" + MONEY_D->money_str(gold) + "�Ѿ�����Ǯׯ����" + RANK_D->query_respect(me) + "��֮���أ��츣������");
		log_file("static/WEAL",
		sprintf("%s������ָ���,�׽�ȼ�:%d,�ƽ�:%s",
		me->query("id"),
		(int)me->query_skill("yijin-jing", 1),
		MONEY_D->money_str(gold))
		);
	} else command("say �����ڴ˻�Ե�Ѿã������Լ�֮����������£��츣������");
	return 1;
}

void unconcious()
 {
         remove_all_killer();
         remove_all_enemy();
         say("�������˵�����������Ĳ��������Ǻã�\n");
         reincarnate();
         set("eff_qi", query("max_qi"));
         set("qi", query("max_qi"));
         set("eff_jing", query("max_jing"));
         set("jing", query("max_jing"));
         set("jingli", query("eff_jingli"));
         clear_conditions_by_type("poison");
 }
 
 void die()
 {
         unconcious();
 }
