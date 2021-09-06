// /d/xiangyang/npc/mengmian-dadao.c

inherit NPC;

void create()
{
        set_name("������", ({"mengmian dadao", "mengmian", "dadao", "dao"}));
        set("long", "����һ���������׵Ĵ�������������������ԣ�����͸��һ�������ɱ����\n");

        set("gender", "����");
        set("attitude", "heroism");

        set("age", 65);
        set("shen_type", -1);
        set("shen", -9000);
        set("str", 30);
        set("int", 20);
        set("con", 20);
        set("dex", 22);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiaji", 50);
        set("combat_exp", 500000);

        set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("unarmed", 120);
        set_skill("parry", 120);

        setup();
	add_money("gold", 2);
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
