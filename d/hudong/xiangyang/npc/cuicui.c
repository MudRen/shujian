// cuicui.c ���ϰ�

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("���ϰ�", ({ "cui laoban", "laoban", "cui", "cuicui" }));
        set("shen_type", 0);
        set("gender", "����");
        set_max_encumbrance(100000000);
        set("age", 24);
        set("long",
                "��������ϰ����з����۾��ڶ����㿴����ȥ��\n");
        set("no_get_from", 1);

        set("no_clean_up", 0);
        set_skill("unarmed", 600);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/attack", 30);
        set_temp("apply/damage", 15);

        set("combat_exp", 2000000);
        set("attitude", "friendly");
	set("inquiry", ([
		"name" : "�����մ�������������Ҷ�ϰ�߽����ϴޡ�\n",
		"�޴�" : "�������Ұ������л���˵��㲻˵����ô֪���ء�\n",
		"rumors" : "��˵����ɶ��м������ֽ����ˡ�\n",
		"cs" : "���������󣠣�������壠���������\n",
		"name" : "�����մ�������������Ҷ�ϰ�߽����ϴޡ�\n",
	]));

        setup();
        carry_object(ARMOR_D("changshan"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
    ::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("do_sell", "sell");
        add_action("do_value", "value");
}
