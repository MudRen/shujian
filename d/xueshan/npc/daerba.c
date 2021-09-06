// daerba.c �����
// by iceland
// Modify by Lklv 2001.10.16

#include <ansi.h>

inherit NPC;
string ask_master();

void create()
{
        object weapon;
        set_name("�����", ({ "daer ba", "daerba" ,"daer","ba"}));
        set("long",@LONG
���ǽ��ַ������¶����ӣ�������������ݣ�����ľګ���Խ����㡣
��˫��ȴ�ǽ�ͻ����˫�־޴�����������
LONG
        );
        set("title", HIY "�����½��ַ������µ���" NOR);
        set("gender", "����");
	set("class", "huanxi");
        set("age", 45);
  	set("attitude", "peaceful");
	set("shen_type", -1);
        set("str", 50);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 1500);
        set("eff_jing", 500);
	set("max_jing", 500);
        set("neili", 1700);
        set("max_neili", 1700);
        set("jiali", 70);
        set("combat_exp", 650000);
        set("score", 60000);
	set("unique", 1);

	set("inquiry", ([
		"���ַ���"   : (: ask_master:),
	]));

        set_skill("huanxi-chan", 140);
        set_skill("literate", 80);
        set_skill("force", 140);
        set_skill("longxiang-boruo", 140);
        set_skill("dodge", 140);
        set_skill("yuxue-dunxing", 140);
        set_skill("staff", 160);
        set_skill("wushang-dali", 160);
        set_skill("hand", 140);
        set_skill("dashou-yin", 140);
        set_skill("parry", 140 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "wushang-dali");
        map_skill("staff", "wushang-dali");

        prepare_skill("hand","dashou-yin");

        create_family("������", 11, "����");
        set("class", "huanxi");

        setup();
        carry_object(__DIR__"obj/changsheng-jiasha")->wear();
	if (clonep()){
		weapon = unew(BINGQI_D("jgxmc"));
		if(!weapon)weapon=new(BINGQI_D("jingang-zuan"));
		weapon->move(this_object());
		weapon->wield();
		add_money("gold",1);
	}
}

string ask_master()
{
	mapping fam;
	object ob=this_player();

	if (!(fam = ob->query("family")) || fam["family_name"] != "������")
		return "�����˵������ʦ�������µ�һ���֣���������˭����֪���ĸ�������\n";
	if (ob->query("family/generation") > 11 )
		return RANK_D->query_respect(ob)+"��ѩɽ�ϴ��û��٣����������Լ���ʦ�������̰ɡ�\n";
	if (ob->query_temp("win_deb"))
		return RANK_D->query_respect(ob)+"���Ѿ������㣬Ը��������ʦ�֡�\n";
	if ((int)ob->query_skill("longxiang-boruo", 1) < 140)
		return "ʦ����˵�������ޱ����޷���������������ڹ������ڹ���Ϊ���������ţ�����ʲô��\n";
	if ((int)ob->query_skill("huanxi-chan", 1) < 120) {
		command("say ѩɽ�����»�ϲ����������˫��");
		return " �ڻ�ϲ�����棬" + RANK_D->query_respect(ob) + "���еĻ������ɣ�\n";
	}
	ob->set_temp("p_fight",1);
	return "Ҫ����Ҷ�ʦ���͵���Ӯ�������������ս�ħ�ơ�\n";
}

int accept_fight(object ob)
{
	object me  = this_object();
	object weapon;
	if (!ob->query_temp("p_fight") ) return 0;
	if (!weapon=present("jingangchu",me))
		return notify_fail("�����˵����û�˽�ս�ħ�ƣ���ô������䣿\n");
	message_vision("\n����͵��ͷ��˵�����ҵ����ϴ����Ʒ�����֮����������ɱ�Թ��\n",this_player());
	me->reincarnate();
	me->set("neili",me->query("max_neili"));
	me->set("chat_chance_combat", 40);
	me->set("chat_msg_combat", ({
		(: exert_function, "shield daer ba" :),
	}) );
	remove_call_out("checking");
	call_out("checking", 1, me, ob);
	ob->delete_temp("p_fight");
	return 1;
}

int checking(object me, object ob)
{
	if (me->is_fighting()) {
		call_out("checking",1, me, ob);
		return 1;
	}
	if ( !present(ob, environment()) ) return 1;

	if( me->query_temp("last_lost_to") == ob
	 && me->query_temp("last_damage_from") == ob) {
		command( "say �ù���"+ RANK_D->query_respect(ob) +
			"����ȥ��ʦ��������ʦ���ˡ�\n");
		ob->set_temp("win_deb",1);
		}
	return 1;
}
