//shanzei.c by zly

inherit NPC;

void create()
{
        set_name("����", ({ "ma zei","zei" }) );
        set("gender", "����" );
        set("age", 22+random(10));
        set("long", "���Ǹ���Ŀ������ɽ�����������ɷ�ؿ����㡣\n");
        set("shen_type", -1);

        set("str", 30);
        set("int", 10);
        set("con", 10);
        set("dex", 30);

        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 600);
        set("max_neili", 600);
        set("combat_exp", 20000+random(10000));

        setup();
        add_money("silver", 25+random(20));
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()))
        {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
        }
}

