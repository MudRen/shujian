// wujiang.c �佫

inherit NPC;

void create()
{
        set_name("�佫", ({ "wu jiang", "wu", "jiang" }));
        set("gender", "����");
        set("age", random(10) + 30);
        set("str", 25);
        set("dex", 16);
        set("long", "��վ�������ȷ��˵���������硣\n");
        set("combat_exp", 75000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set_skill("unarmed", 60);
        set_skill("force", 60);
        set_skill("sword", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 30);

        set("neili", 400);
        set("max_neili", 400);
        set("jiali", 10);

        setup();
	carry_object(BINGQI_D("gangjian"))->wield();
	carry_object(ARMOR_D("armor"))->wear();
	carry_object(ARMOR_D("guanxue"))->wear();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && living(this_object()) &&
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
            call_out("kill_ob", 0, ob);
        }
}

 int accept_fight(object me)
{
        command("say ��ү����������ɱ�ţ��������㵹ù��\n");
        if (me->query_condition("killer") < 100) me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

int accept_kill(object me)
{
        command("say үү������ɱ���ţ��������㵹ù��\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

