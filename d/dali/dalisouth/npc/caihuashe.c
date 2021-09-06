// NPC /d/npc/caihuashe.c
inherit NPC;

void create()
{
        set_name("�˻���", ({ "caihua she", "she" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻ�����ĵĲ˻��ߣ�ͷ������Բ�Ρ�\n");
        set("attitude", "peaceful");
 
        set("str", 15);
        set("cor", 16);

        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
        set("verbs", ({ "bite" }) );
 
        set("combat_exp", 1000+random(500));

        set_temp("apply/attack", 25);
        set_temp("apply/damage", 15);
	set_temp("apply/defence",6);
	set_temp("apply/armor",15);

	setup();
}

void die()
{
	object ob;
	message_vision("$N�鴤���£�$N���ˡ�\n", this_object());
	ob = new(__DIR__"sherou");
	ob->move(environment(this_object()));
	destruct(this_object());
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
