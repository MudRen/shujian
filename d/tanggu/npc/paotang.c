
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����", ({ "paotang", "waiter" }) );
        set("gender", "����" );
        set("age", 22);
        set("long",  "��λ������Ц�����æ�ţ�����ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "���");
        set("vendor_goods", ({
		(["name": FOOD_D("jitui"), "number":20]),
		(["name": FOOD_D("jiudai"),"number":20]),
		(["name": FOOD_D("yuebing"),"number":20]),
		(["name": FOOD_D("baozi"), "number":30]),
		(["name": FOOD_D("hdjiudai"),"number":10]),
		(["name": FOOD_D("kaoya"),"number":20])
        }));
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{       
        object ob; 
        ob = this_player();

        ::init();
        if (base_name(environment()) != query("startroom")) return;
        if( interactive(ob) && visible(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() || is_fighting(ob)) return;
        switch( random(2) ) {
                case 0:
                        say( "����Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��裬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "�����ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
        }
}
