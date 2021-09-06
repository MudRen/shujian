// xiaoer.c 
// Looklove Y2k 4/26

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("��С��", ({ "xiao er","xiao","waiter" }) );
        set("gender", "����" );
        set("age", 19);
        set("long",
                "��λ������Ц�����æ�ţ�����ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
        set("rank_info/respect", "���");
        set("vendor_goods", ({
                FOOD_D("tea"),
                FOOD_D("jiudai"),
                FOOD_D("baozi"),
                FOOD_D("miantang"),
                FOOD_D("mantou"),
                FOOD_D("jitui"),
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
                && ob->query_skill("begging",1) > 10 )
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
        call_out("kicking", 1, ob);
        
}

void kicking(object ob)
{
        if (!ob || environment(ob) != environment()) return;

        ob->move("/d/xiangyang/liuzz");
        message("vision","ֻ����ƹ����һ����" +  ob->query("name") +
                "���˴Ӿƹ���һ�����˳������Ǳ���״���ӿ��ˡ�\n", environment(ob), ob);
}

