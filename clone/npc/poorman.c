// /clone/npc/poorman.c

inherit NPC;

void create()
{
        set_name("�", ({ "qiong han", "poor man", "man" }) );
        set("gender", "����" );
        set("age", 33);
        set("long", "һ���������������ɫ�����\n");
        set("attitude", "friendly");
        set("combat_exp", 15250);
        set("shen_type", 1);
        set("str", 15);
        set("dex", 18);
        set("con", 17);
        set("int", 43);
        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
		"�������ش��˸���Ƿ��\n",
		"�����׽ס�����ϵ�ʭ�ӣ��������������û�����⣬ȫ�����Ǹ�ҧ�ˡ� \n",
                (: random_move :)
        }) );
        carry_object(ARMOR_D("armor/cloth"))->wear();
}
