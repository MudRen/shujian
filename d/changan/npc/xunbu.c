// Write By Yanyang@SJ 2001.10.2
// NPC : /d/changan/npc/xunbu.c

inherit NPC;

void create()
{
        set_name("Ѳ��", ({ "xun bu", "xunbu" }));
        set("age", 22);
        set("gender", "����");
        set("long", "��վ�������ȷ��˵���������硣\n");
        set("attitude", "peaceful");

        set("str", 24);
        set("dex", 16);
        set("combat_exp", 10000);
        set("shen_type", 1);

        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("blade", 40);
        set_skill("force", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);

        set("chat_chance", 2);
        set("chat_msg", ({
                "Ѳ���������µش�����һ�������ó��ٸ�ͨ�����˶ԣ������ֹ���ʲô��\n",
                "Ѳ������ȵ���վס����ʲô�ģ���������̧������\n",
		(: random_move :),
        }));
        setup();
        carry_object(BINGQI_D("blade"))->wield();
        carry_object(ARMOR_D("ruanxue2"))->wear();
        carry_object(ARMOR_D("armor"))->wear();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && living(this_object()) &&
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}
