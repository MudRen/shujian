// /d/mingjiao/npc/laohu.c �ϻ�
inherit NPC;
void create()
{
        set_name("�ϻ�", ({ "lao hu", "hu" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ���͵Ĵ��ϻ���\n");
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 200000);
        set("str", 80);
        set("con", 80);
        set("no_get",1);
      	set("chat_chance", 6);
      	set("chat_msg", ({
              (: this_object(), "random_move" :),
      	}) );
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 50);
        setup();
}

void die()
{
       object ob;
       message_vision("\n$N�Һ�һ�������ˣ�\n", this_object());
       ob = new(ARMOR_D("hupi"));
       ob->move(environment(this_object()));
       destruct(this_object());
}

