// fang.c
inherit NPC;

int ask_help();

void create()
{
        set_name("����", ({ "fang ping", "fang",}));
        set("long",
                "�����Ǻ��Ͽ����ϴ���������Ӣ�ۣ�һ����ɫ���£��Ե��ɷ���ǡ�ƽʱ������飬�Ӳ����˽�����\n"
        );
        set("gender", "����");
        set("attitude", "friendly");
        set("age", 57);
        set("shen_type", 100000);
        set("str", 42);
        set("int", 42);
        set("con", 42);
        set("dex", 42);
        set("per", 40);
        set("max_qi", 6000);
        set("max_jing", 6000);
        set("neili", 9000);
        set("max_neili", 9000);
        set("jiali", 50);
        set("combat_exp", 3000000);
        set("score", 100);

        set("chat_chance", 30);
        set("chat_msg", ({
                (: random_move :)
        }) );
        set_skill("linji-zhuang", 280);
        set_skill("literate", 180);
        set_skill("parry", 280);
        set_skill("taizu-quan", 280);
        set_skill("dodge", 280);
        set_skill("force", 280);
        set_skill("cuff", 280);
        set_skill("anying-fuxiang", 280);

        set("apply/attack", 50);
        set("apply/dexerity", 50);

        map_skill("force", "linji-zhuang");
        map_skill("parry", "taizu-quan");
        map_skill("cuff", "taizu-quan");
        map_skill("dodge", "anying-fuxiang");
        prepare_skill("cuff", "taizu-quan");
        set("inquiry",([
          "��æ" : (: ask_help :),
          "����" : (: ask_help :),
          "help" : (: ask_help :),
        ]) );
        create_family("������", 3, "����");

        setup();
        carry_object("/clone/armor/cloth")->wear();

}

int ask_help()
{
    object me=this_player();
    object ob = this_object();
    object here = environment(me);
    object bing1, bing2;

    if( ob->query("pl") != me ) return 0;
    if( !me->query_temp("em_job1/killed") ) {
        command("l "+me->query("id"));
        command("say ����ô���������㣿\n");
        command("say �Ǳ���������Ԫ�����������ɱ�ˣ��Ҿ����˰��㡣\n");
        bing1 = new("/d/emei/npc/yuanbing");
        bing1->move(here);
        bing1->setskill(me, bing1);
        bing1->set_leader(me);
        bing1->kill_ob(me);
        me->set_temp("em_job1/bing1", bing1); 
        bing2 = new("/d/emei/npc/yuanbing");
        bing2->move(here);
        bing2->setskill(me, bing2);
        bing2->set_leader(me);
        bing2->kill_ob(me);
        me->set_temp("em_job1/bing2", bing2); 
        me->set_temp("em_job1/killing", 1); 
        me->set_temp("em_job1/bing3", me); 
        me->set_temp("em_job1/bing4", me); 
        me->set_temp("em_job1/bing5", me); 
    }
    else if( me->query_temp("em_job1/killed") < 2 ) {
        command("say �������һ��㻹û�ɵ��ء�\n");
    }
    else {
        me->delete_temp("eme_job1/killed");
        me->delete_temp("eme_job1/killing");
        me->delete_temp("eme_job1/bing1");
        me->delete_temp("eme_job1/bing2");
        me->delete_temp("eme_job1/bing3");
        me->delete_temp("eme_job1/bing4");
        me->delete_temp("eme_job1/bing5");
        command("say �ðɣ����Ȼص����ʦ̫������ң�������ټ������������\n");
        move("/d/emei/houdian");
        ob->apply_condition("em_job1", 3);
        set("job_ok", 1);
    }
    return 1;
}

void delay_dest()
{
     remove_call_out("dest");
     call_out("dest", 60);
}

void dest()
{
       object me = this_object();
       object here;
       here = find_object("/d/emei/houdian");
       here->delete("fighting");
       here = find_object("fang ping");
       tell_room(here, me->query("name")+"���������Ѿ����ˣ�������ڣ�\n");  
       tell_room(here, me->query("name")+"ת���뿪��\n");  
       destruct(me);
}

