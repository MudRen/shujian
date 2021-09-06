
inherit NPC;
inherit F_VENDOR;


void create()
{
        set_name("�ӻ����ϰ�", ({ "lao ban", "laoban" }));
        set("shen_type", 1);

        set("gender", "����");
        set("age", 45);
        set("long",
                "�ϰ������������������ˣ����˼�ʮ���С������\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);

        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ({
                (["name": BOOK_D("quanpu"),"number":15]),
                (["name": BOOK_D("dodge_book"),"number":15]),
                (["name": MISC_D("mabudai"), "number": 5]),
            (["name": MISC_D("xionghuang"), "number": 200]),
		(["name": ARMOR_D("beixin"),"number":12])
        }));
        
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("silver",1);
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

