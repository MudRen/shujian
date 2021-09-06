// /d/xiangyang/npc/duxingxia.c

inherit NPC;

void create()
{
        set_name("������", ({"duxing xia", "duxing", "xia"}));
        set("long", "����һ�����������Ĵ������Բ�������������Ϊ���Ρ�\n");

        set("gender", "����");
        set("attitude", "peaceful");

        set("age", 55);
        set("shen_type", 1);
        set("shen", 8000);
        set("str", 38);
        set("int", 23);
        set("con", 22);
        set("dex", 23);
        set("max_qi", 1100);
        set("max_jing", 900);
        set("neili", 1700);
        set("max_neili", 1700);
        set("jiaji", 80);
        set("combat_exp", 600000);

        set_skill("force", 120);
        set_skill("sword", 120);
        set_skill("dodge", 120);
        set_skill("unarmed", 120);
        set_skill("parry", 120);
        set_skill("cuff", 120);

        setup();
	add_money("silver",50);
        carry_object(BINGQI_D("changjian"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
