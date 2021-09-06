// wanlaoban.c by XiaoYao

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("���ϰ�", ({ "wan laoban", "laoban" }) );
        set("gender", "����" );
        set("age", 22);
        set("long",
                "��λ���ϰ�Ϊ�տ��Ų��õ�Ӣ��¥æµ�š�\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "С�ϰ�");
        set("vendor_goods", ({
            (["name": FOOD_D("miantiao"),"number" : 20]),
            (["name": FOOD_D("caiyao"),"number" : 20]),
            (["name": FOOD_D("jianjiao"),"number" : 20]),
            (["name": FOOD_D("chazhong"),"number" : 20]),
            (["name": FOOD_D("jiudai"),"number" : 20]),
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() || is_fighting(ob)) return;
        switch( random(2) ) {
                case 0:
                        say( "���ϰ�Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��裬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "���ϰ��ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
        }
}
