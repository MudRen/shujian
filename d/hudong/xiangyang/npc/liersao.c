// liersao.c ���ɩ
// Lklv 2001.9.24

inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("���ɩ", ({"li ersao", "li", "ersao" }) );
        set("gender", "Ů��" );
        set("age", 34);
        set("long", "��������ʼ�մ���һ˿Ц�ݡ�\n");
        set("attitude","heroism");
        set("combat_exp", 110000 + random(50000) );
        set("shen_type", 0);
        set("per", 21 + random(5));
        set("str", 19);
        set("dex", 24);
        set("con", 25);
        set("int", 12);
        set("wimpy", 60);

	set_skill("unarmed", 60);
        set_skill("dodge", 65);
        set_skill("parry", 60);

        set("vendor_goods", ({
                (["name":"/d/gb/obj/fish1","number": 5]),
                (["name":"/d/gb/obj/fish3","number": 5]),
                (["name":"/d/gb/obj/fish4","number": 5]),
                (["name":"/d/gb/obj/fish5","number": 5]),
                (["name":"/d/gb/obj/fish6","number": 5]),
                (["name":"/d/gb/obj/fish7","number": 5]),
        }));

        set("chat_chance", 2);
        set("chat_msg", ({
                "���ɩգ��գ�۾����ƺ���˵ʲô��\n",
                "���ɩ���˷�ͷ�ϵ�˿��ת��������ͷ����\n",
        }) );
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        add_money("silver", 5+random(2));
}
void init()
{
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}
