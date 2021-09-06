// hubayin.c ������
// by iceland

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "hu bayin", "hubayin" ,"hu","bayin"}));
	set("long",@LONG
��������Ŀ��࣬��������Ũü�߸�����һ˫ͭ���Ĵ��ۡ��·�һ��Сɽ
�Ƶ�վ�����
LONG
	);
	set("title", HIY "�����µ�ʮ��������" NOR);
	set("gender", "����");
	set("age", 39);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 18);
	set("con", 24);
	set("dex", 24);
	set("max_qi", 900);
	set("eff_jing", 400);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("score", 30000);
	set("unique", 1);

	set_skill("huanxi-chan", 80);
	set_skill("literate", 80);
	set_skill("force", 80);
	set_skill("longxiang-boruo", 80);
	set_skill("dodge", 80);
	set_skill("yuxue-dunxing", 80);
	set_skill("hand", 80);
	set_skill("dashou-yin", 80);
	set_skill("claw", 80);
	set_skill("tianwang-zhua", 80);
	set_skill("wushang-dali",80);
	set_skill("staff",80);
	set_skill("parry", 80 );

	map_skill("force", "longxiang-boruo");
	map_skill("dodge", "yuxue-dunxing");
	map_skill("hand", "dashou-yin");
	map_skill("parry", "wushang-dali");
	map_skill("claw", "tianwang-zhua");

	prepare_skill("hand","dashou-yin");
	prepare_skill("claw","tianwang-zhua");

	create_family("������", 12, "����");
	set("class", "huanxi");

	setup();
	carry_object("/d/xueshan/npc/obj/qinxiu-jiasha")->wear();
	carry_object(BINGQI_D("jingangzuan"))->wield();
	add_money("silver",10);
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "������") {
		 command("say"+ RANK_D->query_respect(ob) +
			"���Ǳ��µ��ӣ������ﵷʲô�ң���");
		return;
	}

	if ((int)ob->query_skill("huanxi-chan", 1) < 50) {
	       command("say ��ϲ���Ǹ����书֮���������ڼ������ɡ�");
		command("say"+ RANK_D->query_respect(ob) +
			"�ٰ�����ͨ��������������б��ŵ��ķ��ɡ�");
		return;
	}

	if ((string)ob->query("class") != "huanxi") {
		message_vision("���������˿���ͷ�������������Լ��Ĺ�ͷ��",this_player());
		command("say �㻹û���ң����ܱ�ʾ���������̷ϲ���Ҳ������㡣");
		command("say ��λ" + RANK_D->query_respect(ob) +
			"�������¾��ģ������̷��ҷ��������Ұɡ�");
		return;
	}

	command("say �ðɣ����Ժ�����ҵĵ����ˣ���Ҫ�̿����ޣ�����͵��ѽ��");
	command("recruit " + ob->query("id"));
	ob->set("title", HIY "�����µ�ʮ��������" NOR);
}
