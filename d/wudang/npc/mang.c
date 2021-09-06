// NPC : /d/wudang/npc/mang.c ç


inherit NPC;

void create()
{
        set_name("����", ({ "ju mang", "mang" }) );
        set("race", "Ұ��");
        set("long", "һֻ���ƹ��죬�������ľ����ߡ�\n");
        set("attitude", "peaceful");
        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
        set("verbs", ({ "bite" }) );


        set("combat_exp", 80000);
        set("chat_chance", 25);
        set("chat_msg", ({
              (: random_move :),
        }) );

        set_temp("apply/attack", 450);
	 set_temp("apply/defense",500);
        set_temp("apply/damage", 450);
        set_temp("apply/armor", 600);

        setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                random(ob->query_kar() + ob->query_per()) < 30) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }
}

