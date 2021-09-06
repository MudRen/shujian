// zhurour.c ������
// Lklv 2001.9.24

inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("������", ({"zhurou rong", "rong", "a rong" }) );
        set("gender", "����" );
        set("age", 24+random(10));
        set("long", "�������а��٣���Ϊ�����⣬�������Ƕ����������١�\n");
        set("attitude","heroism");
        set("combat_exp", 125000 );
        set("shen_type", 0);
        set("str", 25);
        set("dex", 20);
        set("con", 15);
        set("int", 15);
        set("env/wimpy", 60);

        set_temp("apply/attack", 40);
	set_skill("cuff", 70+random(10));
	set_skill("taizu-quan", 70);
        set_skill("dodge", 70+random(15));
        set_skill("parry", 70);
	map_skill("cuff", "taizu-quan");
	map_skill("parry", "taizu-quan");
        prepare_skill("cuff", "taizu-quan");

        set("vendor_goods", ({
                (["name":"/d/thd/obj/meat","number": 10]),
        }));

        set("chat_chance", 2);
        set("chat_msg", ({
                "����������һ���������Ĩ�������˲�����\n",
                "���������������죬��֪����˵Щʲô��\n",
        }) );
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        add_money("silver", 10+random(5));
}
void init()
{
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
