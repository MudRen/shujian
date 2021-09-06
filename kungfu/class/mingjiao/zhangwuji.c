// NPC zhangwuji.c ���޼�
// Modify By River@SJ 99.6

#include <ansi.h>
#include "zhangwuji.h";
inherit NPC;
inherit F_MASTER;
string ask_book();
string ask_qishang();
string ask_shu();
string ask_me();
int ask_hdg();
string ask_ling();
string ask_getling();
string ask_fel();
int pfm_zhen();
int pfm_chan();
int pfm_yi();
int pfm_qishang();
int pfm_tougu();
int pfm_tisha();
int pfm_duanhun();
int ask_hu_quest();
int ask_hu();

void create()
{
	object weapon;
	set_name("���޼�",({"zhang wuji","zhang","wuji"}));
	set("title",HIY"���̵���ʮ�Ĵ�����"NOR);
	set("long", "���������̵ĵ���ʮ�Ĵ����������ϴ���Ӣ�ʲ�����Ц�ݡ�\n");
	set("age", 25);
	set("per", 32);
	set("attitude", "friendly");
	set("shen", 40000);
	set("str", 35);
	set("int", 30);
	set("con", 50);
	set("dex", 30);

	set("max_qi", 12500);
	set("max_jing", 7500);
	set("neili", 18600);
	set("eff_jingli", 7500);
	set("max_neili", 18500);
	set("jiali", 150);
	set("combat_exp", 4850000);
	set("unique", 1);
	set("no_bark",1);

	set_skill("sword", 340);
	set_skill("dodge", 350);
	set_skill("force", 370);
	set_skill("dagger", 380);
	set_skill("strike", 340);
	set_skill("hanbing-mianzhang", 340);
	set_skill("piaoyi-shenfa", 350);
	set_skill("tiyunzong", 320);
	set_skill("shenghuo-lingfa", 380);
	set_skill("jiuyang-shengong", 380);
	set_skill("lieyan-dao", 230);
	set_skill("blade", 230);
	set_skill("liehuo-jian", 230);
	set_skill("taiji-jian", 320);
	set_skill("taiji-quan", 330);
	set_skill("parry", 380);
	set_skill("cuff", 380);
	set_skill("qiankun-danuoyi", 380);
	set_skill("qishang-quan", 360);
	set_skill("literate", 250);
	set_skill("medicine", 190);
	set_skill("shenghuo-shengong", 340);
	set_skill("shenghuo-fumozhen", 200);
	set_skill("yingzhua-shou", 320);
	set_skill("hand", 320);

	map_skill("force", "jiuyang-shengong");
	map_skill("cuff","qishang-quan");
	map_skill("dagger","shenghuo-lingfa");
	map_skill("sword","taiji-jian");
	map_skill("dodge", "tiyunzong");
	map_skill("blade", "lieyan-dao");
	map_skill("strike", "hanbing-mianzhang");
	map_skill("parry", "qiankun-danuoyi");
	prepare_skill("cuff","qishang-quan");

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
//		(: pfm_chan :),
		(: pfm_tisha :),
		(: pfm_qishang :),
		(: pfm_tougu :),
		(: pfm_yi :),
		(: pfm_zhen :),
		(: pfm_duanhun :),
	}));

	create_family("����",34,"����");

	set("inquiry", ([
		"��˹����" : "����������Դ�ڲ�˹���̣����м�������ʷ�ˣ�����С�����Ҷ�ȥ��\n"+
			"�β�˹��������֪���ɺã������г�˼��������......",
		"ʥ����" : "ʥ�����������̵�ʥ�����ʧ����ꡣ",
		"лѷ" : "�常���ټ������ǲ��������˽��ġ�",
		"����ͨ"  : (: ask_hu_quest :),
		"����ţ"  : (: ask_hu :),
		"������"  : (: ask_hdg :),
		"�ؼ�"  : (: ask_book :),
		"����ȭ��"  : (: ask_qishang :),
		"����ȭ��" : (: ask_shu :),
		"����" : (: ask_me :),
		"����" : (: ask_ling :),
		"������" : (: ask_getling :),
		"���Ʒ�����" : (: ask_fel :),
	]));

	set_temp("apply/damage", 90);
	set_temp("apply/dodge", 90);
	set_temp("apply/attack", 90);
	set_temp("apply/armor", 90);
	setup();

	if (clonep()){
		if( sizeof(filter_array(children(BINGQI_D("shangshan_ling")), (: clonep :))) > 0 )
			weapon = new(BINGQI_D("tieling"));
		else if( sizeof(filter_array(children(BINGQI_D("fae_ling")), (: clonep :))) > 0 )
			weapon = new(BINGQI_D("tieling"));
		else weapon = unew(BINGQI_D("sf_ling"));
		if (!weapon) weapon = new(BINGQI_D("tieling"));
		carry_object(BINGQI_D("sword"));
		weapon->move(this_object());
		weapon->wield();
		carry_object("/d/mingjiao/obj/white-cloth")->wear();
	}
}

