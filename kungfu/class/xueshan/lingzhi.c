// lingzhi.c ��������
// by iceland

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int ask_me_1();
int ask_me_2();

void create()
{
        set_name("��������", ({ "lingzhi shangren", "lingzhishangren" ,"lingzhi","shangren" }));
        set("long",@LONG
�����ðװ׾�����������֣������еķ�������������Ĳ㡣��ü��Ŀ������
Ц���е�ģ��������һ�־�¶�����Ż�����
LONG
        );
        set("title", HIY "�����µ�ʮ��������" NOR);
        set("gender", "����");
        set("age", 41);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 28);
        set("int", 20);
        set("con", 25);
        set("dex", 27);
        set("max_qi", 1800);
        set("eff_jing", 900);
	set("max_jing",900);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 100);
        set("combat_exp", 600000);
        set("score", 25000);
	set("unique", 1);

        set_skill("huanxi-chan", 120);
        set_skill("literate", 100);
        set_skill("force", 120);
        set_skill("longxiang-boruo", 120);
        set_skill("dodge", 120);
        set_skill("yuxue-dunxing", 120);
        set_skill("hand", 120);
	set_skill("poison",120);
        set_skill("dashou-yin", 120);
        set_skill("parry", 120 );
        set_skill("staff",200);
        set_skill("wushang-dali",200);

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "dashou-yin");
        map_skill("staff", "wushang-dali");

        prepare_skill("hand","dashou-yin");

        create_family("������", 12, "����");
        set("class", "huanxi");
        set("inquiry", ([
                "ٺ»" : (: ask_me_1 :),
                "����" : "���գ����գ�������͵��ڳ�������ɡ�\n",
        ]));

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: exert_function, "shield lingzhi shangren" :),
                (: perform_action, "hand.tianyin" :), }));

        setup();
        carry_object("/d/xueshan/npc/obj/qinxiu-jiasha")->wear();

        add_money("silver",50);
}

void attempt_apprentice(object ob)
{
       	if( (string)ob->query("gender") == "Ů��" ) {
               command("shake");
               command("say �ҷ𷨻�������տ������һ���ѳֲ�ס...�㻹��ȥ�ұ��˰ɡ�");
               return;
	}
        if ((string)ob->query("family/family_name") != "������") {
                command("say"+ RANK_D->query_respect(ob) +
                        "���Ǳ��µ��ӣ������ﵷʲô�ң���");
                return;
	}
        if ((int)ob->query_skill("huanxi-chan", 1) < 80) {
                command("say ��ϲ���Ǹ����书֮���������ڼ������ɡ�");
                command("say"+ RANK_D->query_respect(ob) +
                        "�ٰ�����ͨ��������������б��ŵ��ķ��ɡ�");
                return;
        }

        command("say �ðɣ��Ժ�������ҵĵ����ˡ�");
        command("recruit " + ob->query("id"));
        ob->set("title", HIY "�����µ�ʮ��������" NOR);
}

int ask_me_1()
{
	object me;
	int skill,i,j;
	mapping myfam;
	me=this_player();

        skill = me->query_skill("longxiang-boruo",1);
	myfam = (mapping)me->query("family");
        i = (int)me->query("join_age");
        j = (int)me->query("gf_ok");

	if (!myfam || myfam["family_name"] != "������") {
		command("sneer "+(string)me->query("id"));
		command("say ��"+ RANK_D->query_respect(me) +"��ü���ۣ������ú�ѽ����֪���������ʲô��\n");
		return 1;
	}
	if((int)me->query("xs_given")>=(int)me->query("age")) {
		command("sigh "+(string)me->query("id"));
		command("say ������ٺ»�����Ѿ�������ô�����������ɡ�\n");
		return 1;
	}
        if( (( i + j ) < (int)me->query("age")) && ( skill < 216 ) ) {
		if((int)me->query("xs_given")>=(int)me->query("age")) {
			command("shake "+(string)me->query("id"));
			command("say "+ RANK_D->query_respect(me) +"���깩��������ȱ�����겻����ȡٺ»�����������ɡ�\n");
			return 1;
		}
		command("shake "+(string)me->query("id"));
		command("say "+ RANK_D->query_respect(me) +"���깩��������ȱ�����겻����ȡٺ»�����������ɡ�\n");
    		me->add("gf_ok",1);
        	me->set("xs_given",(int)me->query("age"));
		return 1;
	 }

	if((int)me->query("xs_given")<(int)me->query("age")) {
		if (skill < 60){
			command("pat "+(string)me->query("id"));
			command("say �����δС�ɣ������ڼ�����Ϊ�ǡ�\n");
			return 1;
		}
		if (skill >= 60 && skill < 90) {
			me->set_temp("give_gold", 30);
			remove_call_out("give_money");
			call_out("give_money", 1, me);
			return 1;
		}
		if (skill >= 90 && skill < 140)	{
			me->set_temp("give_gold", 60);
			remove_call_out("give_money");
			call_out("give_money", 1, me);
			return 1;
		}
		if (skill >= 140 && skill < 180) {
			me->set_temp("give_gold", 100);
			remove_call_out("give_money");
			call_out("give_money", 1, me);
			return 1;
		}
		if (skill >= 180){
			me->set_temp("give_gold", 150);
			remove_call_out("give_money");
			call_out("give_money", 1, me);
			return 1;
		}
	}
}

int give_money(object me)
{
	int amount;
	object n_money;
        command("buddhi lingzhi shangren");
        command("say"+ RANK_D->query_respect(me) +"���ú�ٺ»������ȥ���з𷨣�������Ϊ��ʳЩ����������ˡ�");
        message_vision("���������ó������ƽ𣬵ݸ���$N��\n",me);
        n_money = new(GOLD_OB);
        n_money->move(me);
        amount = me->query_temp("give_gold");
        n_money->add_amount(amount);
        me->delete_temp("give_gold");
        me->set("xs_given",(int)me->query("age"));
}
