inherit NPC;
void create()
{
        set_name("���帾Ů", ({ "zangzu funv", "woman"}));
        set("gender", "Ů��");
        set("age", 25);
        set("long", "һλ����ÿ͵Ĳ��帾Ů��\n");
        set("attitude", "friendly");
        set("combat_exp", 500);
        set("str", 18);
        set("int", 18);
        set("con", 18);
        set("dex", 17);
        set("max_qi", 140);
        set("max_jing", 140);
        set("neili", 100);
        set("max_neili", 100);
        set_skill("unarmed", 10);
        set_skill("parry", 10);
        set_skill("dodge", 10);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 5);
        set_temp("apply/damage", 5); 
        setup();
        set("chat_chance", 1);
        set("chat_msg", ({
"���帾Ů����ؿ����㣬��: ���Ǵ��������ģ���ǰû�����㡣\n",
        }) );
        carry_object(ARMOR_D("pipao"))->wear();
        carry_object(FOOD_D("youcha"));

}
