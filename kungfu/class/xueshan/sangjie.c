// sangjie.c ɣ��
// by iceland

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ɣ��", ({ "sang jie", "sangjie" ,"sang","jie"}));
	set("long",@LONG
��������ݣ��������ݣ���ɫ�ڻƣ��ƺ�����������˫�ۺܳ������Ϲǽڱ���
�������ֹ���ʮ���˵á�
LONG
	);
	set("title", HIY "�����·�ǰ�ܻ���" NOR);
	set("gender", "����");
	set("class", "huanxi");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 35);
	set("int", 30);
	set("con", 35);
	set("dex", 35);

	set("max_qi", 1800);
	set("eff_jing", 500);
	set("max_jing",500);
	set("neili", 2100);
	set("max_neili", 2100);
	set("jiali", 50);

	set("combat_exp", 800000);
	set("score", 4000);
	set("unique", 1);

	set_skill("huanxi-chan", 160);
	set_skill("literate", 100);
	set_skill("force", 160);
	set_skill("longxiang-boruo", 160);
	set_skill("dodge", 160);
	set_skill("yuxue-dunxing", 160);
	set_skill("claw", 160);
	set_skill("tianwang-zhua", 160);
	set_skill("hand", 160);
	set_skill("dashou-yin", 160);
	set_skill("xuedao-jing", 160);
	set_skill("blade", 160);
	set_skill("parry", 160);
	set_skill("staff",160);
	set_skill("wushang-dali",160);
	set_skill("poison",100);

	map_skill("force", "longxiang-boruo");
	map_skill("dodge", "yuxue-dunxing");
	map_skill("blade", "xuedao-jing");
	map_skill("hand", "dashou-yin");
	map_skill("parry", "wushang-dali");
	map_skill("claw", "tianwang-zhua");
	map_skill("staff","wushang-dali");

	prepare_skill("hand","dashou-yin");
	prepare_skill("claw","tianwang-zhua");

	create_family("������", 11, "����");
	set("class", "huanxi");

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: exert_function, "shield sang jie" :),
		(: perform_action, "hand.tianyin" :),
	}));

	setup();
	carry_object("/d/xueshan/npc/obj/changsheng-jiasha")->wear();

	add_money("silver",50);
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") == "����" ) {
		command("say ʩ�������ȱ����˵�����ն�����������...\n");
		return;
	}
	if ((string)ob->query("family/family_name") != "������") {
		command("say"+ RANK_D->query_respect(ob) +"���Ǳ��µ��ӣ������ﵷʲô�ң���");
		return;
	}

	if ((int)ob->query_skill("longxiang-boruo", 1) < 120) {
		command("say �Ҵ����¸����书�����ڹ��ศ��ɡ�");
		command("say"+ RANK_D->query_respect(ob) +"�ٰ�����ͨ��������������б��ŵ��ڹ��ɡ�");
		return;
	}
	command("say ��Ĺ����Ѿ������ˣ��Ժ�͸���ѧ�ɡ�");
	command("recruit " + ob->query("id"));
	ob->set("title", HIY "�����µ�ʮ��������" NOR);
}
