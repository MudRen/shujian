// NPC: /d/huashan/npc/ai.c
// Date: Look 99/03/25
// Lklv modify 2001.10.18

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int ask_quest();
void create()
{
        set_name("������",({"ai laozhe","ai"}));
        set("title","��ɽ�ɵ�ʮ��������");
        set("long", "������ڽ��������ӵĻ�ɽ�ɰ����ߡ�");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 32);
        set("int", 32);
        set("con", 32);
        set("dex", 32);

        set("max_qi",3500);
        set("qi", 3500);
        set("max_jing", 2500);
        set("jing",2500);
        set("eff_jingli", 3000);
        set("max_neili", 4000);
        set("neili", 4000);
        set("jiali", 50);
        set("combat_exp", 2000000);
        set("score", 30000);

        set_skill("dodge",  180);
        set_skill("force",  180);
        set_skill("parry",  180);
        set_skill("cuff", 180);
	set_skill("sword", 190);
	set_skill("literate",100);
        set_skill("poyu-quan", 180);
	set_skill("zixia-gong", 180);
        set_skill("huashan-jianfa",  180);
        set_skill("huashan-shenfa",  180);
        set_skill("zhengqi-jue", 180);

	map_skill("dodge", "huashan-shenfa");
	map_skill("sword", "huashan-jianfa");
        map_skill("force","zixia-gong");
        map_skill("parry","poyu-quan");
        map_skill("cuff", "poyu-quan");

        prepare_skill("cuff","poyu-quan");
	set("chat_chance_combat",30);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yangwu" :),
		(: perform_action, "sword.feijian" :),
		(: perform_action, "sword.junzi" :),
		(: perform_action, "sword.kuaijian" :),
		(: perform_action, "sword.lianhuan" :),
		(: perform_action, "sword.sanqing" :),
	}));
        create_family("��ɽ��",12,"����");

        set("inquiry", ([
                "����ͨ": (: ask_quest :),
        ]));
        setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(BINGQI_D("sword"))->wield();
}

void attempt_apprentice(object ob)
{
        mapping fam;
        if ( mapp(fam=ob->query("family"))
         && (string)fam["family_name"] != "��ɽ��"
         && (int)ob->query("is/huashan")==1 ) {
                message_vision(CYN "$N���������ɽ�ɵ���ͽ��������ʲô ������\n"NOR, ob );
                command("slap "+ob->query("id"));
                return;
        }
	if ( ob->query("fengset")) {
		command("say �㲻���Ѿ����˷�����Ϊʦ��ô��");
		return;
	}
        if ((int)ob->query("shen") <= 0) {
	        command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
        	command("say �ڵ��з��棬" + RANK_D->query_respect(ob) + "�Ƿ����ò�����");
		return;
        }
        if ((int)ob->query("max_pot") < 200) {
		command("say " + RANK_D->query_respect(ob)+"���ڲ���Ҫ����ָ������ȥ��������ʦ��ѧ��ȥ�ɡ�");
		return;
        }
        if( (int)ob->query_skill("zixia-gong", 1) < 100 ) {
		command("say �����ϼ�񹦻�δ�����,�����ҿɲ�������Ϊͽ��\n");
		return;
        }

        if( (int)ob->query_skill("force") < 100 ) {
		command("say ����ڹ���δ�����,�����ҿɲ�������Ϊͽ��\n");
		return;
        }
        command("say �ðɣ��Ҿ���������,���ҪΪ���ǻ�ɽ����������");
        command("recruit " + ob->query("id"));
}

int ask_quest()
{
        object me = this_player();
	if (!me->query_temp("hu/quest1")) {
		command("say ���ǻ�ɽǰ�ε�����....���������ʲô��");
		command("consider " + me->query("id"));
		return 1;
        }
        else {
		command("say ���ǻ�ɽǰ�ε����ţ��Լ�����ʦ��ȴ�޻����̡�");
		command("say ������һս�����Ѿ������̽������޼�ɱ�ˡ�");
		command("sneer");
		me->set_temp("hu/quest1",2);
		return 1;
        }
}
