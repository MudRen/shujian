// NPC: /d/huashan/npc/feng_bp.c
// Date: Look 99/03/25
// Modify by Lklv 2001.10.18

inherit NPC;

void create()
{
	set_name("�ⲻƽ",({"feng buping", "feng", "buping" }));
	set("title","��ɽ�ɵ�ʮ�����������ŵ���");
	set("nickname","���콣");
	set("long", "������ڽ�����ĬĬ���ţ���������ʵ�����Ļ�ɽ���ڴ��ˡ�\n");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("no_quest",1);

        set("max_qi",1800);
        set("qi", 1800);
        set("max_jing", 1400);
        set("jing",1400);
        set("eff_jingli", 1700);
        set("jingli", 1700);
        set("max_neili", 3500);
        set("neili", 3500);
        set("jiali", 50);
        set("combat_exp", 1200000);
        set("score", 30000);

        set_skill("sword",  140);
        set_skill("dodge",  140);
        set_skill("force",  140);
        set_skill("parry",  140);
        set_skill("literate",100);
        set_skill("zixia-gong", 120);
        set_skill("huashan-jianfa",  180);
        set_skill("huashan-shenfa",  180);

        map_skill("dodge", "huashan-shenfa");
        map_skill("force","zixia-gong");
        map_skill("sword","huashan-jianfa");
        map_skill("parry","huashan-jianfa");

        prepare_skill("strike","hunyuan-zhang");

        set("chat_chance_combat",40);
        set("chat_msg_combat", ({
		(: perform_action, "strike.wuji" :),
		(: perform_action, "sword.jianmang" :),
        }));
	create_family("��ɽ��",13,"����");

	setup();
	carry_object(BINGQI_D("sword/sword"))->wield();
	carry_object(ARMOR_D("armor/cloth"))->wear();
}

void init()
{
	object me, ob;
	::init();

        ob = this_player();
        me = this_object();

        if (interactive(ob) && !environment(ob)->query("no_fight")){
		command("say �ҽ����ҽ��ڽ���,ֻ����������\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
