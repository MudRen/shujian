// woman.c

inherit NPC;

void create()
{
        set_name("��Ů", ({"woman", "funv" ,"nv","fu"}) );
        set("gender", "Ů��" );
        set("age", 35);
        set("long", "һ�����긾Ů��������ݣ��������ܵ������ѹ�ȣ��ޱ��Ѽ����ư׷���\n");

        set_skill("unarmed", 15);
        set_skill("dodge", 15);
        set_skill("parry", 15);
        set("combat_exp", 300);
	set("shen_type", 0);
        set("str", 15);
        set("dex", 10);
        set("con", 15);
        set("int", 15);
        set("attitude","friendly");
	set("unique", 1);

        setup();
        set("chat_chance", 1);
        set("chat_msg", ({
		"��Ůҡ��ҡ���ﱧ�ŵĺ��ӣ�̾�˿�����\n",
                "��Ů�ҿ��½󣬰���ͷ�������ӵ�������ӽ���ֹͣ���֣���˱��������\n",
		"��Ů����ĺ�����ȭ���ȣ����������Ŀ���������\n",
        }) );
        carry_object(ARMOR_D("pipao"))->wear();
}
