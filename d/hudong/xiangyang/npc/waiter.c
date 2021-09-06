// waiter.c С��

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����", ({ "paotang", "waiter" }) );
        set("gender", "����" );
        set("age", 22);
        set("long",
                "��λ������Ц�����æ�ţ�����ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "���");
        set("vendor_goods", ({
                (["name":FOOD_D("miantang"),"number":20]),
                (["name":FOOD_D("mantou"),"number":20]),
                (["name":FOOD_D("yuebing"),"number":20]),
                (["name":FOOD_D("banana"),"number":15]),
                (["name":FOOD_D("tea"),"number":20]),
        }));
        setup();
}

void init()
{       
        object ob; 
        mapping myfam; 

        ob = this_player();

        ::init();
        if (base_name(environment()) != query("startroom")) return;
        if( interactive(ob) && visible(ob) && !is_fighting() ) {
                if ( (myfam = ob->query("family")) 
                && myfam["family_name"] == "ؤ��" 
                && ob->query_skill("begging",1) < 40 )
                {
                        remove_call_out("saying");
                        call_out("saying", 0, ob);
                } 
                else
                { 
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
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

void saying(object ob)
{
        if (!ob || environment(ob) != environment() || is_fighting(ob)) return;

        say("\n���ô��һ���������Ҫ���Ľ�����ʲô�� ���ҹ���ȥ��\n\n");
        remove_call_out("kicking");
        call_out("kicking", 2, ob);
        
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        ob->move("/d/xiangyang/bhnj");
        message("vision","ֻ����ƹ����һ����" +  ob->query("name") +
                "���˴�С�Ե���һ�����˳������Ǳ���״���ӿ��ˡ�\n", environment(ob), ob);
}

