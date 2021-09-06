// tiejiang.c ����

inherit NPC;
inherit F_VENDOR;
 
void create()
{
        set_name("����", ({ "tie jiang", "tie", "jiang" }) );
        set("gender", "����" );
        set("age", 34);
        set("long",
                "����һλ�������Ŵ����������������ش�����������\n");
        set("combat_exp", 300);
        set("attitude", "peaceful");
        set("rank_info/respect", "����");
        set("vendor_goods", ({
           (["name":__DIR__"obj/changjian","number":25]),
           (["name":__DIR__"obj/gangjian","number":15]),
           (["name":__DIR__"obj/tiejia","number":22]),
           (["name":"/d/tiezhang/obj/gangzhang","number":10]),
           (["name":__DIR__"obj/gangdao","number":10]),
           (["name":__DIR__"obj/caidao","number":20]),
           (["name":__DIR__"obj/tiechui","number":10]),
           (["name":__DIR__"obj/bishou","number":12])
        }));
        set("inquiry", ([
                "name" : "������������С��ס�����������ɶ��\n",
                "rumors" : "�ҵ�����͢��ȥ���˺ӣ������˼����ӹǲ��ã�ǰЩ�첻����ȥ�ˡ�\n",
                "here" : "�����ǳ���Ψһ�Ĵ������ˣ�ʲô�˶�����������������\n",
        ]) );
        setup();
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
        if( !ob || wizardp(ob) || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "����Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "������ֻҪ�����ļһӦ�о��С�\n");
                        break;
                case 1:
                        say( "����Ц�Ǻǵ�˵����λ" + RANK_D->query_respect(ob)
                                + "������Ҫ��ʲô��\n");
                        break;
        }
}


