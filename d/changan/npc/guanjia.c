// Write By Yanyang@SJ 2001.10.1
// NPC : /d/changan/npc/guanjia.c

inherit NPC;

void create()
{
        set_name("�ܼ�", ({ "guan jia", "guanjia" }) );
        set("gender", "����" );
        set("age", 56);
        set("long","����ͷ�׷�������Ϊ������������˲����ġ�\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
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
}

void greeting(object ob)
{
        if (!ob || !present(ob, environment())) return;
        switch( random(2) ) {
                case 0:
                        say( "�ܼ�ӭ����˵������λ" + RANK_D->query_respect(ob)
                                + "���������ڼң���������Щʱ�������ɡ�\n");
                        break;
                case 1:
                        say( "�ܼ�ӭ����˵������λ" + RANK_D->query_respect(ob)
                                + "���������ڼң�����������һ�ȣ������ȥ�ϲ衣\n");
                        break;
        }
}