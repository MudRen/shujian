// Write By Yanyang@SJ 2001.9.29
// NPC : /d/changan/npc/miaozhu.c

inherit NPC;

void create()
{
        set_name("��ף", ({ "miao zhu", "zhu", "keeper" }) );
        set("gender", "����" );
        set("age", 67);
        set("long","������˿�������ʮ�����ˣ��꼶�Ǵ��ˣ�������ȴ�ܺá�\n");
        set("combat_exp", 21000);
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
                        say( "��ף˵������λ" + RANK_D->query_respect(ob)
                                + "��������Ǯ�������£���Щ��Ե�ɡ�\n");
                        break;
                case 1:
                        say( "��ף˵������λ" + RANK_D->query_respect(ob)
                                + "��������Ǯ�ɡ�\n");
                        break;
        }
}
