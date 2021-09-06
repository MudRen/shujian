// xiaofan.c С����

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("С����", ({ "xiao fan", "xiao", "fan" }) );
        set("gender", "����" );
        set("age", 34);
        set("long",
                "��λС������Ц���������æ��������ʱ�к������Ŀ��˽�����\n");
        set("combat_exp", 300);
        set("attitude", "peaceful");
        set("rank_info/respect", "С����");
        set("vendor_goods", ({
        (["name":__DIR__"obj/bottle","number":15]),
        (["name":__DIR__"obj/zhujian","number":18]),
        (["name":__DIR__"obj/fire","number":15]),
         (["name":MISC_D("xionghuang"),"number": 100]),
          (["name":__DIR__"obj/zhubang","number":10]),
         (["name":__DIR__"obj/zhubang","number":10])
        }));
        setup();
        add_money("coin", 90);
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
                        say( "С����Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����ߵ���ô��æ��������һ��������Ҫ�Ķ�����\n");
                        break;
                case 1:
                        say( "С����Ц�Ǻǵ�˵����λ" + RANK_D->query_respect(ob)
                                + "������Ҫ��ʲô��\n");
                        break;
        }
}

