// /d/xiangyang/npc/kzxiaoer.c ��ջС��

inherit WAITER;

inherit F_VENDOR;
void create()
{
        set_name("С��", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "����" );
        set("age", 27);
        set("long", "��λ��С����Ц�����æ�ţ�����ʱ������ڲ����ϵ�Ĩ��������\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("rank_info/respect", "С����");
        set("vendor_goods", ({
                (["name": MISC_D("denglong"), "number":10]),
                (["name": MISC_D("fire"), "number":10]),
        }));
        set("inquiry", ([
                "name" : "���ҵ����ƺ���С���ͺ��ˡ�",
                "rumors" : "�ҿɲ�֪��ʲô���ţ������£���ȥ�������˺��ˡ�",
                "����" : "���������ѽ���͹����ⲻ����¿��¿��",
        ]));
        set("per", 20);

        set("chat_chance", 5);
        set("chat_msg", ({
                "��С������˵�������͹٣������룬�����룡��\n",
                "��С��Ц������˵������ס���ǽ�����ջ������һ�ٸ����İɡ���\n",
        }) );
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
       object ob;

        ::init();
        if (base_name(environment()) != query("startroom")) return;
        if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list", "menu");
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if (!ob || !present(ob, environment())) return;
        switch( random(2) ) {
                case 0:
                        say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������ȱ��裬ЪЪ�Ȱɡ�\n");
                        break;
                case 1:
                        say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
        }
}

int accept_object(object who, object ob)
{

        if (ob->query("money_id") && ob->value() >= 500){
                tell_object(who, "С��һ������˵������л���ϣ��͹�����¥ЪϢ��\n");
                who->set_temp("rent_paid","������ջ");
                return 1;
        }
        return 0;
}

void relay_emote(object me,string arg)
{
        command(arg+" xiao er");
}
