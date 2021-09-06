// duke.c �Ŀ�
// Lklv 2001.9.24

inherit NPC;

void create()
{
        set_name("�Ŀ�", ({"du ke", "duke", "ke" }) );
        set("gender", "����" );
        set("age", 35+random(10));
        set("long", "���Ǹ����ֺ��еĶĿ͡�\n");
        set("attitude","heroism");
        set("combat_exp", 15000+random(5000));
        set("shen_type", 0);
        set("str", 25);
        set("dex", 20);
        set("con", 15);
        set("int", 15);
        set("wimpy", 80);

        set_temp("apply/attack", 20+random(20));
	set_skill("cuff", 40+random(10));
	set_skill("taizu-quan", 40);
        set_skill("dodge", 50+random(15));
        set_skill("parry", 40);
	map_skill("cuff", "taizu-quan");
	map_skill("parry", "taizu-quan");
        prepare_skill("cuff", "taizu-quan");

/*
        set("chat_chance", 2);
        set("chat_msg", ({
                "�Ŀ������Ϳڴ�����������ͭ����˵ࡣ\n",
                "�Ŀ��������С����б�������ʵ��������ϴ�����û�У����������֣���\n",
                "�Ŀͷ��ݵ�������ΰ�һ��Ҫ�������� ���Ǹ��ǰ���ǰ�������������ţ���\n",
                "�Ŀͺ޺޵��ֹ��������ϴ����Ӳ�С�ģ���Ȼ�ᱻ������Ӯȥʮ�����ӡ���\n",
        }) );
*/
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        add_money("silver", 5+random(5));
}
