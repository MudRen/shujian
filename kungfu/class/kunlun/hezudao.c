// hezudao.c (kunlun)

inherit NPC;
#include <ansi.h>
string ask_qin();

void create()
{
	object ob;
	set_name("�����", ({ "he zudao", "he" }));
	set("title", "�����ɿ�ɽ��ʦ");
	set("nickname", "������ʥ");
	set("long",
		"�����������ɿ�ɽ��ʦ���ų��ٽ��������ġ�������ʥ����\n"
		"������Ŀ���ݹ����⣬ԼĪ��ʮ��������͡�\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("per", 27);
	set("str", 27);
	set("int", 60);
	set("con", 40);
	set("dex", 28);

	set("max_qi", 10000);
	set("max_jing", 6500);
	set("neili", 18000);
	set("eff_jingli", 7000);
	set("max_neili", 17000);
	set("jiali", 150);
	set("combat_exp", 4500000);
	set("unique", 1);
	set("score", 40000);

	set("chat_chance_combat", 85);
	set("chat_msg_combat", ({
  		(: perform_action, "sword.xunlei" :),
  		(: perform_action, "sword.hundun" :),
	}));

	set("inquiry", ([
		"��" : (: ask_qin :),
		"��β��" : (: ask_qin :),
	]));

	set_skill("art", 250);
	set_skill("literate", 250);

	set_skill("force", 380);
	set_skill("xuantian-wuji", 380);
	set_skill("dodge", 360);
	set_skill("taxue-wuhen", 360);
	set_skill("xunlei-jian", 400);
	set_skill("strike", 350);
	set_skill("kunlun-zhang", 350);
	set_skill("parry", 360);
	set_skill("sword", 380);
	set_skill("cuff", 380);
	set_skill("zhentian-quan", 380);
	set_skill("leg", 380);
	set_skill("chuanyun-tui", 380);
	set_skill("liangyi-jian", 220);


	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("strike", "kunlun-zhang");
	map_skill("cuff", "zhentian-quan");
	map_skill("leg", "chuanyun-tui");
	map_skill("parry", "xunlei-jian");
	map_skill("sword", "xunlei-jian");
	prepare_skill("strike", "kunlun-zhang");

	set_temp("apply/sword", 100);
	set_temp("apply/parry", 100);
	set_temp("apply/force", 100);
	set_temp("apply/dodge", 100);
	set_temp("apply/strike", 100);
	set_temp("apply/damage", 75);

	create_family("������", 1, "��ɽ��ʦ");
	setup();
	if (clonep()) {
		ob = unew(BINGQI_D("sword/jwqin"));
		if (!ob) ob = new(BINGQI_D("guzheng"));
		ob->move(this_object());
		ob->wield();
		carry_object("/d/kunlun/obj/pao1")->wear();
	}
}
void attempt_apprentice(object ob)
{
	if(ob->query_int() < 32 ) {
		command("say ����������Ҫ���Լ��ߵ��˲ſ������������У��������书�������ۡ�");
		command("say "+RANK_D->query_respect(ob)+"�����Ȼ�ȥ�������ɡ�");
		return;
	}
	if ((int)ob->query_skill("xuantian-wuji", 1) < 130) {
		command("say �����黭��ΪС������Ҳ�������������С�");
		command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ�����������޼����϶��µ㹦��");
		return;
	}
	if ((int)ob->query_skill("art", 1) < 120) {
		command("say ��������ʥ�����彣���ƣ�������Ҳ���ˡ�");
		command("say " + RANK_D->query_respect(ob)+
			"�Ƿ������黭����Ϊǳ��Щ�أ�");
		return;
	}
	if ((int)ob->query("max_neili", 1) < 1000) {
		command("say ����������һ�Ķ����������߻���ħ��");
		command("say " + RANK_D->query_respect(ob) +
			"�Ƿ�Ӧ���Ⱥú�����������");
		return;
	}
	if ( ob->query("gender") == "����" && ob->query_skill("zhentian-quan", 1) < 80 ){
		command("say "+ RANK_D->query_respect(ob) +"�Ƿ�Ӧ����������ȭ�϶��µ㹦��");
		return;
	}
	if ( ob->query("gender") == "Ů��" && ob->query_skill("chuanyun-tui", 1) < 80 ){
		command("say "+ RANK_D->query_respect(ob) +"�Ƿ�Ӧ�����ڴ������϶��µ㹦��");
		return;
	}

	command("say ������Ҳ���������ˣ��Ҿͽ���һЩ�ٽ����֪ʶ�ɡ�");
	command("recruit "+ob->query("id"));
	ob->set("appren_hezudao", 1);
        ob->set("title",HIW"������ʥ��ǰ����"NOR);
}
void reset()
{
	object ob;

	if (clonep() && (ob = unew(BINGQI_D("sword/jwqin")))) {
		ob->move(this_object());
		command("wield jiaowei qin");
	}
}

string ask_qin()
{
	object me = this_player();

	if (me->query("family/master_name") != "�����")
		return "�⽹β�����������ɵı���㲢���ҵĴ��ˣ����ܸ��㣡";

	if (present("jiaowei qin",this_object())) {
		command("unwield jiaowei qin");
		command("give jiaowei qin to " + me->query("id"));
		return "�⽹β�پ͸����ˣ����Ҫ���Ʊ��ܺã�";
	}
	return "�������ˣ���β�����Ѿ����������ˡ�";
}
