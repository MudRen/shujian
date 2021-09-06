inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("���Ů��", ({ "miaojia nuzi","girl" }) );
        set("gender", "Ů��" );
        set("age", 16);
        set("long",
                "��λһ������С��������С���������ϵ���\n");
        set("combat_exp", 300);
        set("attitude", "peaceful");
        set("rank_info/respect", "С����");
        set("vendor_goods", ({
            (["name": FOOD_D("mangguo"),"number" : 20]),
            (["name": FOOD_D("lizhi"),"number" : 20]),
            (["name": FOOD_D("longyan"),"number" : 20]),
            (["name": FOOD_D("yangtao"),"number" : 20]),
            (["name": FOOD_D("xiangjiao"),"number" : 20]),
        }));
        setup();
        add_money("coin", 90);
	carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "���Ů��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����ߵ���ô��æ���������кö�ˮ������һ������ϲ���Եġ�\n");
                        break;
                case 1:
                        say( "���Ů��Ц�Ǻǵ�˵����λ" + RANK_D->query_respect(ob)
                                + "����������ʲôˮ����\n");
                        break;
        }
}
