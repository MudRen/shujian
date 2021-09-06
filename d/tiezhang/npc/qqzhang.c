// qqzhang.c ��ǧ��
// Modify by Lklv 2001.10.18
// lane 2004.12.24 add ����

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_qiubai();
int ask_naogui();
int ask_gold();

void create()
{
	set_name("��ǧ��", ({ "qiu qianzhang", "qiu", "qianzhang" }));
	set("long",
	"����һ��������ͷ�����Ƹ�������㴩��Ь�����ֻ���һ�Ѵ����ȡ�\n"
	"���������ͻ������ı��顣\n");
	set("gender", "����");
	set("age", 60);
	set("attitude", "friendly");
	set("unique", 1);
	set("shen_type", -1);
       	set("str", 23);
	set("int", 30);
	set("con", 26);
	set("dex", 25);
	set("env/wimpy", 70);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 80);
	set("combat_exp", 200000);
	set("score", 40000);

	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("strike", 60);
	set_skill("parry", 60);
	set_skill("literate", 60);
	set_skill("tiezhang-zhangfa", 60);
	set_skill("guiyuan-tunafa", 60);
	set_skill("shuishangpiao", 60);
	set_skill("tiezhang-xinfa",60);

	map_skill("force", "guiyuan-tunafa");
	map_skill("strike", "tiezhang-zhangfa");
	map_skill("parry", "tiezhang-zhangfa");
	map_skill("dodge", "shuishangpiao");
	prepare_skill("strike", "tiezhang-zhangfa");

	create_family("���ư�", 15, "����");

	set("chat_chance_combat", 3);
	set("chat_chance", 3);
	set("chat_msg", ({
		"��ǧ�ɴ�����ֵ�˵���������ư��������µ����飬û��үү��֪���ģ���\n",
		"��ǧ�����ص�˵����������������һ����Ĺ����˵���ﾭ���ֹ���\n",
		"��ǧ�����ص�˵������һ���ڹ������гɣ��Ϳ��Դӻ�����ľ�в���������ˣ���\n",
		"��ǧ��˵��������ָ��ڶ�ָ�ڴ�����һ�����ص����ڣ���˵���ѹʰ��������֮������\n",
		(: random_move :)
	}));
	set("chat_msg_combat", ({
		YEL"��ǧ����ɫ�����������������ˣ����ȥ����������������ʮ���գ����ɼ��磬����С��������\n\n"NOR,
		YEL"��ǧ�𼱵������ٲ�ס�֣�үү�ɾ�Ҫ�������ˣ�����\n\n"NOR,
		(: random_move :)
	}));
	set("inquiry", ([
		"name" : "�ȸ����������һ�����֣�����ô��ǧ�ɡ��������Ų�������Ҳ���ѵ�������\n",
		"here" : "����������ư����̳���ڣ�����û�£���Ҫ�Ĵ����ߣ�����ɱ��֮��������\n",
		"�Ϲٽ���" : (: ask_qiubai :),
		"�ֹ�" : (: ask_naogui :),
	//	"��ң��" : (: ask_gold :),
	]));

	setup();
	carry_object(__DIR__"obj/huiyi")->wear();
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping fam = ob->query("family");
	mapping my_fam = me->query("family");

	if(ob->query("gender")=="����"){
		command ("say �ٺ٣����ư�ɲ��������ֲ��в�Ů���˰���");
		return;
	}
	if (fam && fam["family_name"] != "���ư�"
	 && (int)ob->query("is/tiezhang") == 1 ) {
		message_vision(BLU "$N�������������������ͽ��������ʲô ������\n"NOR, ob );
		command("slap "+ob->query("id"));
		return;
	}
	if ((int)ob->query("shen") >= 0) {
		command("hehe");
		command("say ����ģ�үү������������Ĵ������С���˵�����");
		return;
	}
	if( fam && fam["generation"] == my_fam["generation"] ){
		command("haha");
		command("say "+RANK_D->query_respect(ob)+"�������³��ϵĵ����ˣ�����Ϊʦ����ѽ��");
		return;
	}
	if( fam && fam["master_name"] == "��ǧ��"){
		command("haha");
		command("say "+RANK_D->query_respect(ob)+"�����ҵܵܵĵ����ˣ�"+RANK_D->query_self(me)+"������˼���ҵܵ���ͽ�ܣ�");
		return;
	}
	if( fam && fam["master_name"] == "�Ϲٽ���"){
		command("ah");
		command("say �Ϲٰ����������ѹ����������");
		command("say "+RANK_D->query_respect(ob)+"ԭ�����ϰ������ŵ��Ӱ���ʧ����"+RANK_D->query_self(me)+"����������Ϊͽ��");
		return;
	}
	command("haha");
	command("say үү���书�������������޺úø�����ѧ��׼û��");
	command("recruit " + ob->query("id"));
	ob->set("is/tiezhang",1);
}

int ask_qiubai()
{
	say("�������ư�ĵ�ʮ������������˵ʮ��ǰ���˰��㣬���ں�������֪�����Ǽ٣�\n");
	return 1;
}

int ask_naogui()
{
	say("��һЩ����˵�����������������ϵķ�Ĺ�У������������ٺ٣�һ����ʲô���������棡\n");
	this_player()->set_temp("marks/��1", 1);
	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) +
		"���ǻ����ˣ�����������үү��ѵ��ѵ�㣡��\n");
	command("say ��Ӵ����⣬��⣬�������治���ɣ����һ�ᣬ�Ҷ���ʹ��Ҫ������\n");
	return 0;
}

int ask_gold()
{
	object me;
	int skill, gold;
	mapping myfam;
	me = this_player();
	skill = me->query_skill("tiezhang-zhangfa", 1);
	myfam = (mapping)me->query("family");

	if( !myfam || myfam["family_name"] != "���ư�" ) {
		command("nod2");
		command("say ��ң�ݾ���үү�ҿ��ģ������������µ����飬û��үү��֪���ģ�");
		return 1;
	}

	if( (int)me->query("tz_given") >= (int)me->query("age") ) {
		command("hmm "+(string)me->query("id"));
		command("say �ҽ��겻���Ѿ�������Ǯ���������Թ�ȥ��̽��Ϣ����");
		return 1;
	}

	if( (int)me->query("age") < 18 || skill < 50 ) {
		command("yawn");
		command("say ������Сϸ�첲Сϸ�ȣ�����ʲô�ð���\n");
		return 1;
	}

	gold = skill * 15000;
	if( 100 >= skill ) gold += gold/4;
	me->add("balance", gold);
	me->set("tz_given", (int)me->query("age"));
	command("say үү�Ҿ��ǡ���ң�ݡ������ˣ�����ң�ݡ��ڽ����Ϻպ�������");
	command("say ��ЩǮ����ȥ���Ժ����Ҵ�̽Щ��Ϣ�ɣ�" + MONEY_D->money_str(gold) + "�Ѿ��������Ǯׯ��");
	return 1;
}
