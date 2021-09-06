// Write By Yanyang@SJ 2001.10.2
// NPC: /d/changan/jglaoban.c

inherit NPC;

void create()
{
        set_name("�ƹ��ϰ�", ({"jiuguan laoban", "laoban" }) );
        set("gender", "����" );
        set("title","�����е�");
        set("age", 35);
        set("long", "���Ѿ���ò������ӣ������û�취����������\n");

        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set("combat_exp", 2000);
        set("str", 25);
        set("dex", 20);
        set("con", 15);
        set("int", 15);
        apply_condition("drunk",1000);
        set("attitude","heroism");
        
        setup();

        set("chat_chance", 5);
        set("chat_msg", ({
                "�ƹ��ϰ���˸��ã�һ��ľ�����\n",
                "�ƹ��ϰ�ǿ��������Ѫ˿���۾���������һ�¡�\n",
        }) );
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("coin", 100);
}

void init()
{
	if ( file_name(environment(this_object())) == this_object()->query("startroom")) {
		add_action("do_list","list");
		add_action("do_buy","buy");
	}
}	

int do_list()
{
	write("�ƹ��ϰ����������������˵������������Ҫ���ˡ�����һ�𡭡���ȵ㡭��\n");
	return 1;
}

int do_buy()
{
	write("�ƹ��ϰ����������������˵������������Ҫ���ˡ�����һ�𡭡���ȵ㡭��\n");
	return 1;
}
