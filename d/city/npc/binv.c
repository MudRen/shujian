inherit NPC;

void create()
{
        set_name("�Ů", ({ "bi nv", "binv" }) );
        set("gender", "Ů��" );
        set("age", 18);
        set("long",
                "һ��������а��δ�����µ�СѾ��\n");
        set("combat_exp", 7000);
        set("attitude", "friendly");
        set("per",30);
        set_skill("strike",40);
        set_skill("sword",40);
        set_skill("dodge",40);

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        carry_object(BINGQI_D("changjian"))->wield();
}

