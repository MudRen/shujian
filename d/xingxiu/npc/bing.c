// bing.c �ٱ�
inherit NPC;
void create()
{
        set_name("�����", ({ "huizu bing", "bing" }));
        set("age", 32);
        set("gender", "����");
        set("long", "���Ǹ������ϱ�������פ�����\n");
        set("attitude", "peaceful");
        set("str", 32);
        set("int", 16);
        set("con", 26);
        set("dex", 20);
        set("combat_exp", 20000);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("blade", 40);
        set_skill("force", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 40);        
        setup();
        carry_object(BINGQI_D("blade"))->wield();
        carry_object(ARMOR_D("junfu"))->wear();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && living(this_object()) &&
                (ob->query_condition("killer") || ob->query_temp("xx_rob"))) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 0, ob);
        }
}
int accept_fight(object me)
{
        command("say ��ү���ر߹��۵�Ҫ����û�պ�" + RANK_D->query_respect(me)
                + "�����档\n");
        return 0;
}
