inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("�ӻ����ϰ�", ({ "lao ban", "laoban" }));
        set("shen_type", 1);

        set("gender", "����");
        set("age", 45);
        set("long",
                "�ϰ���������������ԭ�ˣ����˼�ʮ���С��������Ϊ�ӱܹٱ�׷ɱ���ܵ��Ͻ����ˡ�\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);

        set("combat_exp", 40000);
        set("attitude", "friendly");
        set("vendor_goods", ({
            (["name": FOOD_D("bottle"),"number" : 20]),
            (["name": BINGQI_D("zhujian"),"number" : 15]),
            (["name": MISC_D("fire"),"number" : 5]),
            (["name": BINGQI_D("zhubang"),"number" : 10]),
            (["name": ARMOR_D("beixin"),"number" : 10]),
        }));
        
        setup();
        add_money("silver",1);
        carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
