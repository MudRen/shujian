// npc: /d/xingxiu/herdsman.c
// Jay 3/18/96

inherit NPC;

void create()
{
        set_name("������", ({ "muyang ren", "ren"}));
        set("gender", "����");
        set("age", 25 + random(10));

        set("long", "һ��ά����������ˡ�\n");

        set("attitude", "friendly");

        set("combat_exp", 1500);   
        set("env/wimpy", 60);
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("whip", 20);

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set("chat_chance", 5);
        set("chat_msg", ({
           (: random_move :)
         }) );          
        setup();       
        carry_object(BINGQI_D("bian"))->wield();
        carry_object(ARMOR_D("yangao"))->wear();
}