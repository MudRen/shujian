// dashou.c ����
// Lklv 2001.9.27 update

inherit NPC;

void create()
{
        set_name("����", ({"da shou", "dashou", "shou" }) );
        set("gender", "����" );
        set("age", 20+random(10));
        set("long", "���Ǹ��������˺���ר������Ĵ��֡�\n");

        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set("combat_exp", 8000);
	set("shen", -300);
	set("shen_type", -1);
        set("str", 30);
        set("dex", 20);
        set("con", 15);
        set("int", 15);
        set("attitude","heroism");

	set("chat_chance", 5);
	set("chat_msg", ({
		"������Ǯׯ�ϰ���˸�����Ҫ��ҪС�Ľ�ѵ��һ�һ�٣�\n",
 		"���ְ���˫�ֵ���ָ��������~��~��������\n",
        }) );
	setup();

        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

