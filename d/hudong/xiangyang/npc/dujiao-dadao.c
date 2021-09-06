// /d/xiangyang/npc/dujiao-dadao.c

inherit NPC;

void create()
{
        set_name("���Ŵ��", ({"dujiao dadao", "dujiao", "dadao", "dao"}));
        set("long", "����һ�����к��ϵĶ��Ŵ����������ٸ��ҡ�\n");

        set("gender", "����");
        set("attitude", "heroism");

        set("age", 65);
        set("shen_type", -1);
        set("shen", -5000);
        set("str", 35);
        set("int", 20);
        set("con", 22);
        set("dex", 23);
        set("max_qi", 900);
        set("max_jing", 700);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiaji", 50);
        set("combat_exp", 300000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);

        setup();
	add_money("gold", 1);
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