void init()
{
	::init();
	add_action("do_lingwu","taojiao");
	add_action("do_kill", "kill");
	add_action("do_kill", "teamkill");
	add_action("do_kill", "tk");
	add_action("do_kill", "hit");
}

void reset()
{
	object ob;

	if (clonep()) {
		if (!(ob = unew(BINGQI_D("shangshan_ling"))))
			return;
		destruct(ob);
		if (!(ob = unew(BINGQI_D("fae_ling"))))
			return;
		destruct(ob);
		if (ob = unew(BINGQI_D("sf_ling"))) {
			ob->move(this_object());
			command("wield shangshanfae ling");
		}
	}
}

void attempt_apprentice(object ob)
{
	mapping fam = ob->query("family");
	if (!fam || fam["family_name"] != "����"){
		command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}
	if((int)ob->query_skill("shenghuo-shengong", 1) < 150) {
		command("say ������֮ʥ�����˼��õ��ڼ��ķ���");
		command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ�������ڹ��϶��µ㹦��");
		return;
	}
	if((int)ob->query_skill("medicine", 1) < 80) {
		command("say ����ѧ���ӣ��������������ҽ�顣");
		command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ�����ڱ��������϶��µ㹦��");
		return;
	}
	if((int)ob->query_skill("literate", 1) < 100) {
		command("say ����ѧ���ӣ���Ҫ��ѧ�ñ����ȱ���ʫ�顣");
		command("say "+RANK_D->query_respect(ob)+"�Ƿ�Ӧ�����ڶ���д���϶��µ㹦��");
		return;
	}
	if((int)ob->query("shen") < 100000) {
		command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
		command("say �ڵ��з��棬"+RANK_D->query_respect(ob)+"�Ƿ����ò�����");
		return;
	}
	if(ob->query_int() < 32) {
		command("say �ҵ��书��Ҫ���ߵ����Բ���ѧ�ᡣ");
		command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
		command("say "+RANK_D->query_respect(ob)+"�����Ի�����Ǳ�����ڣ�������ذɡ�");
		return;
	}
	command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
	command("say ��л������ӣ����������ֵ�һ���ģ�Ϊ�������壬�������̷�����ɡ�");
	command("recruit " + ob->query("id"));
	ob->set("title",HIR"���̽����״�����"NOR);
	if( ob->query_skill("dagger", 1) < ob->query_skill("balde", 1) ){
		ob->set_skill("dagger", ob->query_skill("balde", 1));
		tell_object(ob, "���ܵ�����ָ�㣬ذ���Ѿ��ﵽ�˵����ľ��磡\n");
	}
}

int do_kill(string arg)
{
	object ob,ob2;
	object me = this_player();
	ob2 = this_object();

	if (!arg) return 0;
	ob = present(arg, environment(me));
	if (ob == this_object() || ob == me) return 0;
	if (!ob || !ob->is_character()) return 0;


	if (userp(ob) && ob->query("family/family_name") == "����") {
		if (me->query("family/family_name") == "����") {
			message_vision(ob2->name()+"��$N�ȵ�����Ϊ���̵��ӣ���Ȼɱ�Լ���ͬ�ţ��������㣡\n", me);
		}
		else {
			message_vision(ob2->name()+"��$N�ȵ����󵨿�ͽ����Ȼ���ѱ������������\n", me);
			kill_ob(me);
		}
		me->set("vendetta/����", 1);
		return 1;
	}
	return 0;
}
