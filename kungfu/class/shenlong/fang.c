//Cracked by Roath
// fangyi.c  ����

inherit NPC;
// inherit F_MASTER;

int do_work();
string *fjob = ({"����", "����", "����", "����", "ˮ��", "������", "��Ҷ��"});

void create()
{
	set_name("����", ({ "fang yi","fang" }));
//      set("nickname", "");
	set("long",
		"һ�Ź���������ò������\n");
	set("gender", "Ů��");
	set("age", 18);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 23);
	set("int", 25);
	set("con", 25);
	set("dex", 26);
	set("max_qi", 600);
	set("max_jing", 600);
	set("neili", 600);
	set("max_neili", 600);
	set("jingli", 600);
	set("max_jingli", 600);
	set("jiali", 30);
	set("combat_exp", 50000);
//      set("score", 50000);
//      set("shen", -3000);

	set_skill("force", 30);
	set_skill("dulong-dafa", 20);
	set_skill("dodge", 40);
	set_skill("lingshe-shenfa", 60);
	set_skill("strike", 30);
	set_skill("kick", 30);
	set_skill("parry", 40);
	set_skill("sword", 50);
	set_skill("jueming-tui", 40);
	set_skill("literate", 40);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("kick", "jueming-tui");

	prepare_skill("kick", "jueming-tui");

	create_family("������", 3, "�����ŵ���");

        set("inquiry", ([
                "����" : (: do_work :),
                "������" : (: do_work :),
                "jiao" : (: do_work :),
        ]));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/quanzhou/obj/qun")->wear();

}

void init()
{
        add_action("do_comfort", "comfort");
}


int do_work()
{
        object me = this_player();
        string fword, fwant;

        if( !me->query("sg/spy") ) {
                say("��������һ��˵�����ʼ���Ķ������������ҹ���\n");
                return 1;
        }

        if( me->query_temp("sg/��a") ) {
                say("�������ͷ���˵��������û���ˣ�\n");
                return 1;
        }

        if( time() < (int)me->query("sg/��t") + 180 ) {
                command("slap " + me->query("id"));
                say("������ŭ����������ô������ˣ�\n");
                return 1;
        }

        me->set_temp("sg/��a", 1);
        me->set("sg/��t", time());

        fwant = fjob[random(sizeof(fjob))];
        fword = sprintf("����̾�˿�����˵���������֮����׽%s����ҩ��\n", fwant);
        say(fword);
        me->set_temp("sg/����", fwant);
        return 1;
}

int do_comfort(string arg)
{
        object me = this_player();

        if( !arg || !(arg == "fang yi" || arg == "fang") )
                return notify_fail("");

        message_vision("$NЦ�����ذ�ο�ŷ�����\n", me);

        if( !me->query_temp("sg/��a") )  {
                say("������Ц������������ˡ�\n");
                return 1;
        }

        me->delete_temp("sg/��a");

        message_vision("$N�������������ģ�����͸���ȥץ��\n", me);
        command("thank " + me->query("id"));
        me->set_temp("sg/��b", 1);

        return 1;
}

int accept_object(object who, object ob)
{
        int expgain, faccept;

        if( !who->query_temp("sg/��b") )
                return 0;

        if( ob->query("name") != who->query_temp("sg/����")
        ||  (strsrch(base_name(ob), "/d/shenlong/npc/") != 0) )  {
                command("angry " + who->query("id"));
                command("disapp " + who->query("id"));
                return 0;
        }

        who->delete_temp("sg/��b");
        who->delete_temp("sg/����");

        call_out("destroy_it", 1, ob);

        command("jump " + who->query("id"));
        command("secret " + who->query("id"));

        message_vision("������$N�������ĵ�˵�˼��仰��\n", who);
        if( who->query_skill("medicine", 1) < 30 )
                 who->improve_skill("medicine", random(2 * who->query("int")));

        if( (expgain = who->query("combat_exp")) > 50000 )
                 return 1;

        if( !random(6) )
        who->add("sg/exp", 1);
        expgain = (50000 - expgain) / 200;
        who->add("combat_exp", expgain + random(expgain));

        expgain /= 3;
        who->add("potential", expgain + random(expgain));
        if( who->query("potential") > who->query("max_potential") )
        who->set("potential", who->query("max_potential"));

        return 1;              
}

void destroy_it(object ob)
{
        if(ob)
        destruct (ob);
}
