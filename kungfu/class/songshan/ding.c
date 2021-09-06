// deng.c ��ɽ�ɵ�������� ���� 2004.12.15 add ask gold
// Lklv 2001.10.18 Modified

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int ask_gold(object who);

void create()
{
	set_name("����", ({ "ding mian", "ding", "mian" }));
	set("nickname", HIR"������"NOR);
	set("long", "����λ���ֵ����ߣ�����Ŀ�ΰ������ɽ�������˵Ķ�ʦ�������ֶ��㡣\n");
	set("gender", "����");
	set("age", 51);
	set("per", 18);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 33);
	set("int", 23);
	set("con", 25);
	set("dex", 25);
	set("unique", 1);
	set("env/wimpy", 70);

	set("max_qi", 3000);
	set("max_jing", 2000);
	set("eff_jingli", 2000);
	set("max_neili", 3500);
	set("jiali", 50);
	set("combat_exp", 1500000);
	set("shen", -640000);

	set_skill("literate", 100);
	set_skill("force", 160);
	set_skill("parry", 165);
	set_skill("sword", 150);
	set_skill("dodge", 150);
	set_skill("hand", 160);
	set_skill("zhongyuefeng", 160);
	set_skill("songyang-shou", 160);
	set_skill("hanbing-zhenqi", 160);
	set_skill("songshan-jian", 160);

	map_skill("force", "hanbing-zhenqi");
	map_skill("dodge", "zhongyuefeng");
	map_skill("hand", "songyang-shou");
	map_skill("parry", "songshan-shou");
	map_skill("sword", "songshan-jian");

	prepare_skill("hand", "songyang-shou");
	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: perform_action, "hand.junji" :),
		(: exert_function, "juhan" :),
	}));

	create_family("��ɽ��", 3, "����");

	set("inquiry", ([
	//	"��������" : (: ask_gold :),
		"����": "������и����ֽУ�����������(junji)����ȡ�Դ˾����塣",
		"��������": "�ٺ٣��뵱�����������˺�ɽ�������ᣬ�õľ��������ַ��ľ�����",
		"��ɽ��" : "������ɽ������������֮�ף�\n",
		"��������" : "������������������֮�������޴󣬿������֡��䵱���⡣\n",
		"������" : "���������ǵ������ˣ�������ɲ⡣\n",
	]) );

	setup();
	carry_object(ARMOR_D("changpao1"))->wear();
	add_money("gold", 1);
}

int ask_gold(object who)
{
	object me = this_player();
	int gold = 0;

	if( me->query("family/family_name") != "��ɽ��" ) {
		command("say ������ɽ�ɵ��£�" + RANK_D->query_respect(me) + "����ǲ�Ҫ���֣�");
		return 1;
	}

        if( (int)me->query_skill("hanbing-zhenqi", 1) < 216 ) {
		command("say " + RANK_D->query_respect(me) + "���ú�ѧϰ����ɽ���书�������ʶ�������������������Σ�");
		return 1;
	}

	if( me->query("songshan_given") >= 300 ) {
		command("say " + RANK_D->query_respect(me) + "�书��ǿ����Ȼ���ĳ������Ǿͷ������ϵЩ������������������ɣ�");
		return 1;
	}

	if( (int)me->query("songshan_given") + 10 < (int)me->query_skill("hanbing-zhenqi", 1) ) {
		if( (int)me->query_skill("hanbing-zhenqi", 1) > 300 ) 
			gold = 300 - (int)me->query("songshan_given");
		else gold = (int)me->query_skill("hanbing-zhenqi", 1) - (int)me->query("songshan_given");
		gold *= 10000;

		if( (int)me->query_skill("literate", 1) < 100 ) gold *= 5; 
		else if( (int)me->query_skill("literate", 1) >= 150 ) gold *= 3; 
		else gold *= 4; 

		command("interest");
		me->add("balance", gold);
		me->set("songshan_given", (int)me->query_skill("hanbing-zhenqi", 1));
		command("say ���ղ�����" + RANK_D->query_respect(me) + "����ѧ�ƺ��������ٰ���");
		command("say ��Ȼ" + RANK_D->query_respect(me) + "���ģ�����ͽ�" + MONEY_D->money_str(gold) + "�������Ǯׯ���㶨Ҫ�ú�����Ⱥ�������ɶ������֮λ����");
	} else command("say " + RANK_D->query_respect(me) + "������ɽ�����书�ư����֣�����ѧ���������ð���");
	return 1;
}

#include "app3.h";
